/*
Difficulty: Easy 
John has a string S, but he like only special strings. So, he has to calculate the 
total number of special substrings in S.

A string T, of length L, is called special string, if either of the following property holds:
    1. All characters of the string T are same. for example, aaa
    2. The string has an odd length (i.e, L is odd) and all characters of T are same except the 
    middle character, for example, aabaa.

Help John to write a function count_special_substrings(), Which will Count the total number of special substrings in S.

Input constraints:
String S contains only lower-case English alphabets.

Input:
First Argument of count_special_substrings() contains a string S.

Output:
Write Count of the total number of special substrings in S.

Sample Input: 
S: aba

Sample Output:
4

Explanation:
S="aba"
Then there are 4 special substrings: {"a", "b", "a", "aba"}

Note: Take inputs using Scanner and Don't change the class name.
*/

import java.util.Scanner;

class special_substrings 
{

	public static void count_special_substrings(String S) 
	{
		int ans = 0;
        int len = S.length();
        int count = 1;
        int[] leftEnd = new int[100];
        int[] rightEnd = new int[100];

	    for(int i = 1; i < len; i++)
	    {
	    	if(S.charAt(i) == S.charAt(i - 1))
	    		count++;
	    	else
	    	{
	    		ans += count * (count + 1) / 2;
	    		count = 1;
	    	}
	    }
	    ans += count * (count + 1) / 2;
	    
	    count = 1;
	    for(int i = 1; i < len; i++)
	    {
	    	if(S.charAt(i) == S.charAt(i - 1))
	    		count++;
	    	else
	    	{
	    		leftEnd[i] = count;
	    		count = 1;
	    	}
        }
        
	    count = 1;
		for(int i = len - 2; i >= 0; i--)
	    {
	    	if(S.charAt(i) == S.charAt(i + 1))
	    		count++;
	    	else
	    	{
	    		rightEnd[i] = count;
	    		count = 1;
	    	}
        }
        	    
	    for(int i = 1; i < len - 1; i++)
	    {
            int p = Math.min(leftEnd[i], rightEnd[i]);
            if((S.charAt(i - 1) == S.charAt(i + 1)) && (S.charAt(i) != S.charAt(i + 1)))
	    		ans += p;
	    }
		System.out.println(ans);
	}

	public static void main(String arg[]) 
	{
		Scanner s = new Scanner(System.in);
		String S; 
		S = s.next();
		count_special_substrings(S);
	}

}