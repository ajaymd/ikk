public class Lis {
    public static void main(String[] args) {
        int[] s = new int[args.length];
        for (int i = 0; i < args.length; ++i)
            s[i] = Integer.parseInt(args[i]);
        longestIncreasingSubSequence(s);
    }

    public static void longestIncreasingSubSequence(int[] s) {
        int length = s.length;
        // The following three lines are not needed but they make the rest of code more
        // readable as the indices of the original sequence will be from 1 to length
        int sequence[] = new int[length + 1];
        sequence[0] = Integer.MIN_VALUE;
        System.arraycopy(s, 0, sequence, 1, length);

        // i - current, j - last
        int array[][] = new int[length + 1][length + 1];

        for (int j = length - 1; j >= 0; --j)
            array[length][j] = sequence[length] > sequence[j] ? 1 : 0;

        for (int i = length - 1; i >= 1; --i)
            for (int j = i - 1; j >= 0; --j)
                array[i][j] = sequence[i] > sequence[j] ? Math.max(array[i + 1][j], array[i + 1][i] + 1) : array[i + 1][j];

        // Printing
        for (int i = 1; i <= length; ++i)
            System.out.print(sequence[i] + " ");
        System.out.println();

        for (int j = length - 1; j >= 0 ; --j) {
            for (int i = 1; i <= length; ++i)
                System.out.print((i <= j ? " " : array[i][j]) + " ");
            System.out.println();
        }

        int j = 0;
        for (int i = 1; i <= length; ++i) {
            if (sequence[i] <= sequence[j] || i != length && array[i][j] == array[i + 1][j])
                continue;
            System.out.format("%d ", sequence[i]);
            j = i;
        }
        System.out.println();
    }
}
