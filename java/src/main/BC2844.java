import java.util.Scanner;
import java.util.Arrays;

public class BC2844 {

    public static int[] readValues(Scanner scanner){
    String line = scanner.nextLine();

    return Arrays.stream(line.split(" "))
                          .mapToInt(Integer::parseInt)
                          .toArray();
    }

    public static int typingTime(int lag, int react, int timeSpent, int lenStr) {
        return 2*lag + react + timeSpent * lenStr;
    }

    public static void winner(int timeMat, int timeVini){
        int x = Integer.compare(timeMat, timeVini);
        if(x == -1) System.out.println("Matheus");
        else if(x == 1) System.out.println("Vinicius");
        else System.out.println("Empate");
    }

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);

        int[] matValues = readValues(scanner);
        int[] viniValues = readValues(scanner);

        int lagMat = matValues[0];
        int reactMat = matValues[1];
        int timeSpentMat = matValues[2];

        int lagVini = viniValues[0];
        int reactVini = viniValues[1];
        int timeSpentVini = viniValues[2];

        String sentence = scanner.nextLine();
        int lenSentence = sentence.length();

        int totalTimeMat = typingTime(lagMat, reactMat, timeSpentMat, lenSentence);
        int totalTimeVini = typingTime(lagVini, reactVini, timeSpentVini, lenSentence);

        winner(totalTimeMat, totalTimeVini);

        scanner.close();
    }
}