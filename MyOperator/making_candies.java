/*
Difficulty: Medium
Making Candies
John loves playing games. His current favorite is CandyMaker, 
where the goal is to make candies.

John just started a level in which he must make (n) candies using (m) machines and (w) workers. 
In a single pass, he can make (m*w) candies, after each pass, he can decide whether to
spend some of his candies to buy more machines or hire more workers.
Buying a machine or hiring a worker costs (p) units of candies, and there is no limit to
the number of machines he can build or workers he can hire.

John wants to maximize his score by making all candies in a minimum number of passes.
Can you find and print the minimum number of passes required for John to make at least
units of candies?

Input Format:
Input consists of four integers describing the respective values of (m), (w), (p), and (n).

Output Format:
Print the minimum number of passes required to make at least (n) candies.

Example #1:
Input:
3
1
2
12
Output:
3

Example #2:
Input:
1
1
235
73
Output:
73
*/


import java.util.Scanner;

class making_candies 
{
	
	public static void max_passes(int m, int w, int p, int n) 
	{
		int passes = 0;
        int candy = 0;
        int run = Integer.MAX_VALUE;
        int step;
    
        while (candy < n) {
            step = (m > Integer.MAX_VALUE / w) ? 0 : (p - candy) / (m * w);
    
            if (step <= 0) {
                int mw = candy / p;
    
                if (m >= w + mw) {
                    w += mw;
                } else if (w >= m + mw) {
                    m += mw;
                } else {
                    int total = m + w + mw;
                    m = total / 2;
                    w = total - m;
                }
    
                candy %= p;
                step = 1;
            }
    
            passes += step;
            if (step * m > Integer.MAX_VALUE / w) {
                candy = Integer.MAX_VALUE;
            } else {
                candy += step * m * w;
                run = Math.min(run, (int)(passes + Math.ceil((n - candy) / (m * w * 1.0))));
            }
        }
    
    	System.out.println(Math.min(passes, run));
	}
	
	public static void main(String arg[]) 
	{
		Scanner s = new Scanner(System.in);
		int m, w, p, n;
		m = s.nextInt();
		w = s.nextInt();
		p = s.nextInt();
		n = s.nextInt();
		
		max_passes(m, w, p , n);
	}
	
}