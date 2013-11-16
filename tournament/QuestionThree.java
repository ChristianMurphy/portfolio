import java.util.Scanner;

/**
 * This program prompts user to input two black jack hands
 * (the total value of the cards as an integer)
 * Then applies the standard rules of black jack.
 * If greater than 21 bust
 * else greater hand wins
 * 
 * @author Christian Murphy
 *
 */

public class QuestionThree {
	public static void main(String[] args) {
		//gets the hands
		int handOne = getUserInt("Enter first hand");
		int handTwo = getUserInt("Enter second hand");
		//prints the winning hand
		System.out.println( blackjack(handOne,handTwo) );
	}
	
	public static int getUserInt(String prompt) {
		Scanner input = new Scanner(System.in);
	    System.out.println(prompt + " (as an integer): ");
	    return input.nextInt();
	}
	
	public static int blackjack(int handOne, int handTwo) {
		boolean handOneBust		= handOne > 21;
		boolean handTwoBust		= handTwo > 21;
		boolean handOneGreater	= handOne > handTwo;
		
		if (handOneBust && handTwoBust) {
			return 0;
		}
		else if (handTwoBust || handOneGreater && !handOneBust) {
			return handOne;
		}
		else {
			//handOne busts for handTwo is greater
			return handTwo;
		}
	}
}
