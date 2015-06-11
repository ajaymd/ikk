public class Lis {
    public static void main(String[] args) {
        // longestCommonSubSequence(new int[]{1, 3, 6, 4, 7, 2, 8, 9, 12});
        //longestCommonSubSequence(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9});
        //longestCommonSubSequence(new int[]{1});
        longestCommonSubSequence(new int[]{1000, 2, 4, 6, 8, 10, 1, 2, 3, 4, 5, 6});

    }

    public static void longestCommonSubSequence(int[] s) {
        int length = s.length;
        // The following three lines are not needed but they make the rest of code more
        // readable as the indices of the original sequence will be from 1 to length
        int sequence[] = new int[length + 1];
        sequence[0] = Integer.MIN_VALUE;
        System.arraycopy(s, 0, sequence, 1, length);

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
