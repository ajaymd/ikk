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

    static TreeNode bst_insert(TreeNode root, int val)
    {
        if (root == null)												// destination.
        {
            return new TreeNode(val);
        }
        if (val <= root.val)											// element is <= hence insert it in left subtree.
        {
            root.left_ptr = bst_insert(root.left_ptr, val);			      // if root.left_ptr is null then new TreeNode will be created and root.left_ptr is assigned, else it will be assigned to the same value as previouly stored.
        }
        else  															// element is > hence insert it in right subtree.
        {
            root.right_ptr = bst_insert(root.right_ptr, val);			// if root.right_ptr is null then new TreeNode will be created and root.right_ptr is assigned, else it will be assigned to the same value as previouly stored.
        }
        return root;
    }

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

    //-------------------------------START-----------------------------------

    static int kth_element;                                                 // kth smallest element is stored in this variable. 
    //int counter = 0;                                                  // when running more than one testcases then dont use static in counter = 0 use this and initialize counter = 0 at the beginning of each testcase. 

    static int counter = 0;

    static void get_k_th_element(TreeNode root, int k)
    {
        /*
            this function uses the idea of inorder_traversal. 
        */
        
        if (root == null || counter >= k)                               // either root is null or we have already found the answer.             
        {
            return;
        }
        get_k_th_element(root.left_ptr, k);                             // first try to find from left subtree, because elements in left suubtree will be smaller than the root.
        if (counter < k)                                                // if we have not found the answer till now.        
        {
            counter++;
            if (counter == k)                                           // if current node is the kth node.
            {
                kth_element = root.val;
                return;
            }
            get_k_th_element(root.right_ptr, k);                        // we have explored left subtree and the root now explore right subtree. 
        }
    }

    static int kth_smallest_element(TreeNode root, int k)
    {
        get_k_th_element(root, k);                                      // find kth smallest element
        return kth_element;
    }

    //-------------------------------------STOP---------------------------------

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

        int N = Integer.parseInt(in.nextLine().trim());

        TreeNode root = null;

        for (int i = 0; i < N; i++)
        {
            int data = Integer.parseInt(in.nextLine().trim());
            root = bst_insert(root, data);
        }

        int k= Integer.parseInt(in.nextLine().trim());

        int ans = kth_smallest_element(root, k);
        
        bw.write(String.valueOf(ans));
        bw.newLine();

        bw.close();
    }
}
