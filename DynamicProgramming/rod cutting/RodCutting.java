import java.util.HashMap;
import java.util.Map;

public class RodCutting {
    public static int recursion(int[] prices, int length) {
        if (length == 0)
            return 0;

        int max = 0;
        for (int cut = 1; cut <= length; ++cut) {
            int i = prices[cut] + recursion(prices, length - cut);
            if (i > max)
                max = i;
        }
        return max;
    }
    public static int memoization(int[] prices, int length) {
        Map<Integer, Integer> cache = new HashMap<>();
        return memoization(prices, length, cache);
    }

    public static int memoization(int[] prices, int length, Map<Integer, Integer> cache) {
        if (length == 0)
            return 0;

        int c = cache.getOrDefault(length, 0);
        if (c != 0)
            return c;

        int max = 0;
        for (int cut = 1; cut <= length; ++cut) {
            int i = prices[cut] + memoization(prices, length - cut);
            if (i > max)
                max = i;
        }
        cache.put(length, max);
        return max;
    }

    public static int dynamicProgramming(int[] prices, int length) {
        int[] maxRevenue = new int[length + 1];
        maxRevenue[0] = 0;

        for (int l = 1; l <= length; ++l) { // l is the same as length in recursion
            int max = 0;
            for (int cut = 1; cut <= l; ++cut) {
                int i = prices[cut] + maxRevenue[l - cut];
                if (i > max)
                    max = i;
            }
            maxRevenue[l] = max;
        }

        System.out.print("(");
        int l = length;
        while (l > 0) {
            int max = 0;
            int index = -1;
            for (int cut = 1; cut <= l; ++cut) {
                int i = prices[cut] + maxRevenue[l - cut];
                if (i > max) {
                    max = i;
                    index = cut;
                }
            }
            System.out.print(" " + index);
            l -= index;
        }
        System.out.print(")");

        return maxRevenue[length];
    }

    public static void main(String[] args) {
        int[] prices = {0, 1, 4, 11, 12, 13, 14, 15, 21, 24, 30};
        System.out.print("Recursion:" + recursion(prices, 7));
        System.out.print(" Memoization: " + memoization(prices, 7));
        System.out.println(" Dynamic Programming: " + dynamicProgramming(prices, 7));

        System.out.print("Recursion:" + recursion(prices, 1));
        System.out.print(" Memoization: " + memoization(prices, 1));
        System.out.println(" Dynamic Programming: " + dynamicProgramming(prices, 1));

        System.out.print("Recursion:" + recursion(prices, 10));
        System.out.print(" Memoization: " + memoization(prices, 10));
        System.out.println(" Dynamic Programming: " + dynamicProgramming(prices, 10));
    }
}
