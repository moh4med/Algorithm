#include<iostream>
#include"Headers/LinkedList.h"
#include"Headers/Stack.h"
using namespace std;
void Stack_A::create(int n)
{
    Stack_A::element=new int [n];
    capacity=n;
}
bool Stack_A::Is_Full()
{
    return head==capacity-1;
}
bool Stack_A::Is_Empty()
{
    return head==-1;
}
void Stack_A::push(int a)
{
    if(!Is_Full()){
    element[++head]=a;
    }else{
    cout<<"stack is full\n";
    }
}
int Stack_A::pop()
{
    if(!Is_Empty())
    return element[head--];
}
int Stack_A::peek()
{
    return element[head];
}
bool Stack_L::Is_Empty(){
return head==NULL;
}
void Stack_L::push(int a)
{
    Node *x=new Node;
    x->value=a;
    x->next=head;
    head=x;
}
int Stack_L::pop()
{
    if(!Is_Empty()){
    int a=head->value;
     delete head;
    head=head->next;
    return a;}
}
int Stack_L::peek()
{
    return head->value;
}
