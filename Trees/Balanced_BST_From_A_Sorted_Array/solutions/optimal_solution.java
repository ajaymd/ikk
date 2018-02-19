import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static class TreeNode
    {
        int val;
        TreeNode left_ptr;
        TreeNode right_ptr;

        TreeNode(int _val)
        {
            val = _val;
            left_ptr = null;
            right_ptr = null;
        }
    };


    
    //-----------------------------------START----------------------------------------

    /*
     * Complete the function below.
     */

    /*
        For your reference:
        
        static class TreeNode
        {
            int val;
            TreeNode left_ptr;
            TreeNode right_ptr;

            TreeNode(int _val)
            {
                val = _val;
                left_ptr = null;
                right_ptr = null;
            }
        };
    */

    // build tree using values (a[l], a[l+1], ..., a[r]).
    static TreeNode build_balanced_bst_helper(int l, int r, int[] a)                    
    {
        if (l > r)  
        {
            return null;
        }
        int m = l + (r - l) / 2;
        // to build balanced tree we need to choose the middle element as the root 
        TreeNode temp = new TreeNode(a[m]);                                         
        // recursively create subtree and add it as left child
        temp.left_ptr = build_balanced_bst_helper(l, m - 1, a);                     
        // recursively create subtree and add it as right child 
        temp.right_ptr = build_balanced_bst_helper(m + 1, r, a);                        
        return temp;
    }

    static TreeNode build_balanced_bst(int[] a) 
    {
        int N = a.length;
        // build balanced BST
        return build_balanced_bst_helper(0, N - 1, a);                                  
    }

    //-----------------------------------STOP----------------------------------------



    static boolean check_balanced_bst(TreeNode root, int l, int r, int[] a)
    {
        // If no value in [l, r] and tree is also empty.
        if (l > r && root == null)                              
        {
            return true;
        }
        // If no value in [l, r] but tree contains something. 
        else if (l > r && root != null)                         
        {
            return false;
        }
        // If some values in [l, r] but tree is empty.
        if (root == null)                                       
        {
            return false;
        }

        int mid1 = l + (r - l) / 2;
        int mid2 = l + (r - l + 1) / 2;

        boolean valid1 = (root.val == a[mid1] && check_balanced_bst(root.left_ptr, l, mid1 - 1, a)
            && check_balanced_bst(root.right_ptr, mid1 + 1, r, a));
        /*
        actually we are doing valid1 || valid2 but when valid1 is true then no need to find valid2
        */
        if (valid1)                                             
        {
            return true;        
        }
        /*
        when odd no of elements in [l, r] then mid1 = mid2 so valid1 = valid2 and no need to find 
        valid2. 
        */ 
        if (mid1 == mid2)                                       
        {
            return false;        
        }
        return (root.val == a[mid2] && check_balanced_bst(root.left_ptr, l, mid2 - 1, a) && 
            check_balanced_bst(root.right_ptr, mid2 + 1, r, a));  
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

        int a_size = 0;
        a_size = Integer.parseInt(in.nextLine().trim());

        int[] a = new int[a_size];
        for(int i = 0; i < a_size; i++) {
            int a_item;
            a_item = Integer.parseInt(in.nextLine().trim());
            a[i] = a_item;
        }

        TreeNode root = build_balanced_bst(a);
        
        if (check_balanced_bst(root, 0, a_size - 1, a))
        {
            bw.write("Valid Balanced BST");
        }
        else
        {
            bw.write("Invalid Balanced BST");
        }
        bw.newLine();

        bw.close();
    }
}