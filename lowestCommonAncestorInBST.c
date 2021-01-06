#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *newNode(int data)
{
    TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
    new->val = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
TreeNode *findLCAInBST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if ((root->val > p->val) && (root->val > q->val))
    {
        return findLCAInBST(root->left, p, q);
    }
    else if ((root->val < p->val) && (root->val < q->val))
    {
        return findLCAInBST(root->right, p, q);
    }
    else
    {
        return root;
    }
}

int main()
{
    TreeNode *root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(7);
    root->left->left = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(10);

    TreeNode *lca = findLCAInBST(root, root->left, root->right);
    printf("Val of LCA Node is %d\n", lca->val);

    return 0;
}
