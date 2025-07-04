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
    var fs = require('fs');
    var input = fs.readFileSync('/dev/stdin', 'utf8');
    var lines = input.trim().split('\n');
    // .shift() para pegar o primeiro elemento e removê-lo do array 'lines'.
    var C = parseInt(lines.shift());
    var _loop_1 = function (i) {
        var lineValues = lines[i].trim().split(/\s+/).map(Number);
        var N = lineValues[0];
        var grades = lineValues.slice(1);
        var sum = grades.reduce(function (a, b) { return a + b; }, 0);
        var avg = sum / N;
        var above = grades.filter(function (g) { return g > avg; }).length;
        var pct = (above * 100) / N;
        console.log(pct.toFixed(3) + '%');
    };
    for (var i = 0; i < C; i++) {
        _loop_1(i);
    }
}
run();
