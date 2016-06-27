#include<iostream>
#include"Headers/LinkedList.h"
#include"Headers/Queue.h"
using namespace std;
void Queue_A::create(int n)
{
    element=new int [n];
    capacity=n;
}
bool Queue_A::Is_Full()
{
    return n==capacity;
}
bool Queue_A::Is_Empty()
{
    return n==0;
}
void Queue_A::Enqueue(int a)
{
    if(!Is_Full())
    {
        head=(head+1)%capacity;
        element[head]=a;
        n++;
    }
    else
    {
        cout<<"stack is full\n";
    }
}
int Queue_A::Dequeue()
{
    if(!Is_Empty())
    {
        tail=(tail+1)%capacity;
        n--;
        return element[tail];
    }
    else
    {
        return -1;
    }
}
bool Queue_L::Is_Empty()
{
    return n==0;
}
void Queue_L::Enqueue(int a)
{
    Node* x=new Node;
    x->value=a;
    if(n==0)
    {
        tail=x;
        head=x;
    }
    else
    {
        tail->next=x;
        tail=x;
    }
    n++;
}
int Queue_L::Dequeue()
{
    if(!Is_Empty())
    {
        Node* x=head;
        head=head->next;
        //delete
        if(x==tail)
        {
            tail=NULL;
        }
        n--;
        return x->value;

    }
    else
    {
        return -1;
    }
}
