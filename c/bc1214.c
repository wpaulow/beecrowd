/**
*   https://judge.beecrowd.com/pt/problems/view/1214
*   Input
*       The input contains many test cases. The first line of the input contains
*   an integer C, indicating the number of test cases. Following are C test cases
*   or instances. Each test case starts with an integer N, which is the number
*   of people in a class (1 ≤ N ≤ 1000). After that, N integers are given,
*   separated by spaces, each representing the final grade (an integer between
*   0 and 100) of each student in the class.
*
*   Output
*       For each test case, print a line giving the percentage of students who
*   are above the class average, with the value rounded to 3 decimal places.
*
*   Author
*       GitHub: @wpaulow
*
*
**/

#include <stdio.h>
#include <stdlib.h>

double averages() {
    double average = 0.0;
    int grades, n_grades, c = 0, over = 0, sum = 0;
    int *lst_grades = NULL;

    while(1){
        scanf("%d", &grades);
        if(c == 0) {
            n_grades = grades;
            c = n_grades+2;
            lst_grades = (int*)realloc(lst_grades, n_grades*sizeof(int));
        } else {
            lst_grades[c-2] = grades;
            sum += lst_grades[c-2];
        }
        c--;
        if(c == 1) break;
    }
    average = sum/n_grades;
    for(int i = 0; i < n_grades; i++) {
        if(lst_grades[i] > average) over++;
    }

    return 100*over/(double)n_grades;
}

int main(void) {
    int c;
    scanf("%d", &c);
    double out[c];
    for(int i = 0; i < c; i++) out[i] = averages();

    for(int i = 0; i < c; i++) printf("%.3lf%\n", out[i]);

    return 0;
}
