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
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class BC1318 {
    public static void main(String[] args) {
        int tickets, people;
        ArrayList<Integer> out = new ArrayList<>();
        Scanner keyboard = new Scanner(System.in);

        while (true) {
            int reps = 0;
            HashMap<Integer, Integer> count = new HashMap<>(); 
            tickets = keyboard.nextInt();
            people = keyboard.nextInt();
            if (tickets == 0 && people == 0) break;

            // Read all tickets from the package
            // Count how many numbers have at least 2 occurrences
            for (int i = 0; i < people; i++) {
                int num = keyboard.nextInt();
                if (num >= 1 && num <= tickets){ 
                    count.put(num, count.getOrDefault(num, 0) + 1);
                if (count.getOrDefault(num, 0) == 2) reps++;
                }
            }
            
            out.add(reps);
        }
        keyboard.close();

        for (int x : out) System.out.println(x);
    }
}
