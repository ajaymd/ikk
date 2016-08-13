public class Houses {
    public static int recursiveMaxGain(int array[], int i, boolean allowedToSelect) {
        if (i == array.length - 1)
            return allowedToSelect ? array[i] : 0;

        int max0 = recursiveMaxGain(array, i + 1, false);
        int max1 = recursiveMaxGain(array, i + 1, true);

        return allowedToSelect ? Math.max(array[i] + max0, max1) : max1;
    }

    public static int dynamicProgramming(int array[]) {
        int length = array.length;
        int allowed[] = new int[length];
        int notAllowed[] = new int[length];

        allowed[length - 1] = array[length - 1];
        notAllowed[length - 1] = 0;

        for(int i = length - 2; i >= 0; --i) {
            allowed[i] = Math.max(array[i] + notAllowed[i + 1], allowed[i + 1]);
            notAllowed[i] = allowed[i + 1];
        }

        return allowed[0];
    }

    private static int input[] = {18, 4, 1, 20};

    public static void main(String [] args) {
        System.out.println("Recursion: " + recursiveMaxGain(input, 0, true));
        System.out.println("Dynamic Programming: " + dynamicProgramming(input));
    }
}
