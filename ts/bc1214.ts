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
  const readline = require('readline');
  const input = [];

  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  rl.question('', (answer) => {
    const input = answer.trim().split(/\s+/).map(Number);
    rl.close();
  });

  let idx = 0;
  const C = input[idx++];
  const results: string[] = [];

  for (let t = 0; t < C; t++) {
    const N = input[idx++];
    const grades = input.slice(idx, idx + N);
    idx += N;
    const sum = grades.reduce((a, b) => a + b, 0);
    const avg = sum / N;
    const above = grades.filter(g => g > avg).length;
    const pct = (above * 100) / N;
    results.push(pct.toFixed(3));
  }

  console.log(results.join('\n'));
}

run();
