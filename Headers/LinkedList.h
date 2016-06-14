#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#pragma once
struct Node
{
    int value=0;
    Node* next=NULL;
};

class LinkedList
{
private:
    Node* head=NULL;
    Node* tail=NULL;
public:
    void traverse();
    void Push(int val);
    void Append(int val=0);
    void Insert(int i,int val,bool insist=false);
    void del(int i);
    void remove(int val,bool all=false);
    int length();
    void removefirst();
    void swap_node(int a,int b);
    void reverseList();
};

#endif // LINKEDLIST_H_INCLUDED
