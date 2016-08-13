public class Rope {
    public static int recursion(int ropeLength, boolean mustCut) {
        if (ropeLength == 1)
            return 1;

        int max = mustCut ? 0 : ropeLength;
        for (int i = 1; i < ropeLength; ++i)
            max = Math.max(max, recursion(i, false) * recursion(ropeLength - i, false));

        return max;
    }

    public static long dynamicProgramming(int ropeLength) {
        long max[] = new long[ropeLength + 1];

        max[1] = 1;

        for(int j = 2; j <= ropeLength; ++j) { // j is the ropeLength on the recursion
            long m = (j == ropeLength ?  0 : j);
            for(int i = 1; i < j; ++i) // i has the same role as in the recursion
                m = Math.max(m, max[i] * max[j - i]);
            max[j] = m;
        }

        return max[ropeLength];
    }

    public static void main(String[] args) {
        int ropeLength = 13;
        System.out.println("Recursion:" + recursion(ropeLength, true));
        System.out.println("Dynamic Programming: " + dynamicProgramming(ropeLength));
    }
}
