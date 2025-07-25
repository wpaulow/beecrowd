/**
*   https://judge.beecrowd.com/pt/problems/view/1318
*   Input
*       The input contains data from several test cases. Each test case consists of two lines. The first  
*   line contains two integers N and M, which indicate, respectively, the * number of original tickets  
*   and the number of people at the party (1 ≤ N ≤ 10000 and 1 ≤ M ≤ 20000). The second line of the  
*   test case contains M integers Ti representing the ticket numbers in the package given by the  
*   director (1 ≤ Ti ≤ N). The end of input is indicated by N = M = 0.
*
*   Output
*       For each test case, your program should print a line containing the number of tickets in the  
*   package that have another ticket with the same number in the sequence.
* 
*   Personal Note      
*       The final result alone doesn't provide complete information. Knowing how many tickets have at  
*   least one duplicate doesn't guarantee that these duplicated tickets were originals, nor does it  
*   confirm the existence of any original among those without duplicates. Therefore, also knowing the  
*   total count of duplicates among all tickets, including those with multiple duplicates, could help  
*   in defining probabilities for scenarios similar to this problem.  
*
*   Author
*       GitHub: @wpaulow
* 
**/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tickets, people, len = 0;
    int *out = NULL;
    
    while(1) {
        scanf("%d %d", &tickets, &people);
        if (tickets == 0 && people == 0) break;

        // Array to count occurrences of each ticket (indices 0..tickets)
        int *count = (int*) calloc(tickets+1, sizeof(int));

        // Read all tickets from the package
        for (int i = 0; i < people; i++) {
            int num;
            scanf("%d", &num);
            if (num >= 1 && num <= tickets) count[num]++;
        }

        // Count how many numbers have at least 2 occurrences
        int reps = 0;
        for(int i = 1; i <= tickets; i++) count[i] >= 2 ? reps++ : reps;
        if(reps > 0) {
            len++;
            out = (int*) realloc(out, len*sizeof(int));
            out[len-1] = reps;
        }

        free(count);
    }

    for(int i = 0; i < len; i++) printf("%d\n", out[i]);
    free(out);

    return 0;
}
