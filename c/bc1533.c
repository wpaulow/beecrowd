#include <stdio.h>
#include <limits.h>

int main() {
    int N;

    while (scanf("%d", &N) == 1 && N != 0) {
        int suspects[N];
        for (int i = 0; i < N; i++)
            scanf("%d", &suspects[i]);

        int most_suspect = INT_MIN;
        int second_most_suspect = most_suspect;
        int i_second_most_suspect = -1;

        for (int i = 0; i < N; i++) {
            if (suspects[i] > most_suspect) {
                second_most_suspect = most_suspect; // O antigo most_suspect se torna o second most_suspect
                most_suspect = suspects[i];  // O valor atual se torna o novo most_suspect
            } else if (suspects[i] > second_most_suspect && suspects[i] < most_suspect) {
                // Se o suspeito atual é mais suspeito que o second_most_suspect, mas menor que o most_suspect
                second_most_suspect = suspects[i];
            }
        }

        for (int i = 0; i < N; i++) {
            if (suspects[i] == second_most_suspect) {
                i_second_most_suspect = i+1;
                break;
            }
        }
        printf("%d\n", i_second_most_suspect);
    }

    return 0;
}