var readline = require('readline');
var n;

function log2(n) {
    return Math.log(n) / Math.LN2;
}

readline.createInterface(process.stdin, process.stdout).on('line', function (line) {
    if (!n) {
        n = line;
    } else {
        var labels = line.split(' ');
        var i = labels[0] || 1;
        var j = labels[1] || 1;
        var heightI = log2(i);
        var heightJ = log2(j);
        console.log(Math.floor(heightI) + Math.floor(heightJ));
    }
});