#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include"LinkedList.h"
#pragma once
class Stack_A
{
private:
    int *element;
    int head=-1;
    int capacity;
public:
    void push(int a);
    void create(int n);
    bool Is_Full();
    bool Is_Empty();
    int pop();
    int peek();
};
class Stack_L
{
private:
   Node *head;
public:
    void push(int a);
    bool Is_Empty();
    int pop();
    int peek();
};
#endif // STACK_H_INCLUDED
