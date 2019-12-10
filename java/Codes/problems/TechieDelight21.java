package problems;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * problems.TechieDelight21
 * Given an array of integers, find the maximum difference between two elements in the array such that
 *  smaller element appears before the larger element.
 */
public class TechieDelight21 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            A.add(sc.nextInt());
        }
        System.out.println(getDiff(A, n));
        sc.close();
    }

    private static int getDiff(List<Integer> a, int n) {
        int diff = Integer.MIN_VALUE;
        int max_so_far = a.get(n - 1);
        for(int i = n - 2; i >= 0; i--) {
            if(a.get(i) > max_so_far)
                max_so_far = a.get(i);
            else
                diff = Math.max(diff, max_so_far - a.get(i));
        }
        return diff;
    }
}