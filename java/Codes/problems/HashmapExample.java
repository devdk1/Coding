package problems;
/*package whatever //do not write package name here */

import java.util.*;

class HashmapExample {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while (t-- != 0) {
            int n = s.nextInt();
            HashMap<String, Integer> my_map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                String input = s.next();
                int count = s.nextInt();
                my_map.put(input, count);
            }
            String str = s.next();
            int output = (my_map.get(str) != null) ? my_map.get(str) : -1;
            System.out.println(output);
        }
        s.close();
    }
}