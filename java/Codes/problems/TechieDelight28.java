package problems;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * https://www.techiedelight.com/find-minimum-sum-subarray-given-size-k/
 */
public class TechieDelight28 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            A.add(sc.nextInt());
        }
        int k = sc.nextInt();
        findSubArray(A, n, k);
        sc.close();
    }

    private static void findSubArray(List<Integer> a, int n, int k) {
        int window_sum = 0, end_index = 0;
        int min_so_far = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            window_sum += a.get(i);
            if(i + 1 >= k) {
                if(window_sum < min_so_far) {
                    min_so_far = window_sum;
                    end_index = i;
                }
                window_sum -= a.get(i + 1 - k);
            }
        }
        System.out.println("Subarray is from : "+(end_index + 1 - k)+" to "+end_index);
    }
}
