package problems;

import java.util.Scanner;

public class Solution {
    
    public static void getList(int A[], int n) {
        // ArrayList<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        int prev = 1;
        for(i = 0; i < n ; i++) {
            if(j < i) {
                if(A[i] > A[j]) {
                    prev = i - j;
                    System.out.print(i - j);
                    j++;
                }
                else if(A[i] == A[j]) {
                    
                }
            }
        }
        System.out.println();
    }
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t != 0) {
            int n = sc. nextInt();
            int A[] = new int[n];
            for(int i = 0; i < n; i++) {
                A[i] = sc.nextInt();
            }
            sc.close();
            getList(A, n);
            t--;
        }
    }
}