#include <stdio.h>
#include <malloc.h>
#include "bin_tree.h"
#include "seqqueue.h"

//初始化
void TreeInit(TreeNode** proot)
{
    if(proot == NULL)
    {
        //非法输入
        return;
    }
    *proot=NULL;
    return ;
}

//先序遍历
void TreePreOrder(TreeNode* root)
{
    if(root==NULL)
    {
        //
        return;
    }
    printf("%c",root->data);
    //
    TreePreOrder(root->lchild);
    //
    TreePreOrder(root->rchild);
    return;
}
//中序遍历
void TreeInOrder(TreeNode* root)
{
    if(root==NULL)
    {
        //
        return;
    }
    //
    TreePreOrder(root->lchild);
    printf("%c",root->data);
    //
    TreePreOrder(root->rchild);
    return;
}
//后序遍历
void TreePostOrder(TreeNode* root)
{
    if(root==NULL)
    {
        //非法输入
        return;
    }
    //递归访问左子树
    TreePreOrder(root->lchild);
    //递归访问右子树
    TreePreOrder(root->rchild);
    printf("%c",root->data);
    return;
}

//层序遍历
void TreeLevelOrder(TreeNode* root)
{
    if(root==NULL)
    {//空树
        return ;
    }
    //1.根节点入队列
    SeqQueue queue;
    SeqQueueInit(&queue);
    SeqQueuePush(&queue,root);
    //2.循环取队首元素
    while(1)
    {
        SeqQueueType front;
        int ret=SeqQueueTop(&queue,&front);
        if(ret==0)
        {
            break;
        }
        //3.打印当前值
        printf("%c",front->data);
        //
        SeqQueuePop(&queue);
        //左右子树入
        if(front->lchild!=NULL)
        {
            SeqQueuePush(&queue,front->lchild);
        }
        if(front->rchild!=NULL)
        {
            SeqQueuePush(&queue,front->rchild);
        }
    }
    printf("\n");
    return;
}

TreeNode* _TreeCreate(TreeNodeType data[],size_t size,size_t* index,TreeNodeType null_node)
{
    if(index==NULL)
    {
        //非法输入
        return NULL;
    }
    if(data[*index]==null_node)
    {
        //遇到空节点
        return NULL;
    }
    TreeNode* new_node=CreatTreeNode(data[*index]);
    ++(*index);//取下一个节点
    new_node->lchild=_TreeCreate(data,size,index,null_node);
    ++(*index);
    //创建右子树
    new_node->rchild=_TreeCreate(data,size,index,null_node);
    return new_node;
}
//创建一棵树
TreeNode* TreeCreate(TreeNodeType data[],size_t size,char null_node)
{
    //表示当前取数组中的哪个元素
    size_t index=0;
    return _TreeCreate(data,size,&index,null_node);
}

//树的拷贝
TreeNode* TreeClone(TreeNode* root)
{
    if(root==NULL)
    {
        //空树
        return NULL;
    }
    //按照先序遍历来遍历
    TreeNode* new_node=CreatTreeNode(root->data);
    new_node->lchild=TreeClone(root->lchild);
    new_node->rchild=TreeClone(root->rchild);
    return new_node;
}


////////////////////////////////////////////////////////////////
//测试代码
///////////////////////////////////////////////////////////////

TreeNode* CreatTreeNode(TreeNodeType value)
{
    TreeNode* new_node=(TreeNode*)malloc(sizeof(TreeNode));
    new_node->data=value;
    new_node->lchild=NULL;
    new_node->rchild=NULL;
    return new_node;
}

void DestroyTreeNode(TreeNode* node)
{
    free(node);
    node=NULL;
}

void TestInit()
{
    printf("====================== %s ==================\n",__FUNCTION__);
    TreeNode* root;
    TreeInit(&root);
    printf("root指针期望是NULL，实际是：%p\n",root);
}

void TestOrder()
{
    printf("===================== %s ===================\n",__FUNCTION__);
    TreeNode* a=CreatTreeNode('a');
    TreeNode* b=CreatTreeNode('b');
    TreeNode* c=CreatTreeNode('c');
    TreeNode* d=CreatTreeNode('d');
    TreeNode* e=CreatTreeNode('e');
    TreeNode* f=CreatTreeNode('f');
    TreeNode* g=CreatTreeNode('g');
    
    a->lchild=b;
    a->rchild=c;
    b->lchild=d;
    b->rchild=e;
    e->lchild=g;
    c->rchild=f;

    printf("============ preorder =========\n");
    TreePreOrder(a);
    printf("\n");
    printf("============ inorder =========\n");
    TreeInOrder(a);
    printf("\n");
    printf("============ postorder =========\n");
    TreePostOrder(a);
    printf("\n");
}
void Test()
{
    printf("===================== %s ===================\n",__FUNCTION__);
    TreeNode* a=CreatTreeNode('a');
    TreeNode* b=CreatTreeNode('b');
    TreeNode* c=CreatTreeNode('c');
    TreeNode* d=CreatTreeNode('d');
    TreeNode* e=CreatTreeNode('e');
    TreeNode* f=CreatTreeNode('f');
    TreeNode* g=CreatTreeNode('g');
    
    a->lchild=b;
    a->rchild=c;
    b->lchild=d;
    b->rchild=e;
    e->lchild=g;
    c->rchild=f;

    printf("============ levelorder =========\n");
    TreeLevelOrder(a);
    printf("\n");
}
void main()
{
    TestInit();
    TestOrder();
    Test();
}
