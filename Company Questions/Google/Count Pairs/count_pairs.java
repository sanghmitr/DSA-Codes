package Count_Pairs;
import java.io.*;
import java.util.*;


public class CountPairs {


    static int diff = 0;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("/home/ayush/Downloads/Questions/Count_Pairs/input.txt"));

        int n = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());
        int d = Integer.parseInt(br.readLine());

        int[] a = new int[n];
        int[] b = new int[n];
        
        StringTokenizer sb = new StringTokenizer(br.readLine());
        StringTokenizer sb2 = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(sb.nextToken());
            b[i] = Integer.parseInt(sb2.nextToken());
        }

        diff = c - d;
        int[] in = new int[n];
        for (int i = 0; i < n; ++i) in[i] = b[i] - a[i]; 

        System.out.println(solve(in));


    }

    private static int solve(int[] nums) {
        int[] temp = nums.clone();
        return mergeSort(nums, temp, 0, nums.length - 1);
    }


    private static int mergeSort(int[] a, int[] temp, int l, int h) {
        if (l >= h) return 0;
        int m = l + (h  - l) / 2, inv = 0;
        
        inv += mergeSort(a, temp, l, m);
        inv += mergeSort(a, temp, m + 1, h);        
        inv += merge(a, temp, l, m, h);
        
        return inv;
       
    }
    
    private static int merge(int[] a, int[] temp, int l, int m, int h) {
        int inv = 0;
        
        int i = l, j = m + 1;
        
        for (; i <= m; ++i) {
            while (j <= h && a[i] >= a[j] + diff) ++j;
            inv += (j - (m + 1));
        }
        
        
        
        for (int k = l; k <= h; ++k) temp[k] = a[k];
        i = l; j = m + 1;
        
        for (int k = l; k <= h; ++k) {
            if (i > m) a[k] = temp[j++];
            else if (j > h) a[k] = temp[i++];
            else if (temp[i] > temp[j]) a[k] = temp[j++];
            else a[k] = temp[i++];
            
        }
        
        return inv;
    }
}