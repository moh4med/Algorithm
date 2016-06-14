#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#pragma once
#include"LinkedList.h"
class Queue_A
{
private:
    int *element;
    int head=-1;
    int tail=-1;
    int n=0;
    int capacity;
public:
    void Enqueue(int a);
    void create(int n);
    bool Is_Full();
    bool Is_Empty();
    int Dequeue();
};
class Queue_L
{
private:
   Node *head;
   Node *tail;
   int n=0;
public:
    void Enqueue(int a);
    bool Is_Empty();
    int Dequeue();
};

#endif // QUEUE_H_INCLUDED
