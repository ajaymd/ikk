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

function get_size(head)
{
    var N = 0;
    while (head != null)
    {
        N++;
        head = head.next;
    }
    return N;
}

function find_intersection(l1, l2)
{
    // Size of first linked list.
    var N1 = get_size(l1);                                  	
    // Size of second linked list.
    var N2 = get_size(l2);                                  	
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

var fs = require('fs');
var wstream = fs.createWriteStream(process.env.OUTPUT_PATH);

process.stdin.on('end', function() {
    __input_stdin_array = __input_stdin.split("\n");
    var l1;
    var l1_size = 0;

    l1_size = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
    __input_currentline += 1;

    var l1_i, l1_item;
    var l1 = null;
    var l1_tail = null;
    for(l1_i = 0; l1_i < l1_size; l1_i++) {
        var l1_item = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
        __input_currentline += 1;

        l1_tail = _insert_node_into_singlylinkedlist(l1, l1_tail, l1_item);
        if(l1_i == 0) {
            l1 = l1_tail;
        }
    }


    var l2;
    var l2_size = 0;

    l2_size = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
    __input_currentline += 1;

    var l2_i, l2_item;
    var l2 = null;
    var l2_tail = null;
    for(l2_i = 0; l2_i < l2_size; l2_i++) {
        var l2_item = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
        __input_currentline += 1;

        l2_tail = _insert_node_into_singlylinkedlist(l2, l2_tail, l2_item);
        if(l2_i == 0) {
            l2 = l2_tail;
        }
    }

    //----added manually----
    merge_at = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
    __input_currentline += 1;
    var l1_temp = l1;
    for (var i = 0; i < merge_at; i++)
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
    wstream.write(res + "\n");

    wstream.end();
});
