package problems;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TechieDelight38 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            A.add(sc.nextInt());
        }
        getMaxProductSubarray(A, n);
        sc.close();
    }

    private static void getMaxProductSubarray(List<Integer> a, int n) {
        int max_ending_here = 0, min_ending_here = 0;
        int max_so_far = 0;

        for(int i = 0; i < n; i++) {
            int temp_max = max_ending_here;
            max_ending_here = Integer.max(a.get(i), Integer.max(max_ending_here * a.get(i), a.get(i) * min_ending_here));
            min_ending_here = Integer.min(a.get(i), Integer.min(a.get(i) * temp_max, a.get(i) * min_ending_here));

            max_so_far = Integer.max(max_so_far, max_ending_here);
        }
        System.out.println("Maximum product of subarray is : "+max_so_far);
    }
}
