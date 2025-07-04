"""
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
**/
"""
import sys

def main():
    C = int(input())
    out = []
    for _ in range(C):
        data = input().split()
        N = int(data[0])
        grades = list(map(int, data[1:1+N]))
        avg = sum(grades) / N
        count_above = sum(1 for g in grades if g > avg)
        pct = count_above / N * 100.0
        out.append(f"{pct:.3f}%")

    print("\n".join(out))

if __name__ == "__main__":
    main()
