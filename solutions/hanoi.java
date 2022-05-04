// Arup Guha (modified by Ali Orooji for 2021)
// 8/22/2015
// Solution to 2021 UCF Practice Local Contest
// Problem: Towers of Hanoi Grid (hanoi)

import java.util.*;

public class hanoi {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int discs = stdin.nextInt();
		int n = stdin.nextInt();

		// Impossible case.
		if (discs > (n-1)*(n-1)+1)
			System.out.println("impossible");

		// Otherwise, there's a nice tidy formula - 
		// each disc moves 2n-2 steps, doing a grid walk.
		else
			System.out.println( (discs*(2*n-2)) );
		
	}// end of main()

}// end of class hanoi 
