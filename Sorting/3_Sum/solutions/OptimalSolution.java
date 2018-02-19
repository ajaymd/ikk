import java.util.TreeSet;

public class OptimalSolution {
    /*
     * Time Complexity: O(N^2+Nlog(N))
     * Space Complexity: O(N^3)
     */
    static String[] originalSolution(ArrayList<Integer> input) {
        TreeSet<String> set = new TreeSet<>();
        int n = input.size();
        // We will sort the input first. This is a pre-requisite for two pointer technique.
        Collections.sort(input);
        for (int index = 0; index < n; index++) {
            int currentElement = input.get(index);
            // We need sum -currentElement so the sum of all three elements would be zero.
            int neededSum = -currentElement;
            // Maintain a left index to the next of current index
            // Maintain a right index to the last element of the array
            int left = index + 1, right = n - 1;
            while (left < right) {
                int sum = input.get(left) + input.get(right);
                if (sum == neededSum) {
                    /*
                     * If we find the triplet
                     * 1. Add it to the set
                     * 2. Move either the left pointer or the right pointer
                     */
                    if (!set.contains(
                    		currentElement + "," + input.get(left) + "," + input.get(right)
                    	)) {
                        set.add(currentElement + "," + input.get(left) + "," + input.get(right));
                    }
                    left++;
                } else if (sum > neededSum) {
                    // If sum is more than intended, decrement the right pointer
                    right--;
                } else {
                    // If sum is less than intended, increment the left pointer
                    left++;
                }
            }
        }
        // Return the array from the set
        return set.toArray(new String[set.size()]);
    }
}
