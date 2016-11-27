process.stdin.setEncoding('utf8');
var input = "";
var n, m, dp, Ma, Mb;
var path;

process.stdin.on('readable', () => {
    var chunk = process.stdin.read();
    if (null !== chunk) {
        input += chunk;
    }
});

function getLine() {
    return input.splice(0, 1);
};

/**
 * @param qn  n-th query to execute
 * @param r1  Robot1 position, -1 means that there is not any previous movement
 * @param r2  Robot2 position ^^^^ 
 * @param curDistance Distance for the current state
 */
function distance(qn, r1, r2) {
    
    // use this string as a key to store all the partial results
    var index = "[" + qn + "," + r1 + "," + r2 + "]";

    if (!dp.hasOwnProperty(index)) {

        // r2 is -1 when robot 2 has not been moved,
        // in this case the cost to move from r2 to the next Ma must be zero
        var r2p = -1 === r2 ? Ma[qn] : r2;
        var d1, d2;

        // case case, the last query
        if ((n-1) === qn) {
            d1 = Math.abs(r1-Ma[qn]);
            d2 = Math.abs(r2p-Ma[qn]);

            if (d1 < d2) {
                path[qn] = "R1";
                dp[index] = d1 + Math.abs(Mb[qn]-Ma[qn]);
            } else {
                path[qn] = "R2";
                dp[index] = d2 + Math.abs(Mb[qn]-Ma[qn]);
            }
        } else {
            d1 = Math.abs(r1-Ma[qn]) + Math.abs(Mb[qn]-Ma[qn]) + distance(qn+1, Mb[qn], r2);
            d2 = Math.abs(r2p-Ma[qn]) + Math.abs(Mb[qn]-Ma[qn]) + distance(qn+1, r1, Mb[qn]);

            // choose the minimum between move the robot R1 or R2
            if (d1 < d2) {
                path[qn] = "R1";
                dp[index] = d1;
            } else {
                path[qn] = "R2";
                dp[index] = d2;
            }
        }
    }
    
    return dp[index];
};

process.stdin.on('end', () => {
    input = input.split(/\r?\n/);
    var t = getLine();
    console.log("t = ", t);
    while (t --) {
        var tmp = getLine()[0].split(" ").map(n => parseInt(n));
        m = tmp[0];
        n = tmp[1];

        dp = {};
        path = new Array(n);
        Ma = new Array(n);
        Mb = new Array(n);
        for (var i = 0; i < n; i++) {
            var query = getLine()[0].split(" ").map(n => parseInt(n));
            Ma[i] = query[0];
            Mb[i] = query[1];
        }
        
        console.log(distance(0, Ma[0], -1));
    }
});

