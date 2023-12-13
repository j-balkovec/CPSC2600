import java.util.Scanner;

public class HW2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int universalSetSize = 10;
        int setA = 0;
        int setB = 0;

        System.out.println("Please enter numbers for set A (enter -1 to stop):");
        int userInputA;
        while ((userInputA = scanner.nextInt()) != -1) {
            if (userInputA >= 0 && userInputA < universalSetSize) {
                setA |= (1 << userInputA);
            } else {
                System.out.println("Invalid input. Enter a number between 0 and 9 or -1 to stop.");
            }
        }

        System.out.println("Please enter numbers for set B (enter -1 to stop):");
        int userInputB;
        while ((userInputB = scanner.nextInt()) != -1) {
            if (userInputB >= 0 && userInputB < universalSetSize) {
                setB |= (1 << userInputB);
            } else {
                System.out.println("Invalid input. Enter a number between 0 and 9 or -1 to stop.");
            }
        }

        System.out.print("\nSet A:         ");
        printSet(setA);
        System.out.print("Set B:         ");
        printSet(setB);

        int union = setA | setB;
        int intersection = setA & setB;
        int difference = setA & (~setB);

        System.out.print("\nUnion:         ");
        printSet(union);
        System.out.print("Intersection:  ");
        printSet(intersection);
        System.out.print("Difference:    ");
        printSet(difference);
        System.out.print("\n");
        
        Scanner.close();
    }

    private static void printSet(int set) {
        for (int i = 0; i < 10; i++) {
            int bit = (set >> i) & 1;
            System.out.print(bit);
        }
        System.out.print("\n");
    }
}