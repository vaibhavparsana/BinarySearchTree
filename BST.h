
   
typedef struct{
    double num;
} NodeData;

typedef struct treenode {
    NodeData data;  // struct inside a struct
    struct treenode* left;
    struct treenode* right;
} TreeNode;

typedef struct {
    TreeNode* root;  // Root of the tree
} BinaryTree;

// Function prototypes

TreeNode* newTreeNode(NodeData dat);
TreeNode* rootInsert(double arr[], int start, int end) ;
TreeNode* search(TreeNode* root, double num);
void inOrder(TreeNode* node);


