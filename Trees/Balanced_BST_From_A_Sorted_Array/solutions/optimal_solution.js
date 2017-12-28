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



//-----------------------------------START----------------------------------------


/*
 * Complete the function below.
 */

/*
    For your reference:
    
    function TreeNode(node_value) 
    {
        this.val = node_value;
        this.left_ptr = null;
        this.right_ptr = null;
    }
*/

function build_balanced_bst_helper(l, r, a)                    // build tree using values (a[l], a[l+1], ..., a[r]).
{
    if (l > r)  
    {
        return null;
    }
    var m = l + (r - l + 1) / 2;
    var temp = new TreeNode(a[m]);                                         // to build balanced tree we need to choose the middle element as the root 
    temp.left_ptr = build_balanced_bst_helper(l, m - 1, a);                     // recursively create subtree and add it as left child
    temp.right_ptr = build_balanced_bst_helper(m + 1, r, a);                        // recursively create subtree and add it as right child 
    return temp;
}

function build_balanced_bst(a) 
{
    var N = a.length;
    return build_balanced_bst_helper(0, N - 1, a);                                  // build balanced BST
}

//-----------------------------------STOP----------------------------------------



function check_balanced_bst(root, l, r, a)
{
    if (l > r && root == null)                              // If no value in [l, r] and tree is also empty.
    {
        return true;
    }
    else if (l > r && root != null)                         // If no value in [l, r] but tree contains something. 
    {
        return false;
    }
    if (root == null)                                       // If some values in [l, r] but tree is empty.
    {
        return false;
    }

    var mid1 = l + (r - l) / 2;
    var mid2 = l + (r - l + 1) / 2;

    var valid1 = (root.val == a[mid1] && check_balanced_bst(root.left_ptr, l, mid1 - 1, a) && check_balanced_bst(root.right_ptr, mid1 + 1, r, a));
    if (valid1)                                             // actually we are doing valid1 || valid2 but when valid1 is true then no need to find valid2
    {
        return true;        
    }
    if (mid1 == mid2)                                       // when odd no of elements in [l, r] then mid1 = mid2 so valid1 = valid2 and no need to find valid2.  
    {
        return false;        
    }
    return (root.val == a[mid2] && check_balanced_bst(root.left_ptr, l, mid2 - 1, a) && check_balanced_bst(root.right_ptr, mid2 + 1, r, a));  
}

var fs = require('fs');
var wstream = fs.createWriteStream(process.env.OUTPUT_PATH);

process.stdin.on('end', function() {
    __input_stdin_array = __input_stdin.split("\n");
    var a_size = 0;
    a_size = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
    __input_currentline += 1;

    var a = [];
    var a_item;
    for (var a_i = 0; a_i < a_size; a_i++) {
        var a_item = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
        __input_currentline += 1;
        a.push(a_item);
    }

    var root = build_balanced_bst(a);
    
    if (check_balanced_bst(root, 0, a_size - 1, a))
    {
        wstream.write("Valid Balanced BST\n");
    }
    else
    {
        wstream.write("Invalid Balanced BST\n");
    }
    
    wstream.end();
});