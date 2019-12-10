/*
Difficulty: Easy
Being greedy for Water:

You are given container full of water. Container can have limited amount of water. 
You also have NN bottles to fill. 
You need to find the maximum numbers of bottles you can fill.
Input:
First Argument contains an integer arg1 capacity of the container.
Second Argument contains an interger arg2 number of bottles(length of array).
Third Argument contains an array arg3 capacities of each bottles.

Output:
You should print maximum number of bottles you can fill.

Example #1:
    SAMPLE INPUT 
    I: 10 II: 5 III: [8,5,4,3,2]

    SAMPLE OUTPUT s
    3

Example #2:
    SAMPLE INPUT 
    I: 10 II: 6 III: [1,3,7,2,2,1]

    SAMPLE OUTPUT 
    5

*/
//Note take inpus using Scanner, and do not change the class Name

import java.util.Scanner;
import java.util.Arrays; 


class being_greedy 
{
	/**
	 * Sort the array and maintain the sum till container capacity.
	 */
	public static void max_bottels(int arg1, int arg2, int[] arg3) 
	{
		Arrays.sort(arg3);
		int sum = 0, count = 0;
		for(int i = 0; i < arg2; i++) {
			sum += arg3[i];
			if(sum <= arg1)
				count++;
			else
				break;
		}
		System.out.println(count);
	}
	
	public static void main(String arg[]) 
	{
		Scanner s = new Scanner(System.in);
		int arg1, arg2;
		arg1 = s.nextInt();
		arg2 = s.nextInt();
		int arg3[] = new int[arg2];
		for (int i = 0; i < arg2; i++) {
			arg3[i] = s.nextInt();
		}
		max_bottels(arg1, arg2, arg3);
	}
	
}