#include<iostream>
#include"Headers/BinaryTree.h"
#include"Headers/Queue.h"
using namespace std;
TNode* create_node(int val)
{
    TNode* a=new TNode;
    a->data=val;
    return a;
}
TNode* BinaryTree::create(int val)
{
    root=create_node(val);
    return root;
}
TNode* BinaryTree::get_root()
{
    return root;
}
void Inorder(TNode*a)
{
    if(a!=NULL)
    {
        Inorder(a->left);
        cout<<a->data<<" ";
        Inorder(a->right);
    }
}
void Preorder(TNode*a)
{
    if(a!=NULL)
    {
        cout<<a->data<<" ";
        Preorder(a->left);
        Preorder(a->right);
    }
}
void Postorder(TNode*a)
{
    if(a!=NULL)
    {
        Postorder(a->left);
        Postorder(a->right);
        cout<<a->data<<" ";
    }
}
int height(TNode*a)
{
    if(a==NULL)
    {
        return 0;
    }
    else
    {
        int l= height(a->left);
        int r= height(a->right);
        if(l<r)
        {
            return r+1;
        }
        else
        {
            return l+1;
        }
    }
}
void print_row(TNode*a,int i){
    if(a==NULL){
        return;
    }
    if(i==1){
      cout<<a->data<<" ";
    }else{
        print_row(a->left,i-1);
        print_row(a->right,i-1);
    }
}
void BFS(TNode*a)
{
   for(int i=1;i<=height(a);i++){
    print_row(a,i);
   }
}

