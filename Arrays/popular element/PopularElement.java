public class PopularElement {
    static int[] a;

    public static void main(String[] args) {
        if (args.length == 0)
            return;

        a = new int[args.length];
        for (int i = 0; i < a.length; ++i)
            a[i] = Integer.valueOf(args[i]);

        int p = (a.length + 3) / 4;

        for (int i = 1; i <= 4; ++i) {
            int candidate = a[p * i  - 1];
            int l = findLeftMostElement(candidate, p * (i - 1), p * i - 1);
            if (l + p - 1 >= a.length)
                return;
            if (a[l + p - 1] == candidate) {
                System.out.println(candidate);
                return;
            }
        }
    }

    static int findLeftMostElement(int element, int left, int right) {
        if (left == right)
            return left;
        int mid = (left + right) / 2;
        return a[mid] >= element ? findLeftMostElement(element, left, mid)
                                 : findLeftMostElement(element, mid + 1, right);
    }
}
