import * as readline from 'readline';

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N: number | null = null;
let expectingSuspects = false; // Flag para saber se estamos esperando a linha dos suspeitos

rl.on('line', (line: string) => {
    if (!expectingSuspects) {
        N = parseInt(line.trim());

        if (N === 0) {
            rl.close();
            return;
        }

        expectingSuspects = true;
    } else {
        // Se estamos esperando suspeitos, esta é a linha deles
        const suspects = line.trim().split(' ').map(Number);

        // if (N === null || suspects.length !== N) {
        //     console.error("Erro");
        //     rl.close();
        //     return;
        // }

        let mostSuspect: number = -Infinity;
        let secondMostSuspect: number = -Infinity;

        for (const suspect of suspects) {
            if (suspect > mostSuspect) {
                secondMostSuspect = mostSuspect;
                mostSuspect = suspect;
            } else if (suspect > secondMostSuspect && suspect < mostSuspect) {
                secondMostSuspect = suspect;
            }
        }

        let iSecondMostSuspect: number = -1;
        for (let i = 0; i < N; i++) {
            if (suspects[i] === secondMostSuspect) {
                iSecondMostSuspect = i + 1;
                break;
            }
        }
        console.log(iSecondMostSuspect);

        expectingSuspects = false;
        N = null;
    }
});

rl.on('close', () => {
    // console.log("Programa encerrado."); // Opcional: mensagem ao fechar
    process.exit(0);
});