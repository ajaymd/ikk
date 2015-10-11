/******************************************************************************
 * Print all permutations of an array of length n
 *****************************************************************************/
public class Permutations {
    public static void main(String[] args) {
        printPermutations(args);
    }

    public static void printPermutations(Object[] array) {
        printPermutations(array, 0);
    }

    private static void printPermutations(Object[] array, int i) {
        if (i == array.length) {
            for (Object obj : array) System.out.print(" " + obj);
            System.out.println();
            return;
        }

        for (int j = i; j < array.length; ++j) {
            swap(array, i, j);
            printPermutations(array, i + 1);
            swap(array, i, j);
        }
    }

    private static void swap(Object[] array, int i, int j) {
        Object tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
    }
}
