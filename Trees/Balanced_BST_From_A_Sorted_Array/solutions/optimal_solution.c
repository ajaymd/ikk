#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct TreeNode TreeNode;

struct TreeNode
{
    int val;
    TreeNode* left_ptr;
    TreeNode* right_ptr;
};



//-----------------------------------START----------------------------------------

/*
 * Complete the function below.
 */

/*
    For your reference. 

    struct TreeNode
    {
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;
    };
*/

TreeNode * build_balanced_bst_helper(int l, int r, int* a)          // build tree using values (a[l], a[l+1], ..., a[r]).
{
    if (l > r)  
    {
        return NULL;
    }
    int m = l + (r - l) / 2;
    TreeNode *temp = (TreeNode *) malloc(sizeof(TreeNode));
    temp->val = a[m];                                               // to build balanced tree we need to choose the middle element as the root 
    temp->left_ptr = NULL;
    temp->right_ptr = NULL;
    temp->left_ptr = build_balanced_bst_helper(l, m - 1, a);        // recursively create subtree and add it as left child
    temp->right_ptr = build_balanced_bst_helper(m + 1, r, a);       // recursively create subtree and add it as right child 
    return temp;
}

TreeNode * build_balanced_bst(int a_size, int* a)
{
    return build_balanced_bst_helper(0, a_size - 1, a);             // build balanced BST
}

//-----------------------------------STOP----------------------------------------



bool check_balanced_bst(TreeNode *root, int l, int r, int* a)
{
    if (l > r && root == NULL)                              // If no value in [l, r] and tree is also empty.
    {
        return true;
    }
    else if (l > r && root != NULL)                         // If no value in [l, r] but tree contains something. 
    {
        return false;
    }
    if (root == NULL)                                       // If some values in [l, r] but tree is empty.
    {
        return false;
    }
    
    int mid1 = l + (r - l) / 2;
    int mid2 = l + (r - l + 1) / 2;
    
    bool valid1 = (root->val == a[mid1] && check_balanced_bst(root->left_ptr, l, mid1 - 1, a) && check_balanced_bst(root->right_ptr, mid1 + 1, r, a));
    if (valid1)                                             // actually we are doing valid1 || valid2 but when valid1 is true then no need to find valid2
    {
        return true;        
    }
    if (mid1 == mid2)                                       // when odd no of elements in [l, r] then mid1 = mid2 so valid1 = valid2 and no need to find valid2.  
    {
        return false;        
    }
    return (root->val == a[mid2] && check_balanced_bst(root->left_ptr, l, mid2 - 1, a) && check_balanced_bst(root->right_ptr, mid2 + 1, r, a));  
}

int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    int a_size = 0;
    scanf("%d\n", &a_size);

    int a[a_size];
    for(int i = 0; i < a_size; i++) {
        int a_item;
        scanf("%d", &a_item);
        a[i] = a_item;
    }

    TreeNode* root = build_balanced_bst(a_size, a);
    
    if (check_balanced_bst(root, 0, a_size - 1, a))
    {
        fprintf(f, "Valid Balanced BST\n");
    }
    else
    {
        fprintf(f, "Invalid Balanced BST\n");
    }
    
    fclose(f);
    return 0;
}
