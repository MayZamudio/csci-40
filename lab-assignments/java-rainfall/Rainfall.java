import java.util.*;
import java.lang.String;
import java.util.Arrays;

public class Rainfall {
    public static void main(String[] args) {
        java.util.Scanner cin = new java.util.Scanner(System.in);
        System.out.println("Welcome to Java Rainfall!");
        System.out.println("Please enter daily rainfall data (-1 to quit):");

        ArrayList<Integer> userVals = new ArrayList<Integer>();
        int num = 0;
        int nonRainyDays = 0;
        // Count rainy days
        while (true) {
            try {
                num = cin.nextInt();
            }
            catch (Exception e) {
                System.out.println("BAD INPUT!");
                System.exit(0);
            }
            if (num == -1) break;
            if (num > -1) userVals.add(num);
            if (num == 0) nonRainyDays++;
            if (!cin.hasNextInt()){
                System.out.println("BAD INPUT!");
                System.exit(0);
            }
        }
        //    sort(userVals.begin(), userVals.end(), greater<>());
        Collections.sort(userVals, Collections.reverseOrder());
        int sum = 0;
        for (int x : userVals){
            sum += x;
        }

        int average = sum / userVals.size();
        int numRainyDays = (userVals.size() - nonRainyDays);
        int averageRainy = 0;
        if (numRainyDays != 0) {
            averageRainy = sum / numRainyDays;
        }
        int choice = 0;
                while (true) {
            System.out.println("1) Average daily rainfall");
            System.out.println("2) Average rainfall on rainy days");
            System.out.println("3) Count of days that had rain");
            System.out.println("4) Maximum rainfall");
            System.out.println("5) Top 5 days of rain");
            System.out.println("6) Quit");
            try {
                choice = cin.nextInt();
            }
            catch (Exception e) {
                System.out.println("BAD INPUT!");
                System.exit(0);
            }
            if (choice == 1) {
                if (userVals.isEmpty()) System.out.println("NO DATA"); //cout << "NO DATA\n";
                else System.out.println(average);//cout << average << endl;
            } else if (choice == 2) {
                if (userVals.isEmpty() || numRainyDays == 0) System.out.println("NO DATA"); //cout << "NO DATA\n";
                else System.out.println(averageRainy);//cout << averageRainy << endl;
            } else if (choice == 3) {
                System.out.println(numRainyDays);//cout << numRainyDays << endl;
            } else if (choice == 4) {
                if (userVals.isEmpty() || numRainyDays == 0) System.out.println("NO DATA");//cout << "NO DATA\n";
                else System.out.println(userVals.get(0));//cout << userVals.get(0) << endl;
            } else if (choice == 5) {
                if (userVals.get(0) == 0) System.out.println("NO DATA");//cout << "NO DATA\n";
                else {
                    for (int i = 0; i < 5; i++) {
                        if (i > userVals.size() - 1 || userVals.get(i) == 0) break;
                        System.out.println(userVals.get(i));//cout << userVals.at(i) << endl;
                    }
                }
            } else break;
        }
    }

}