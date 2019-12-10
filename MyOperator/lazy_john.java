/*
Difficulty: Easy 
John is a lazy boy. His father decided to put him on a behavioral test for two months (60 days). 
On 1st day the father keeps a ration of 1 cookie, each day the ration will be doubled. 
If John is active on ith day he will be given all the cookies in the ration that day, otherwise, 
he is given zero cookies.
Given the total number of cookies John ate, find the number of days he was active?

Input Format:
The first argument contains an Integer denoting the total number of cookies John ate.

Output Format:
print the number of days John is active.

Example #1:
    Input: 6
    OUTPUT: 2

Explanation
To eat a total of 6 cookies John behaved normally 1st day and on the 3rd day.

Example #2:
    Input: 14444
    OUTPUT: 7
*/
//Note take inpus using Scanner, and do not change the class Name

import java.util.Scanner;

class lazy_john 
{
	/**
	 * number of 1's in binary representation of an Integer
	 */ 
	public static void active_days(int N) 
	{
		int count = 0; 
        while (N > 0) { 
            count += N & 1; 
            N >>= 1; 
        } 
        System.out.println(count);
	}
	
	public static void main(String arg[]) 
	{
		Scanner s = new Scanner(System.in);
		int N;
		N = s.nextInt();
		active_days(N);
	}
	
}