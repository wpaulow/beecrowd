/**
 *   https://judge.beecrowd.com/pt/problems/view/1214
 *   Input
 *       The input contains many test cases. The first line of the input contains
 *       an integer C, indicating the number of test cases. Following are C test cases
 *       or instances. Each test case starts with an integer N, which is the number
 *       of people in a class (1 ≤ N ≤ 1000). After that, N integers are given,
 *       separated by spaces, each representing the final grade (an integer between
 *       0 and 100) of each student in the class.
 *
 *   Output
 *       For each test case, print a line giving the percentage of students who
 *       are above the class average, with the value rounded to 3 decimal places.
 *
 *   Author
 *       GitHub: @wpaulow
 */
function run() {
    var readline = require('readline');
    var input = [];
    var rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question('', function (answer) {
        var input = answer.trim().split(/\s+/).map(Number);
        rl.close();
    });
    var idx = 0;
    var C = input[idx++];
    var results = [];
    var _loop_1 = function (t) {
        var N = input[idx++];
        var grades = input.slice(idx, idx + N);
        idx += N;
        var sum = grades.reduce(function (a, b) { return a + b; }, 0);
        var avg = sum / N;
        var above = grades.filter(function (g) { return g > avg; }).length;
        var pct = (above * 100) / N;
        results.push(pct.toFixed(3));
    };
    for (var t = 0; t < C; t++) {
        _loop_1(t);
    }
    console.log(results.join('\n'));
}
run();
