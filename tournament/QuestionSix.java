

import java.util.Scanner;
/**
 * this takes in user input,
 * and prints if their input is a Jolly Jumper or not
 * @author Christian Murphy
 *
 */
public class QuestionSix {
	private static int length;
	
	public static void main(String[] args) {
		int[] jumpingNumbers = userInput();
		
		System.out.println("Is it a Jolly Jumper? " + isItJolly(jumpingNumbers) );
	}
	
	/**
	 * takes in user input through command line
	 * @return	int[]	of user inputs has entered
	 * @see Scanner
	 */
	private static int[] userInput() {
		Scanner scanner = new Scanner(System.in);
		
		//takes in length
		do {
			System.out.println("how many numbers in the list: ");
			length = scanner.nextInt();
		} while (length < 2);
			
		//creates storage for int array
		int[] jumpingNumbers = new int[length];
		
		//takes input for every element
		for (int counter = 0; counter < length; counter++) {
			System.out.println("enter a number");
			jumpingNumbers[counter] = scanner.nextInt();
		}
		
		//closes scanner and returns
		scanner.close();
		return jumpingNumbers;
	}
	
	/**
	 * checks if a number array is a Jolly Jumper set
	 * @param	jollyArray	a set of potenetial jolly jumper numbers
	 * @return	boolean		whether it is jolly or not
	 */
	private static boolean isItJolly (int[] jollyArray) {
		//creates array
		boolean[] checkList = new boolean[length - 1];
			
		//checks off what values appear
		for (int counter = 0; counter < (length - 1); counter++) {
			/*
			 * takes the difference of two consecutive values
			 * takes the absolute value of the difference
			 * decrements by one for array
			 */
			int magic = Math.abs(jollyArray[counter + 1] - jollyArray[counter]) - 1;
			
			//checks off number
			if ( (-1 < magic) && (magic < length) ) {
				checkList[magic] = true;
			}
			//not possible break
			else {
				return false;
			}
		}
		
		//tests to see if values have been checked off
		for (boolean test : checkList){
			if (!test) {
				return false;
			}
		}
		
		return true;
	}
}
