import java.util.TreeSet;

public class OptimalSolution {
    /*
     * Space Complexity: O(phonenumberlength)
     * Time Complexity: O(phonenumberlength)
     */
    public static long numPhoneNumbers(int startdigit, int phonenumberlength) {
        
        // List of where integers where you can go from a particular integer
        ArrayList<ArrayList<Integer>> listOfNext = new ArrayList<>();
        
        // 0
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(0).add(4);
        listOfNext.get(0).add(6);
        
        // 1
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(1).add(6);
        listOfNext.get(1).add(8);
        
        // 2
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(2).add(7);
        listOfNext.get(2).add(9);
        
        // 3
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(3).add(4);
        listOfNext.get(3).add(8);
        
        // 4
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(4).add(3);
        listOfNext.get(4).add(9);
        listOfNext.get(4).add(0);
        
        // 5
        listOfNext.add(new ArrayList<Integer>());
        
        // 6
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(6).add(1);
        listOfNext.get(6).add(7);
        listOfNext.get(6).add(0);
        
        // 7
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(7).add(2);
        listOfNext.get(7).add(6);
        
        // 8
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(8).add(1);
        listOfNext.get(8).add(3);
        
        // 9
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(9).add(4);
        listOfNext.get(9).add(2);
        
        long numTill[][] = new long[phonenumberlength][10];
        // First digit is already given. So we can only form one number of length 1.
        numTill[0][startdigit] = 1;
        
        for(int i = 1; i < phonenumberlength; i++){
            for(int num = 0; num < 10; num++){
                for(int to:listOfNext.get(num)){
                    // We can come to num from all its neighbours.
                    // So we will add all possible numbers of length i-1 that are neighnours of num.
                    numTill[i][num] += numTill[i-1][to];
                }
            }
        }
        
        long ans = 0;
        // Sum all possible ending of length phonenumberlength
        for(int num = 0; num < 10; num++){
            ans += numTill[phonenumberlength-1][num];
        }
        return ans;
    }
}
