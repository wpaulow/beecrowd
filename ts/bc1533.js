"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var readline = require("readline");
var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
var N = null; // Variável para armazenar o valor de N
var expectingSuspects = false; // Flag para saber se estamos esperando a linha dos suspeitos
rl.on('line', function (line) {
    if (!expectingSuspects) {
        N = parseInt(line.trim());
        if (N === 0) {
            rl.close();
            return;
        }
        expectingSuspects = true;
    }
    else {
        // Se estamos esperando suspeitos, esta é a linha deles
        var suspects = line.trim().split(' ').map(Number);
        // if (N === null || suspects.length !== N) {
        //     // Isso indica um erro na entrada ou na lógica, N deveria estar definido e coincidir
        //     console.error("Erro: Número de suspeitos não corresponde a N ou N não foi definido.");
        //     rl.close();
        //     return;
        // }
        var mostSuspect = -Infinity;
        var secondMostSuspect = -Infinity;
        for (var _i = 0, suspects_1 = suspects; _i < suspects_1.length; _i++) {
            var suspect = suspects_1[_i];
            if (suspect > mostSuspect) {
                secondMostSuspect = mostSuspect;
                mostSuspect = suspect;
            }
            else if (suspect > secondMostSuspect && suspect < mostSuspect) {
                secondMostSuspect = suspect;
            }
        }
        var iSecondMostSuspect = -1;
        for (var i = 0; i < N; i++) {
            if (suspects[i] === secondMostSuspect) {
                iSecondMostSuspect = i + 1;
                break;
            }
        }
        console.log(iSecondMostSuspect);
        expectingSuspects = false; // Resetamos para esperar o próximo N
        N = null; // Resetamos N
    }
});
rl.on('close', function () {
    // console.log("Programa encerrado."); // Opcional: mensagem ao fechar
    process.exit(0);
});
