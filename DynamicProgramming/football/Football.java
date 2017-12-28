public class Football {
    public static int recursion(int score) {
        if (score == 0)
            return 1;
        if (score < 0)
            return 0;
        return recursion(score - 7) + recursion(score - 3) + recursion(score - 2);
    }

    public static int countCombinations(int score) {
        int comb[] = new int[score + 1];
        comb[0] = 1;
        for (int i = 1; i <= score; ++i) {
            int c = 0;
            if (i >= 7)
                c += comb[i - 7];
            if (i >= 3)
                c += comb[i - 3];
            if (i >= 2)
                c += comb[i - 2];
            comb[i] = c;
        }

        return comb[score];
    }

    public static void main(String[] args) {
        for (int i = 0; i < 20; ++i)
            System.out.println(i + " " + countCombinations(i) + " " + recursion(i));
    }
}
