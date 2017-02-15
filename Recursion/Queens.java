/******************************************************************************
 *
 *  Print all solutions to the N queens problem
 *
 *****************************************************************************/
public class Queens {
    static void queensRecursion(int[] array, int i) {
        if (i == array.length) {
            for (int e : array)
                System.out.print("+-");
            System.out.println("+");
            for(int k = 0; k < array.length; ++k) {
                for (int e : array)
                    System.out.print("|" + (e == k ? '*' : ' '));
                System.out.println("|");
                for (int e : array)
                    System.out.print("+-");
                System.out.println("+");
            }
            System.out.println();

            return;
        }

        for(int j = 0; j < array.length; ++j) {
            array[i] = j;
            if (isValid(array, i))
                queensRecursion(array, i + 1);
        }
    }

    static boolean isValid(int[] array, int i) {
        int k;
        for(k = 0; k < i; ++k) {
            if (array[k] == array[i])
                return false;
            if (array[k] - array[i] == k - i)
                return false;
            if (array[k] - array[i] == i - k)
                return false;
        }
        return true;
    }

    static void queens(int n) {
        int[] array = new int[n];
        queensRecursion(array, 0);
    }

    public static void main(String[] args) {
        queens(5);
    }
}
