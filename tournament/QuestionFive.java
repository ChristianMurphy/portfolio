import java.util.Scanner;

/**
 * This program takes int two user inputs,
 * takes the first number to the power of the second number,
 * and prints the ones place of that number
 * 
 * @author Christian Murphy
 *
 */

public class QuestionFive {
	public static void main (String[] args) {
		int number = getUserInt("enter a number");
		int exponent = getUserInt("enter and exponent");
		System.out.println( exponential(number, exponent) );
	}
	
	public static int getUserInt(String prompt) {
		Scanner input = new Scanner(System.in);
	    System.out.println(prompt + " (as an integer): ");
	    return input.nextInt();
	}
	
	public static int exponential(int number, int exponent) {
		double result = Math.pow(number, exponent);
		return (int) result % 10;
	}
}
