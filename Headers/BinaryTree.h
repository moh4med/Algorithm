#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#pragma once
struct TNode{
int data;
TNode* left=NULL;
TNode* right=NULL;
};
class BinaryTree{
private:
TNode* root;
public:
TNode* create(int val=0);
TNode* get_root();
};
void BFS(TNode*a);
int height(TNode*a);
void print_row(TNode*a,int i);
void Inorder(TNode*a);
void Preorder(TNode*a);
void Postorder(TNode*a);
TNode* create_node(int val);
#endif // BINARYTREE_H_INCLUDED
