// Simple factorials using recursion

public class Factorials {

	public static int factorial(int N) {

		if (N == 0) 
			return 1;
		else if (N == 1) 
			return 1;

		return N * factorial(N-1);
	}

	public static void main(String args[]) {

		Scanner input = new Scanner(System.in);
		N = input.nextInt();

		System.out.println(factorial(N));
	}
}