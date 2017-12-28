public class EditDistance {
    public static void main(String [] args) {
        System.out.println(editDistance(args[0], args[1]));
    }

    private static int editDistance(String left, String right) {
        int lLength = left.length();
        int rLength = right.length();
        int array[][] = new int[lLength + 1][rLength + 1];
        array[lLength][rLength] = 0;
        for (int i = lLength - 1; i >= 0; --i)
            array[i][rLength] = lLength - i;
        for (int j = rLength - 1; j >= 0; --j)
            array[lLength][j] = rLength - j;
        for (int i = lLength - 1; i >= 0; --i) {
            for (int j = rLength - 1; j >= 0; --j) {
                int min = Math.min(array[i][j + 1] + 1, array[i + 1][j + 1] + (left.charAt(i) == right.charAt(j) ? 0 : 1));
                array[i][j] = Math.min(min, array[i + 1][j] + 1);
            }
        }    

        int i = 0;
        int j = 0;
        System.out.println(left);
        System.out.println(right);
        while (i != lLength || j < rLength) {
            if (j >= rLength) {
                System.out.println(i + ": delete " + left.charAt(i));
                i++;
                continue;
            }
            if (i >= lLength) {
                System.out.println(j + ": add " + right.charAt(j));
                j++;
                continue;
            }
            if (array[i][j] == array[i][j + 1] + 1) {
                System.out.println(i + ": add " + right.charAt(j));
                j++;
            } else if (array[i][j] == array[i + 1][j] + 1) {
                System.out.println(i + ": delete " + left.charAt(i));
                i++;
            }
            else if (array[i][j] != array[i + 1][j + 1]) {
                System.out.println(i + ": replace " + left.charAt(i) + " with " + right.charAt(j));
                i++;
                j++;
            }
            else {
                System.out.println(i + ": move (" + right.charAt(j) + ")");
                i++;
                j++;
            }
        }
        return array[0][0];
    }
}
