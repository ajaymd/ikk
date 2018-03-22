import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	static class TreeNode
	{
        /*
        To find height of tree, value stored in nodes does not matter. So in input also we are 
        not given this field. 
        */
		//int val;														
		Vector<TreeNode> children = new Vector<TreeNode>(0);
		TreeNode()
		{
			children.clear();
		}
	};


	//--------------------------------START------------------------------------

    /*
	    For your reference:
	    
	    static class TreeNode
	    {
	        Vector<TreeNode> vec = new Vector<TreeNode>(0);
	        TreeNode()
	        {
	            children.clear();
	        }
	    };
    */

    static int find_height(TreeNode root)
    {
        // Handle base case when root is a leaf node.
        if (root.children.size() == 0)									
        {
            return 0;
        }
        int h = 0;
        for (int i = 0; i < root.children.size(); i++)
        {
            TreeNode temp = root.children.get(i);
            // Find height of each children and store the maximum height of children. 
            h = Math.max(h, find_height(temp));						
        }
        return h + 1;			
    }

    //--------------------------------STOP------------------------------------

    static HashMap <Integer, TreeNode> address = new HashMap<Integer, TreeNode>();

    static TreeNode build_tree(int[] from, int[] to) {
    	int N = from.length + 1;
        // Clear the variable. 
		address.clear();												
		for (int i = 1; i <= N; i++)
		{
            // Create N nodes. 
			address.put(i, new TreeNode());								
		}
		for (int i = 0; i < N - 1; i++)								  
		{
            // Link the nodes. (Build the k-ary tree.)
			address.get(from[i]).children.add(address.get(to[i]));		
		}
		return address.get(1);	
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        final String fileName = System.getenv("OUTPUT_PATH");
        BufferedWriter bw = null;
        if (fileName != null) {
            bw = new BufferedWriter(new FileWriter(fileName));
        }
        else {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        int res;
        int k;
        k = Integer.parseInt(in.nextLine().trim());

        int from_size = 0;
        from_size = Integer.parseInt(in.nextLine().trim());

        int[] from = new int[from_size];
        for(int i = 0; i < from_size; i++) {
            int from_item;
            from_item = Integer.parseInt(in.nextLine().trim());
            from[i] = from_item;
        }

        int to_size = 0;
        to_size = Integer.parseInt(in.nextLine().trim());

        int[] to = new int[to_size];
        for(int i = 0; i < to_size; i++) {
            int to_item;
            to_item = Integer.parseInt(in.nextLine().trim());
            to[i] = to_item;
        }

        TreeNode root = build_tree(from, to);

        res = find_height(root);
        bw.write(String.valueOf(res));
        bw.newLine();

        bw.close();
	}
}
