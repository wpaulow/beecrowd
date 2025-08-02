#include <stdio.h>
#include <string.h>

int typingTime(int lag, int react, int timeSpent, int lenStr) {
    return 2*lag + react + (timeSpent * lenStr);
}

int compare_int(int a, int b) {
    return (a > b) - (a < b);
}

void winner(int ttM, int ttV) {
    int x = compare_int(ttM, ttV);
    if(x == 1) printf("Vinicius\n");
    else if (x == -1) printf("Matheus\n");
    else printf("Empate\n");
}

int main(void) {
    int lagMat, reactMat, timeSpentMat, lagVini, reactVini, timeSpentVini;
    int lenStr, totalTimeMat, totalTimeVini;
    char stringDuel[100001] = {0}, line[100];

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d %d %d", &lagMat, &reactMat, &timeSpentMat);
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d %d %d", &lagVini, &reactVini, &timeSpentVini);

    fgets(stringDuel, sizeof(stringDuel), stdin);
    lenStr = strlen(stringDuel);
    while(stringDuel[lenStr-1] == '\n' || stringDuel[lenStr-1] == '\r')
        stringDuel[--lenStr] = '\0';

    totalTimeMat = typingTime(lagMat, reactMat, timeSpentMat, lenStr);
    totalTimeVini = typingTime(lagVini, reactVini, timeSpentVini, lenStr);

    winner(totalTimeMat, totalTimeVini);

    return 0;
}