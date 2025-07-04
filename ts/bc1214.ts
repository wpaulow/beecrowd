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

function run(): void {
  const fs = require('fs');

  const input = fs.readFileSync('/dev/stdin', 'utf8');
  const lines = input.trim().split('\n');

  const C = parseInt(lines.shift());

  for (let i = 0; i < C; i++) {
    const lineValues = lines[i].trim().split(/\s+/).map(Number);

    const N = lineValues[0];
    const grades = lineValues.slice(1);
    const sum = grades.reduce((a, b) => a + b, 0);
    const avg = sum / N;
    const above = grades.filter(g => g > avg).length;
    const pct = (above * 100) / N;
    console.log(pct.toFixed(3) + '%');
  }
}
run();
