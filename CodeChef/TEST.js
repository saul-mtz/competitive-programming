process.stdin.setEncoding('utf8');

process.stdin.on('data', function(input) {
    input.split("\n").forEach(function(n) {
        if (42 == n) {
            process.exit();
        }
        console.log(n);
    });
});
