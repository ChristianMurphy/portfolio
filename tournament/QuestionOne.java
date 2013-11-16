import java.util.Scanner;

/**
 * This program takes in User Input,
 * for if it is a weekday,
 * or if it is a vacation,
 * and prints if you can sleep in
 * 
 * @author Christian Murphy
 *
 */

public class QuestionOne {
	public static void main (String[] args) {
		boolean weekday = getUserBoolean("Is it a weekday?");
		boolean vacation = getUserBoolean("Is it a vacation?");
		System.out.println("Can I sleep in? " + sleepIn(weekday, vacation) );
	}
	
	public static boolean getUserBoolean(String prompt) {
		Scanner input = new Scanner(System.in);
	    System.out.println(prompt + " (True or False): ");
	    return input.nextBoolean();
	}
	
	public static boolean sleepIn (boolean weekday, boolean vacation) {
		return !weekday || vacation;
	}
}