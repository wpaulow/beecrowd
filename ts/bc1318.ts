import * as fs from 'fs';

const inputData = fs.readFileSync(0, 'utf-8').trim().split(/\s+/).map(Number);
let index = 0;
const results: number[] = [];

while (true) {
    const n = inputData[index++];
    const m = inputData[index++];

    if (n === 0 && m === 0) {
        break;
    }

    const count = new Array(n + 1).fill(0);

    for (let i = 0; i < m; i++) {
        const ticket = inputData[index++];
        count[ticket]++;
    }

    let duplicateCount = 0;
    for (let i = 1; i <= n; i++) {
        if (count[i] >= 2) {
            duplicateCount++;
        }
    }

    results.push(duplicateCount);
}

results.forEach(res => console.log(res));
