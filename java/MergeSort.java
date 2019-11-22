import java.util.Scanner;

public class MergeSort {
    public static void sort(int A[], int l, int r) {
        if(l < r) {
            int mid = (l + r) / 2;

            sort(A, l, mid);
            sort(A, mid + 1, r);

            mergeSort(A, l, mid, r);
        }
    }

    public static void mergeSort(int A[], int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        int L[] = new int[n1];
        int R[] = new int[n2];

        for(int i = 0; i < n1; i++)
            L[i] = A[l + i];
        for(int j = 0; j < n2; j++)
            R[j] = A[mid + 1 + j];

        int i = 0, j = 0;
        int k = l;
        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) {
                A[k] = L[i];
                i++;
            }
            else {
                A[k] = R[j];
                j++;
            }
            k++;
        }

        while(i < n1) {
            A[k] = L[i];
            k++;
            i++;
        }

        while(j < n2) {
            A[k] = R[j];
            k++;
            j++;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int A[] = new int[n];
        for (int i = 0; i < n; i++)
            A[i] = sc.nextInt();

        sort(A, 0, n - 1);
        for (int i = 0; i < n; i++)
            System.out.print(A[i]+" ");
        sc.close();
    }
}