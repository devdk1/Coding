import java.util.Scanner;

public class MaxProductSubArray {
    public static int maxProduct(int arr[], int n) {
        int max_so_far = 0;
        int max_ending_here = 0, min_ending_here = 0;

        for(int i = 0; i < n; i++) {
            int temp = max_ending_here;
            max_ending_here = Integer.max(arr[i], Integer.max(arr[i] * max_ending_here, arr[i] * min_ending_here));
            min_ending_here = Integer.min(arr[i], Integer.min(arr[i] * temp, arr[i] * min_ending_here));

            max_so_far = Integer.max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        sc.close();
        System.out.println(maxProduct(arr, n));   
    }
}