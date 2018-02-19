import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static class LinkedListNode {
        int val;
        LinkedListNode next;

        LinkedListNode(int node_value) {
            val = node_value;
            next = null;
        }
    };

    public static LinkedListNode _insert_node_into_singlylinkedlist(LinkedListNode head, 
        LinkedListNode tail, int val) {
        if(head == null) {
            head = new LinkedListNode(val);
            tail = head;
        }
        else {
            tail.next = new LinkedListNode(val);
            tail = tail.next;
        }
        return tail;
    }

    /*
        ----START----
    */

    static int get_size(LinkedListNode head)
    {
        int N = 0;
        while (head != null)
        {
            N++;
            head = head.next;
        }
        return N;
    }

    static int find_intersection(LinkedListNode l1, LinkedListNode l2)
    {
        // Size of first linked list.
        int N1 = get_size(l1);                                  	
        // Size of second linked list.
        int N2 = get_size(l2);                                  	
        while (N1 > N2)                                     
        {
            l1 = l1.next;
            N1--;
        }
        while (N2 > N1)                                     
        {
            l2 = l2.next;
            N2--;
        }
        // Comparing address.
        while (l1 != null && l1 != l2)                              
        {
            l1 = l1.next;
            l2 = l2.next;
        }
        // If we have reached end.
        if (l1 == null)                                             
        {
            return -1;
        }
        // Intersection at node pointed by current value of l1.
        return l1.val;                                          	
    }

    /*
        ----STOP----
    */

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
        int l1_size = 0;

        LinkedListNode l1 = null;
        LinkedListNode l1_tail = null;

        l1_size = Integer.parseInt(in.nextLine());

        for(int i = 0; i < l1_size; i++) {
            int l1_item;
            l1_item = Integer.parseInt(in.nextLine().trim());
            l1_tail = _insert_node_into_singlylinkedlist(l1, l1_tail, l1_item);

            if(i == 0) {
                l1 = l1_tail;
            }
        }


        int l2_size = 0;

        LinkedListNode l2 = null;
        LinkedListNode l2_tail = null;

        l2_size = Integer.parseInt(in.nextLine());

        for(int i = 0; i < l2_size; i++) {
            int l2_item;
            l2_item = Integer.parseInt(in.nextLine().trim());
            l2_tail = _insert_node_into_singlylinkedlist(l2, l2_tail, l2_item);

            if(i == 0) {
                l2 = l2_tail;
            }
        }

        //----added manually----
        int merge_at = Integer.parseInt(in.nextLine());
        LinkedListNode l1_temp = l1;
        for (int i = 0; i < merge_at; i++)
        {
            l1_temp = l1_temp.next;        
        }
        if (l2_tail == null)
        {
            l2 = l1_temp;
        }
        else
        {
            l2_tail.next = l1_temp;     
        }
        //--------
        
        res = find_intersection(l1, l2);
        bw.write(String.valueOf(res));
        bw.newLine();

        bw.close();
    }
}
