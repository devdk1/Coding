package problems;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * problems.TechieDelight25
 * Given an array of integers, find all distinct combinations of given length.
 */
public class TechieDelight25 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            A.add(sc.nextInt());
        }
        int length = sc.nextInt();
        getCombinations(A, n, length);
        sc.close();
    }

    private static void getCombinations(List<Integer> a, int n, int length) {
        
    }
}