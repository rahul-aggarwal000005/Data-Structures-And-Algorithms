/*package whatever //do not write package name here */
import java.math.BigInteger;
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	static BigInteger factorial(int N)
	{
		// Initialize result
		BigInteger f = new BigInteger("1"); // Or BigInteger.ONE

		// Multiply f with 2, 3, ...N
		for (int i = 2; i <= N; i++)
			f = f.multiply(BigInteger.valueOf(i));

		return f;
	}
	public static void main (String[] args) {
		//code
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();
		while (t != 0) {
			int n = scn.nextInt();
			System.out.println(factorial(n));
			t--;
		}
	}
}