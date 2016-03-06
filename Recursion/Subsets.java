public class Subsets {
    public static void main(String[] args) {
        printSubsets(args);
    }

    public static void printSubsets(Object[] set) {
        Object[] subset = new Object[set.length];
        printSubsets(set, 0, subset, 0);
    }

    private static void printSubsets(Object[] set, int read, Object[] subset, int write) {
        if (read == set.length) {
            System.out.print("{");
            for (int i = 0; i < write; ++i) {
                System.out.print(subset[i]);
                if (i + 1 != write)
                    System.out.print(", ");
            }
            System.out.println("}");
            return;
        }

        printSubsets(set, read + 1, subset, write); // Don't select
        subset[write] = set[read]; // Select
        printSubsets(set, read + 1, subset, write + 1);
    }
}
