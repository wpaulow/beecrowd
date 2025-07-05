def main():
    out = list()
    while True:
        reps = 0
        tickets_str, people_str = input().split(" ")
        tickets = int(tickets_str)
        people = int(people_str)

        if(tickets == 0 and people == 0):
            break

        count = [0] * (tickets+1)

        n_lst = input().split()
        for n in n_lst:
            if(n.isdigit()):
                n = int(n)
                if(n >= 1 and n <= tickets):
                    count[n] += 1
                    if (count[n] == 2):
                        reps += 1

        out.append(reps)

    for x in out:
        print(x)

main()




