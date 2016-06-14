#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#pragma once
#include"BinaryTree.h"
class BST{
private:
   TNode* root=NULL;
public:
    void create(int val);
    TNode* search(TNode*x,int val);
    TNode* search(int val);
    void insert(TNode**x,int val);
    void insert(int val);
    TNode* getroot();
};
#endif // BINARYSEARCHTREE_H_INCLUDED
