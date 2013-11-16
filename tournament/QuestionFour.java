import java.util.Scanner;

/**
 * This converts a base ten integer to a base two number
 * 
 * @author Christian Murphy
 *
 */

public class QuestionFour {
	public static void main (String[] Args) {
		int baseTen = getUserInt("Enter a base 10 number");
		System.out.println( convertToBinary(baseTen) );
	}
	
	public static int getUserInt(String prompt) {
		Scanner input = new Scanner(System.in);
	    System.out.println(prompt + " (as an integer): ");
	    return input.nextInt();
	}
	
	public static int convertToBinary(int number) {
		int binary = 0;
		
		for (int baseTen = number; baseTen > 0; baseTen /= 2) {
			binary *= 10;
			binary += baseTen % 2;
		}
		
		return binary;
	}
}
