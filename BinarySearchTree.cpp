#include<iostream>
#include<BinarySearchTree.h>
using namespace std;
void BST::create(int val){
root=create_node(val);
}
TNode* BST::search(TNode*x,int val)
{
    if(x==NULL||val==x->data)
    {
        x=create_node(val);
    }
    else
    {
        if(x->data > val)
        {
            return search(x->left,val);
        }
        else if (x->data < val)
        {
            return search(x->right,val);
        }
    }
}
void BST::insert(int val){
insert(&root,val);
}
TNode* BST::search(int val){
search(root,val);
}
TNode* BST::getroot(){
return root;
}
void BST::insert(TNode**x,int val)
{
    if(*x==NULL)
    {
        *x=create_node(val);
    }
    else
    {
        if((*x)->data > val)
        {
            insert(&((*x)->left),val);
        }
        else
        {
            insert(&((*x)->right),val);
        }
    }
}
