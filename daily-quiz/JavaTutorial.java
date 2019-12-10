import java.util.ArrayList;

public class JavaTutorial {
    //5. Function
    private static int squared(int x) {
        Integer bob = x; //Boxing
        x = bob; //Unboxing
        //String s = bob.toString();
        return x*x;
    }

    public static void main(String[] args) {
        java.util.Scanner cin = new java.util.Scanner(System.in); //1. Input - This sets up something like cin
        System.out.println("Please type in your name:"); //1. This is how you cout

        int x = 7; //2. This is how you make a primitive variable
        String name = new String("Bob"); //2. This is how you make a class object - no delete needed
        name = cin.nextLine(); //1. Reads a sentence, this is like getline(cin,s);
        //name = cin.next(); //1. Reads just one word, this is like cin >> s;
        System.out.println("Please type in how many times you want me to say your name:");
        x = cin.nextInt();  //1. This reads one int, like cin >> x;

        for (int i = 0; i < x; i++) { //3. This is how you write a for loop
            System.out.println("Hi " + name);
        } //Curly braces are also optional with one line for loops and if statements

        for (String s : args) { //3. Range based for loops are identical
            System.out.println("Arg: " + s);
        }

        if (name.equals("Bill")) //4. If statements... string == string doesn't work here!
            System.out.println("I know you!");
        if (x == 7)
            System.out.println("X is seven!");

        //5. Functions
        System.out.println("5 squared: " + squared(5));

        //6. Arrays
        //int[] arr = new int[10]; 
        //int[] arr = {1,3,5,7,9,13}; 
        int arr[] = new int[] {2,4,6,8,10};
        arr[2] = 7;
        for (int i : arr) System.out.println(i);
        //6. Vectors are called ArrayLists in Java
        ArrayList<Integer> vec = new ArrayList<Integer>();
        vec.add(5);
        vec.add(10);
        vec.add(15);
        vec.add(20);
        int sum = 0;
        for (int i : vec) sum += i;
        System.out.println("5 + 10 + 15 + 20 = " + sum);
    }
}
