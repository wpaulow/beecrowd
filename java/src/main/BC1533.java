import java.util.Scanner;

public class BC1533 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int N = sc.nextInt();
            if (N == 0) {
                break;
            }

            int[] suspects = new int[N];
            for (int i = 0; i < N; i++) {
                suspects[i] = sc.nextInt();
            }

            int mostSuspect = Integer.MIN_VALUE;
            int secondMostSuspect = Integer.MIN_VALUE;

            for (int i = 0; i < N; i++) {
                if (suspects[i] > mostSuspect) {
                    secondMostSuspect = mostSuspect;
                    mostSuspect = suspects[i];
                } else if (suspects[i] > secondMostSuspect && suspects[i] < mostSuspect) {
                    secondMostSuspect = suspects[i];
                }
            }

            int iSecondMostSuspect = -1;
            for (int i = 0; i < N; i++) {
                if (suspects[i] == secondMostSuspect) {
                    iSecondMostSuspect = i + 1;
                    break;
                }
            }
            System.out.println(iSecondMostSuspect);
        }
        sc.close();
    }
}