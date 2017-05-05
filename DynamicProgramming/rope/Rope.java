public class Rope {
    public static int recursion(int ropeLength, int initialRopeLength) {
        if (ropeLength == 1)
            return 1;

        int max = initialRopeLength == ropeLength ? 0 : ropeLength;
        for (int i = 1; i < ropeLength; ++i)
            max = Math.max(max, i * recursion(ropeLength - i, initialRopeLength));

        return max;
    }

    public static int dynamicProgramming(int ropeLength) {
        int max[] = new int[ropeLength + 1];

        max[1] = 1;

        for(int j = 2; j <= ropeLength; ++j) { // j is the ropeLength on the recursion
            int m = (j == ropeLength ?  0 : j);
            for(int i = 1; i < j; ++i) // i has the same role as in the recursion
                m = Math.max(m, i * max[j - i]);
            max[j] = m;
        }

        return max[ropeLength];
    }

    public static void main(String[] args) {
        int ropeLength = 13;
        System.out.println("Recursion:" + recursion(ropeLength, ropeLength));
        System.out.println("Dynamic Programming: " + dynamicProgramming(ropeLength));
    }
}
