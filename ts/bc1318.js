"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var inputData = fs.readFileSync(0, 'utf-8').trim().split(/\s+/).map(Number);
var index = 0;
var results = [];
while (true) {
    var n = inputData[index++];
    var m = inputData[index++];
    if (n === 0 && m === 0) {
        break;
    }
    var count = new Array(n + 1).fill(0);
    for (var i = 0; i < m; i++) {
        var ticket = inputData[index++];
        count[ticket]++;
    }
    var duplicateCount = 0;
    for (var i = 1; i <= n; i++) {
        if (count[i] >= 2) {
            duplicateCount++;
        }
    }
    results.push(duplicateCount);
}
results.forEach(function (res) { return console.log(res); });
