package problems;

import java.util.Scanner;
import java.util.Stack;

/**
 * problems.Spinny
 */
public class Spinny {
    /**
     * Pair
     */
    public class Pair {
        private int num;
        private int region;
        
        public Pair (int num, int region) {
            this.num = num;
            this.region = region;
        }

        public int getNum() {
            return this.num;
        }

        public int getRegion() {
            return this.region;
        }
    }

    /**
     *
     * @param A
     * @param n
     * @return
     */
    public static int SpinnyTask(int A[], int n) {
        int ans = 0;
        int i = 0;
        int left[] = new int[n];
        left[i] = 1;
        int leftMaxIndex = i;
        for(i = 1; i < n ; i++) {
            if(A[i] > A[i - 1]) {
                if(A[i] > A[leftMaxIndex]) {
                    left[i] = i - leftMaxIndex + left[leftMaxIndex];
                    leftMaxIndex = i;
                }
                else left[i] = left[i - 1] + 1;
            }
            else left[i] = 1;
        }
    
        int right[] = new int[n];
        right[n - 1] = 0;
        int rightMaxIndex = n - 1;
        for(i = n - 2; i >= 0; i--) {
            if(A[i] > A[i + 1]) {
                if(A[i] > A[rightMaxIndex]) {
                    right[i] = rightMaxIndex - i + right[rightMaxIndex];
                    rightMaxIndex = i;
                }
                else right[i] = right[i + 1] + 1;
            }
            else right[i] = 0;
        } 
    
        for(i = 0; i < n; i++)
            System.out.print(left[i]+" ");
        System.out.println();
        for(i = 0; i < n; i++)
            System.out.print( right[i]+" ");
        System.out.println();

        for(i = 0; i < n; i++)
            ans += left[i] + right[i];
    
        return ans;
    }

    public void SpinnyTaskUsingStk(int A[], int n) {
        Stack<Pair> st = new Stack<>();
        st.push(new Pair(A[0], 1));
        int left[] = new int[n];
        left[0] = 1;
        for(int i = 1; i < n; i++) {
            if(A[i] > st.peek().getNum()) {
                int currRegion = 1;
                while (!st.empty() && A[i] > st.peek().getNum()) {
                    Pair top = st.pop();
                    currRegion += top.getRegion();
                }
                left[i] = currRegion;
                st.push(new Pair(A[i], currRegion));
            }
            else {
                left[i] = 1;
                st.push(new Pair(A[i], 1));
            }
        }

        st.clear(); 
        st.push(new Pair(A[n - 1], 1));
        int right[] = new int[n];
        right[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(A[i] > st.peek().getNum()) {
                int currRegion = 1;
                while (!st.empty() && A[i] > st.peek().getNum()) {
                    Pair top = st.pop();
                    currRegion += top.getRegion();
                }
                right[i] = currRegion;
                st.push(new Pair(A[i], currRegion));
            }
            else {
                right[i] = 1;
                st.push(new Pair(A[i], 1));
            }
        }
        System.out.print("Left -> ");
        for(int i = 0; i < n; i++) {
            System.out.print(left[i]+" ");
        }
        System.out.println();

        System.out.print("Right -> ");
        for(int i = 0; i < n; i++) {
            System.out.print(right[i] - 1+" ");
        }
        System.out.println();

        System.out.print("Final -> ");
        for(int i = 0; i < n; i++) {
            System.out.print(left[i] + right[i] - 1+" ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int A[] = new int[n];

        for(int i = 0; i < n; i++)
            A[i] = sc.nextInt();

        Spinny spin = new Spinny();
        spin.SpinnyTaskUsingStk(A, n);
//        System.out.println(SpinnyTask(A, n));
        sc.close();
    }
}