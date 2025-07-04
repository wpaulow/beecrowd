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
import java.util.Locale;
import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class BC1214 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        int C = sc.nextInt();
        List<BigDecimal> percentages = new ArrayList<>();

        for (int tc = 0; tc < C; tc++) {
            int N = sc.nextInt();
            int[] grades = new int[N];
            int sum = 0;
            for (int i = 0; i < N; i++) {
                grades[i] = sc.nextInt();
                sum += grades[i];
            }

            BigDecimal total = new BigDecimal(sum);
            BigDecimal count = new BigDecimal(N);
            BigDecimal avg = total.divide(count, 10, RoundingMode.HALF_UP);

            long countAbove = Arrays.stream(grades)
                .mapToObj(grade -> new BigDecimal(grade))
                .filter(g -> g.compareTo(avg) > 0)
                .count();

            BigDecimal above = new BigDecimal(countAbove);
            BigDecimal percent = above
                .multiply(new BigDecimal("100"))
                .divide(count, 5, RoundingMode.HALF_UP)
                .setScale(3, RoundingMode.HALF_EVEN);

            percentages.add(percent);
        }
        percentages.stream()
            .forEach(percent -> System.out.printf("%.3f%%%n", percent));

        sc.close();
    }
}
