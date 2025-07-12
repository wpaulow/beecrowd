import sys

def main():
    while True:
        N = int(sys.stdin.readline())
        if N == 0:
            break
        
        suspects = list(map(int, sys.stdin.readline().split()))

        most_suspect = 0
        second_most_suspect = 0

        for suspect in suspects:
            if suspect > most_suspect:
                second_most_suspect = most_suspect
                most_suspect = suspect
            elif suspect > second_most_suspect and suspect < most_suspect:
                second_most_suspect = suspect
        
        i_second_most_suspect = -1
        for i in range(N):
            if suspects[i] == second_most_suspect:
                i_second_most_suspect = i+1
                break
        
        print(i_second_most_suspect)

main()