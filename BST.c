#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"


   
// Create a new tree node using malloc. Returns a pointer to the new node.
TreeNode* newTreeNode(NodeData dat) {
    TreeNode* p = (TreeNode*) malloc(sizeof(TreeNode));
    p->data = dat;  // Copies the node data
    p->left = p->right = NULL;
    return p;
}

TreeNode* rootInsert(double arr[], int start, int end) {
	NodeData node; 
	if (start > end) 
      return NULL; // return null if empty list
      
    int middle = (start + end) / 2; //pick the middle number
    node.num = arr[middle]; // setting its value to node
    TreeNode* root = newTreeNode(node); // creating a new node
    
    root->right = rootInsert(arr,start,middle-1);
    root->left = rootInsert(arr,middle+1,end);
    
    return root; // returns root of entire tree 
}


// Searches the tree for 'str'. Returns NULL if not found.
// This prints out a line for each step in the search. For a well-balanced
// tree we can expect the number of steps to be about log2(n) or less.
TreeNode* search(TreeNode* root, double num) {
    if (root == NULL)   // Termination check (base case)
        return NULL;
    printf("Search took a step\n");
	if (num == root->data.num)       // Item was found!
	    return root;
	else if (num < root->data.num)   // Should we go left?
	    return search(root->left, num);
	else                // Go right
	    return search(root->right, num);
        
}

// Prints the entire tree using in-order traversal.
void inOrder(TreeNode* node) {
    if (node != NULL) {
        inOrder(node->left);
        printf("%lf ", node->data.num);
        inOrder(node->right);
    }
}

