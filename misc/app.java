// Header files for Java
import java.util.*;
import java.lang.String;

public class app {
    public static void main(String[] args) {
        String s = "Hello CSCI";// In Java have to have uppercase S because String is a class
        System.out.println(s);

        boolean bool = false; // Cannot use 0
        int x = 0;
        char c = 'c';
        float f = 0.8f;
        int y[] = new int[10]; // Array - Don't have to delete in Java

        if (bool == false) {
            System.out.println(s + " " + "Something");
        }
        else if (x != 1) {
            x -= -1;
            System.out.println("Something else");
        }
        else {
         f /= 0;
        }
        c = 'j';
        for (int i = 0; i < 10; i++) {
            y[i] = i * 42;
        }
        for (int n : y) {
            System.out.println(n);

        }
        System.out.println("What is your name?");
        Scanner in = new ScannerJava(System.in);
        String str = in.nextLine();
        System.out.println(str);
    }
}

// To compile: javac app.java
// To run: java app