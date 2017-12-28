process.stdin.resume();
process.stdin.setEncoding('utf-8');

var __input_stdin = "";
var __input_stdin_array = "";
var __input_currentline = 0;

process.stdin.on('data', function(data) {
    __input_stdin += data;
});

function TreeNode(node_value) {
    this.val = node_value;
    this.left_ptr = null;
    this.right_ptr = null;
}

function bst_insert(root, val)
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
    
    function TreeNode(node_value) 
    {
        this.val = node_value;
        this.left_ptr = null;
        this.right_ptr = null;
    }
*/

//-------------------------------START-----------------------------------

var kth_element;                                                 // kth smallest element is stored in this variable. 
//int counter = 0;                                                  // when running more than one testcases then dont use static in counter = 0 use this and initialize counter = 0 at the beginning of each testcase. 

var counter = 0;

function get_k_th_element(root, k)
{
    /*
        this function uses the idea of inorder_traversal. 
    */

    if (root == null || counter >= k)                               // either root is null or we have already found the answer.             
    {
        return;
    }
    get_k_th_element(root.left_ptr, k);                         // first try to find from left subtree, because elements in left suubtree will be smaller than the root.
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

function kth_smallest_element(root, k)
{
    get_k_th_element(root, k);                                      // find kth smallest element
    return kth_element;
}

//-------------------------------------STOP---------------------------------

var fs = require('fs');
var wstream = fs.createWriteStream(process.env.OUTPUT_PATH);

process.stdin.on('end', function() {
    __input_stdin_array = __input_stdin.split("\n");
    
    var N = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
    __input_currentline += 1;

    var root = null;

    for (var i = 0; i < N; i++)
    {
        var data = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
        __input_currentline += 1;
        root = bst_insert(root, data);
    }
    
    var k;
    var k = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
    __input_currentline += 1;


    ans = kth_smallest_element(root, k);
    wstream.write(ans + "\n");

    wstream.end();
});
