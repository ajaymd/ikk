import java.util.TreeSet;

public class OptimalSolution {
    /*
     * Space Complexity: O(n*(MAX_LENGTH(KEYS)+MAX_LENGTH(VALUES)))
     * Time Complexity: O(n*(MAX_LENGTH(VALUE))
     */
    private static String[] originalSolution(String[] arr) {
        // Map to store a count for every key
        HashMap<String, Integer> count = new HashMap<>();
        // Map to store maximum String value for each key
        HashMap<String, String> maxValue = new HashMap<>();
        
        for (String x : arr) {
            // Split on space to seperate key and value
            String splits[] = x.split(" ");
            String key = splits[0];
            String value = splits[1];
            
            // If count contains the key, add 1 to it
            if (count.containsKey(key)) {
                count.put(key, count.get(key) + 1);
            }
            // Else put the value in map with count value 1
            else {
                count.put(key, 1);
            }
            
            // If maxValue contains key, put in map max of both values
            if (maxValue.containsKey(key)) {
                String value1 = maxValue.get(key);
                String value2 = value;
                if (value1.compareTo(value2) < 0) {
                    // value2 is greater
                    maxValue.put(key, value2);
                } else {
                    // value1 is greater
                    maxValue.put(key, value1);
                }
            }
            // Else add the new value
            else {
                maxValue.put(key, value);
            }
        }
        
        String answer[] = new String[count.size()];
        int pointer = 0;
        for (String key : count.keySet()) {
            answer[pointer++] = key + ":" + count.get(key) + "," + maxValue.get(key);
        }
        return answer;
    }
}
