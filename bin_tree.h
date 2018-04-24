#pragma once
#include <stddef.h>

typedef char TreeNodeType;

//用孩子表示法表示一棵树
typedef struct TreeNode{
    TreeNodeType data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
} TreeNode;

//初始化
void TreeInit(TreeNode** proot);
//先序遍历
void TreePreOrder(TreeNode* root);
//中序遍历
void TreeInOrder(TreeNode* root);
//后序遍历
void TreePostOrder(TreeNode* root);
//层序遍历
void TreeLevelOrder(TreeNode* root);
//创建一棵树
TreeNode* TreeCreate(TreeNodeType data[],size_t size,char null_node);
TreeNode* CreatTreeNode(TreeNodeType value);
//树的拷贝
TreeNode* TreeClone(TreeNode* root)
