import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Change {
    public static int recursion(Set<Integer> coins, int change) {
        if (change == 0)
            return 0;

        int min = change;
        for (Integer coin : coins)
            if (change >= coin)
                min = Math.min(min, 1 + recursion(coins, change - coin));

        return min;
    }

    public static int memoization(Set<Integer> coins, int change) {
        int[] cache = new int[change + 1];
        return memoization(coins, change, cache);
    }

    public static int memoization(Set<Integer> coins, int change, int[] cache) {
        if (cache[change] > 0)
            return cache[change];

        if (change == 0)
            return 0;

        int min = change;
        for (Integer coin : coins)
            if (change >= coin)
                min = Math.min(min, 1 + memoization(coins, change - coin, cache));

        cache[change] = min;
        return min;
    }

    public static int dynamicProgramming(Set<Integer> coins, int change) {
        int minCoins[] = new int[change + 1];

        minCoins[0] = 0;

        for (int c = 1; c <= change; ++c) {  // c is the change of the recursion
            int min = c;
            for (Integer coin : coins)
                if (c - coin >= 0)
                    min = Math.min(min, 1 + minCoins[c - coin]);
            minCoins[c] = min;
        }

        return minCoins[change];
    }


    public static void main(String[] args) {
        Set<Integer> coins = new HashSet<>(Arrays.asList(1, 3, 10, 25, 40));

        for (int change = 1; change < 45; ++change) {
            System.out.print(change + " Recursion: " + recursion(coins, change));
            System.out.print(" Memoization: " + memoization(coins, change));
            System.out.println(" Dynamic Programming: " + dynamicProgramming(coins, change));
        }
    }
}
