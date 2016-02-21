package coursework;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


/**
 * You are given a 2-Dimensional array with M rows and N columns. You are initially
 * positioned at (0,0) which is the top-left cell in the array. You are allowed to
 * move either right or downwards. The array is filled with 1's and 0's. A 1 indicates
 * that you can move through that cell, a 0 indicates that you cannot move through the
 * cell. Given a function numberOfPaths which takes in the above 2-D array, return the
 * number of paths from the top-left cell to the bottom-right cell (i.e. (0,0) to
 * (M- 1,N-1)).
 * 
 * Your task is to complete the body of the function and return a single integer
 * denoting the number of paths mentioned above. Since the answer can be large,
 * you have to return the number of paths modulo 1,000,000,007, i.e. ans % (109 + 7).
 * 
 * Constraints:
 * 1 ≤ N, M ≤ 1,000
 *
 */
public class PathsInMatrix {
 
    private int rows, cols;
    private int array[][] = null;
    private int counts[][] = null;
    
    private static final long PRIME = (long) 1e9 + 7;
     
    public static void main(String[] args)throws IOException {
 
        PathsInMatrix finder = new PathsInMatrix();
         
        BufferedReader reader =
        	new BufferedReader(new InputStreamReader((System.in)));
         
        System.out.print("Enter the no of rows in matrix: ");
        finder.rows = Integer.parseInt(reader.readLine());
        System.out.print("Enter the no of cols in matrix: ");
        finder.cols = Integer.parseInt(reader.readLine());

        finder.array = new int[finder.rows][finder.cols];
        finder.counts = new int[finder.rows][finder.cols];

        for(int i = 0; i < finder.rows; i++) {
            System.out.print("Enter " + (i+1) + "th row: ");
            for (int j = 0 ; j < finder.cols; j++) {
                String s = reader.readLine();
                finder.array[i][j] = Integer.parseInt(s);
                finder.counts[i][j] = -1;
            }
        }
        
        System.out.println("No of paths : "+ finder.noOfPaths(0, 0));
    }
 
    public int noOfPaths(int i, int j) {
    	if (counts[i][j] != -1) {
    		return counts[i][j];
    	}
   
    	int count = 0;
    	
        if ((i == rows-1) && (j == cols-1)) {
            count = array[i][j];
        } else if (i == rows-1) {
            count = array[i][j+1];
        } else if (j == cols-1) {
            count = array[i+1][j];
        } else if (array[i][j] == 1) {
            count = noOfPaths(i+1, j) + noOfPaths(i, j+1);
        }
        
        count %= PRIME;
        
        counts[i][j] = count;
        return count;
    }
}