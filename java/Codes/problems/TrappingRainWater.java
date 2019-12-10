package problems;

import java.util.Scanner;
import java.util.Stack;

public class TrappingRainWater {
    public static int trappedWater(int A[], int n) {
        int ans = 0;
        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        while(l < r) {
            if(A[l] < A[r]) {
                if(A[l] >= leftMax)
                    leftMax = A[l];
                else 
                    ans += leftMax - A[l];
                l++;
            }
            else {
                if(A[r] >= rightMax)
                    rightMax = A[r];
                else 
                    ans += rightMax - A[r];
                r--;
            }
        }
        return ans;
    }

    /**
     * We will store indexes in Stack
     */
    public static int trappedWaterUsingStack(int A[], int n) {
        Stack<Integer> st = new Stack<>();
        int ans = 0;
        int distance, bounded_height;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && A[i] > A[st.peek()]) {
                int top = st.pop();
                if(!st.empty()) {
                    distance = i - st.peek() - 1;
                    bounded_height = Math.min(A[i], A[st.peek()]) - A[top];
                    ans += distance * bounded_height;
                }
            }
            st.push(i);
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int A[] = new int[n];

        for(int i = 0; i < n; i++)
            A[i] = sc.nextInt();
        System.out.println(trappedWater(A, n)+" Using stack : "+trappedWaterUsingStack(A, n));
        sc.close();
    }
}