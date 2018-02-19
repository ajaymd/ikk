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

    static LinkedListNode find_first_big(LinkedListNode ptr)
    {
        if (ptr.val < ptr.next.val)
        {
            return ptr.next;
        }
        LinkedListNode cur = ptr.next;
        while (cur != ptr)
        {
            if (cur.val < cur.next.val)
            {
                return cur.next;
            }
            cur = cur.next;
        }
        return null;
    }

    static boolean is_non_decreasing(LinkedListNode head)
    {
        LinkedListNode cur = head;
        while (cur.next != head)
        {
            if (cur.val > cur.next.val)
            {
                return false;
            }
            cur = cur.next;
        }
        return true;
    }

    static LinkedListNode find_first_small(LinkedListNode ptr)
    {
        if (ptr.val > ptr.next.val)
        {
            return ptr.next;
        }
        LinkedListNode cur = ptr.next;
        while (cur != ptr)
        {
            if (cur.val > cur.next.val)
            {
                return cur.next;
            }
            cur = cur.next;
        }
        return null;
    }

    // Finds size of the linked list
    static int find_size(LinkedListNode ptr)                                                  
    {
        int N = 1;
        LinkedListNode cur = ptr.next;
        while (cur != ptr)
        {
            N++;
            cur = cur.next;
        }
        return N;
    }

    static int find_median(LinkedListNode ptr) 
    {
        /*
            Linked list will be one of these 3 types
            1) (2 . 2 . 2 . 2 . 2 . 2)
            2) (2 . 2 . 4 . 6 . 8 . 8)
            3) (8 . 8 . 4 . 6 . 2 . 2)

            Now first case is trivial.

            In 2nd case if we can find first smallest element (call it head) then finding median 
            will be trivial. Just find middle element/elements.
            // (2 . 2 . 4 . 6 . 8 . 8) then head will be ([2]head . 2 . 4 . 6 . 8 . 8)
        
            In 3rd case if we can find first largest element (call it head) then finding median 
            will be trivial. Just find middle element/elements.
            // (8 . 8 . 4 . 6 . 2 . 2) then head will be ([8]head . 8 . 4 . 6 . 2 . 2)

        */

        int N = find_size(ptr);
        /*
        We do not know if given linked list is non-increasing or non-decreasing. If it is 
        non_decreasing (2.4.6.8) then there will be <= 1 pair big.small (8.2). If it is 
        non_increasing (8.6.4.2) then there will be many pair big.small (8.6, 6.4, 4.2). When both
        non-increasing and non-decreasing (2.2.2) then there will be no small.big. This function 
        returns pointer to small. For non-decreasing case it will be unique. For (2 . 2 . 2) it 
        will be NULL. For non-increasing it will be any one of the valid pairs. 
        */
        LinkedListNode first_small = find_first_small(ptr);                        

        // When all elements are same (2.2.2) then return any element.
        if (first_small == null)                                                    
        {
            return ptr.val;
        }

        LinkedListNode head = null;
        /*
        Take pointer to small that we got previously, as head and check if linked list is 
        non-decreasing or not.
        */
        if (is_non_decreasing(first_small))                                         
        {
            // If it is non-decreasing then we have found our head
            head = first_small;                                                     
        }
        else
        {   
            // Non-increasing                                                                        
            head = find_first_big(ptr);
        }

        // Till now we have found our head.     
        // Exact middle element in case of odd N and middle left element in case of even N.
        for (int i = 0; i < (N - 1) / 2; i++)                                      
        {
            head = head.next;
        }
        if (N % 2 == 1)
        {
            return head.val;
        }
        // take care of overflow
        return (int)(((long)head.val + (long)head.next.val) / (long)2);             
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
        int ptr_size = 0;

        LinkedListNode ptr = null;
        LinkedListNode ptr_tail = null;

        ptr_size = Integer.parseInt(in.nextLine());

        for(int i = 0; i < ptr_size; i++) {
            int ptr_item;
            ptr_item = Integer.parseInt(in.nextLine().trim());
            ptr_tail = _insert_node_into_singlylinkedlist(ptr, ptr_tail, ptr_item);

            if(i == 0) {
                ptr = ptr_tail;
            }
        }

        //----added manually----
        // Till now it was linear, now join tail to head and make it circular. 
        ptr_tail.next = ptr;                                                            
        /*
        Now we have got circular linked list but ptr will be the first element, but we need to 
        give arbitrary node. 
        */
        // Value of arbitrary_shift will be [0, ptr_size). 
        int arbitrary_shift = Integer.parseInt(in.nextLine());
        while (arbitrary_shift > 0)
        {
            arbitrary_shift -= 1;
            ptr = ptr.next;
        }
        //--------

        res = find_median(ptr);
        bw.write(String.valueOf(res));
        bw.newLine();

        bw.close();
    }
}
