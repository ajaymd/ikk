process.stdin.resume();
process.stdin.setEncoding('utf-8');

var __input_stdin = "";
var __input_stdin_array = "";
var __input_currentline = 0;

process.stdin.on('data', function(data) {
    __input_stdin += data;
});
function LinkedListNode(node_value) {
    this.val = node_value;
    this.next = null;
}

function _insert_node_into_singlylinkedlist(head, tail, val) {
    if(head == null) {
        head = new LinkedListNode(val);
        tail = head;
    }
    else {
        var node = new LinkedListNode(val);
        tail.next = node;
        tail = tail.next;
    }
    return tail;
}

/*
    ----START----
*/

function find_first_big(ptr)
{
    if (ptr.val < ptr.next.val)
    {
        return ptr.next;
    }
    var cur = ptr.next;
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

function is_non_decreasing(head)
{
    var cur = head;
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

function find_first_small(ptr)
{
    if (ptr.val > ptr.next.val)
    {
        return ptr.next;
    }
    var cur = ptr.next;
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
function find_size(ptr)                                                  
{
    var N = 1;
    var cur = ptr.next;
    while (cur != ptr)
    {
        N++;
        cur = cur.next;
    }
    return N;
}

function find_median(ptr) 
{
    /*
        Linked list will be one of these 3 types
        1) (2 . 2 . 2 . 2 . 2 . 2)
        2) (2 . 2 . 4 . 6 . 8 . 8)
        3) (8 . 8 . 4 . 6 . 2 . 2)

        Now first case is trivial.

        In 2nd case if we can find first smallest element (call it head) then finding median will 
        be trivial. Just find middle element/elements.
        // (2 . 2 . 4 . 6 . 8 . 8) then head will be ([2]head . 2 . 4 . 6 . 8 . 8)

        In 3rd case if we can find first largest element (call it head) then finding median will 
        be trivial. Just find middle element/elements.
        // (8 . 8 . 4 . 6 . 2 . 2) then head will be ([8]head . 8 . 4 . 6 . 2 . 2)

    */

    var N = find_size(ptr);
    /*
    We do not know if given linked list is non-increasing or non-decreasing. If it is 
    non_decreasing (2.4.6.8) then there will be <= 1 pair big.small (8.2). If it is non_increasing
    (8.6.4.2) then there will be many pair big.small (8.6, 6.4, 4.2). When both non-increasing and
    non-decreasing (2.2.2) then there will be no small.big. This function returns pointer to 
    small. For non-decreasing case it will be unique. For (2 . 2 . 2) it will be NULL. For 
    non-increasing it will be any one of the valid pairs. 
    */
    var first_small = find_first_small(ptr);                                    

    // When all elements are same (2.2.2) then return any element.
    if (first_small == null)                                                    
    {
        return ptr.val;
    }

    var head = null;
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
    for (var i = 0; i < Math.floor((N - 1) / 2); i++)                           
    {
        head = head.next;
    }
    if ((N % 2) == 1)
    {
        return head.val;
    }
    return ((head.val + head.next.val) / 2);  
}

/*
    ----STOP----
*/

var fs = require('fs');
var wstream = fs.createWriteStream(process.env.OUTPUT_PATH);

process.stdin.on('end', function() {
    __input_stdin_array = __input_stdin.split("\n");
    var ptr;
    var ptr_size = 0;

    ptr_size = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
    __input_currentline += 1;

    var ptr_i, ptr_item;
    var ptr = null;
    var ptr_tail = null;
    for(ptr_i = 0; ptr_i < ptr_size; ptr_i++) {
        var ptr_item = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
        __input_currentline += 1;

        ptr_tail = _insert_node_into_singlylinkedlist(ptr, ptr_tail, ptr_item);
        if(ptr_i == 0) {
            ptr = ptr_tail;
        }
    }

    //----added manually----
    // Till now it was linear, now join tail to head and make it circular. 
    ptr_tail.next = ptr;                                                            
    /*
    Now we have got circular linked list but ptr will be the first element, but we need to give 
    arbitrary node. 
    */
    // Value of arbitrary_shift will be [0, ptr_size). 
    var arbitrary_shift = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
    __input_currentline += 1;
    while (arbitrary_shift > 0)
    {
        arbitrary_shift -= 1;
        ptr = ptr.next;
    }
    //--------

    res = find_median(ptr);
    wstream.write(res + "\n");

    wstream.end();
});
