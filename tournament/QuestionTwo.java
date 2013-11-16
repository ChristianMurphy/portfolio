import java.util.Scanner;

/**
 * This program takes in a number entered by the user,
 * and returns the factorial of that number,
 * using recursion
 * 
 * @author Christian Murphy
 *
 */

public class QuestionTwo {
	public static void main (String[] args){
		int factor = getUserInt("enter a number to find the factorial of");
		System.out.println( factorial(factor) );
	}
	
	public static int getUserInt(String prompt) {
		Scanner input = new Scanner(System.in);
	    System.out.println(prompt + " (as an integer): ");
	    return input.nextInt();
	}
	
	public static int factorial (int number) {
		if (number == 1) {
			return 1;
		}
		else {
			return number * factorial(number - 1);
		}
	}
}
