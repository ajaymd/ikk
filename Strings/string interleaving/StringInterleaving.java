/****************************************
 *
 * Print all interleaving of strings
 *
 ****************************************/
public class StringInterleaving {
    public static void stringInterleaving(String left, String right) {
        char[] leftArray = left.toCharArray();
        char[] rightArray = right.toCharArray();
        char[] result = new char[left.length() + right.length()];
        stringInterleaving(leftArray, 0, rightArray, 0, result);
    }

    private static void stringInterleaving(char[] left, int l, char[] right, int r, char[] result) {
        if (l == left.length) {
            for (;r < right.length; ++r)
                result[l + r] = right[r];
            printResult(result);
            return;
        } else if (r == right.length){
            for (;l < left.length; ++l)
                result[l + r] = left[l];
            printResult(result);
            return;
        }

        result[l + r] = left[l];
        stringInterleaving(left, l + 1, right, r, result);
        result[l + r] = right[r];
        stringInterleaving(left, l, right, r + 1, result);
    }

    private static void printResult(char[] result) {
        if (result.length == 0)
            return;
        for (char c : result)
            System.out.print(c);
        System.out.println();
    }

    public static void main(String[] args) {
        String left = "ab";
        String right = "de";
        System.out.println(left + ":" + right);
        stringInterleaving(left, right);

        left = "abc";
        right = "d";
        System.out.println(left + ":" + right);
        stringInterleaving(left, right);

        right = "";
        System.out.println(left + ":" + right);
        stringInterleaving(left, right);

        left = "";
        System.out.println(left + ":" + right);
        stringInterleaving(left, right);

        System.out.println("End");
    }
}
