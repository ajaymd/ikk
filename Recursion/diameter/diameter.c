/******************************************************************************
 *
 *  Write a function that returns the diameter of a tree
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX(l, r)    ((l) > (r) ? (l) : (r))

typedef struct TreeNode {
    int distance_from_father;
    struct TreeNode **sons;
} TreeNode;

int diameterRecursion(TreeNode *tree, int *max_distance_to_father) {
    if (tree->sons == NULL) {
        *max_distance_to_father = tree->distance_from_father; 
        return 0;
    }

    int d = -1;
    int total_max_distance, total_2nd_max_distance;
    total_max_distance = total_2nd_max_distance = 0;
    for(TreeNode **son = tree->sons; *son != NULL; ++son) {
        int max_distance;
        int d_son = diameterRecursion(*son, &max_distance);
        if (max_distance > total_max_distance) {
            total_2nd_max_distance = total_max_distance;
            total_max_distance = max_distance;
        } else if (max_distance > total_2nd_max_distance) {
            total_2nd_max_distance = max_distance;
        }
        d = MAX(d, d_son);
    }

    *max_distance_to_father = total_max_distance + tree->distance_from_father;
    return MAX(d, total_max_distance + total_2nd_max_distance);
}

int diameter(TreeNode *tree) {
    if (tree == NULL)
        return -1;

    int md;
    return diameterRecursion(tree, &md);
}
        

typedef struct {
    char *tree;
    int diameter;
} TestCase;

int readNumber(const char **p) {
    int d = 0;
    while(isdigit(**p)) {
        d *= 10;
        d += **p - '0';
        ++(*p);
    }
    return d;
}

TreeNode *buildTreeRecursion(const char **p) {
    ++(*p); // **p == '{'
    TreeNode *node = malloc(sizeof(TreeNode));
    node->distance_from_father = readNumber(p);
    ++(*p);
    int number_of_sons = readNumber(p);
    ++(*p);
    if (number_of_sons == 0) {
        node->sons = NULL;
        return node;
    }
    node->sons = malloc((number_of_sons + 1) * sizeof(TreeNode*));
    node->sons[number_of_sons] = NULL;
    for(int i = 0; i < number_of_sons; i++) {
        node->sons[i] = buildTreeRecursion(p);
        if (**p == ',')
        ++(*p);
    }
    ++(*p);
    return node;
}

TreeNode *buildTree(const char *tree_string) {
    const char *p = tree_string;
    return buildTreeRecursion(&p);
}

void freeTree(TreeNode *tree) {
    if (tree->sons != NULL) {
        for(TreeNode **son = tree->sons; *son != NULL; ++son)
            freeTree(*son);
        free(tree->sons);
    }
    free(tree);
}
    

TestCase tests[] = {
    // One node - no diameter
    {"{0,0}", 0}, 
    // One leaf - no diameter
    {"{0,1,{5,0}}", 5},
    // Still one leaf - no diameter
    {"{0,1,{5,1,{4,1,{7,0}}}}", 16},
    // The diameter of the first son is the diameter of the tree
    {"{0,1,{5,2,{8,0},{7,0}}}", 15},
    // The diameter of the last son is the diameter of the tree
    {"{0,3,{1,2,{5,0},{7,0}},{1,2,{6,0},{5,0}},{1,2,{10,0},{9,0}}}", 19},
    // Now the diameter is between a leaf in the first son and a leaf in the third son
    {"{0,3,{5,2,{8,0},{7,0}},{5,2,{9,0},{8,0}},{5,2,{10,0},{9,0}}}", 29},
};  

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

void test() {
    int result;
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        printf("-------\n");
        TreeNode *tree = buildTree(tests[i].tree);
        result = diameter(tree);
        if (result != tests[i].diameter) {
            printf("Error: diameter of test case number %d is %d. Got %d instead\n",
                i, tests[i].diameter, result);
            errors++;
        } 
    }

    if (errors)
        printf("Got %d errors\n", errors);
    else
        printf("Good work\n");
}

int main() {
    test();
    return 0;
} 

  
