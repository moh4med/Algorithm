#include<iostream>
#include<LinkedList.h>
using namespace std;

void LinkedList::traverse()
{
    Node *x=head;
    while(x!=NULL)
    {
        cout<<x->value<<endl;
        x=x->next;
    }
}
void LinkedList::Push(int val)
{
    Node* x=new Node;
    x->value=val;
    x->next=head;
    head=x;
    if(tail==NULL)
    {
        tail=x;
    }
}
void LinkedList:: Append(int val)
{
    Node* x=new Node;
    x->value=val;
    if(head==NULL)
    {
        head=x;
        tail=x;
    }
    else
    {
        tail->next=x;
        tail=x;
    }

}
void LinkedList:: Insert(int i,int val,bool insist)
{
    Node *y=head;
    while(y!=NULL &&i>1)
    {
        y=y->next;
        i--;
    }
    if(i==0)
    {
        Push(val);
    }
    else if(y==NULL)
    {
        if(insist)
        {
            while(i>0)
            {
                Append();
                i--;
            }
            Append(val);
        }
    }
    else
    {
        Node* x=new Node;
        x->value=val;
        Node *z=y->next;
        y->next=x;
        x->next=z;
    }
}
void LinkedList:: del(int i)
{
    Node *y=new Node;
    y->next=head;
    if(i<0)
    {
        i=length()+i;
    }
    while(y->next!=NULL&&i>0)
    {
        y=y->next;
        i--;
    }
    if(y->next!=NULL&&i>=0)
    {
        Node *x=y->next;
        y->next=x->next;
        if(head==x)
        {
            head=x->next;
        }
        if(tail==x)
        {
            tail=y;
        }
        if(head==NULL)
        {
            tail=NULL;
        }
        delete x;
    }
    else
    {
        cout<<"out of range\n";
    }
}
void LinkedList:: remove(int val,bool all)
{
    bool found=false,f=false;
    Node *y=new Node;
    y->next=head;
    while(y->next!=NULL)
    {
        if(y->next->value==val)
        {
            Node *x=y->next;
            y->next=x->next;
            if(head==x)
            {
                head=x->next;
            }
            if(tail==x)
            {
                tail=y;
            }
            if(head==NULL)
            {
                tail=NULL;
            }
            delete x ;
            found=true;
            f=true;
            if(!all)
            {
                break;
            }
        }
        else
        {
            f=false;
        }
        if(!f)
        {
            y=y->next;
        }
    }
    if (!found)
    {
        cout<<"not found\n";
    }

}
int LinkedList:: length()
{
    int i=0;
    Node *x=head;
    while(x!=NULL)
    {
        x=x->next;
        i++;
    }
    return i;
}
void LinkedList:: removefirst()
{
    del(0);
}
void LinkedList:: swap_node(int a,int b)
{
    Node *x=new Node;
    x->next=head;
    while(x->next!=NULL)
    {
        if(x->next->value==a)
        {
            break;
        }
        x=x->next;
    }
    Node *y=new Node;
    y->next=head;
    while(y->next!=NULL)
    {
        if(y->next->value==b)
        {
            break;
        }
        y=y->next;
    }
    if(y->next!=NULL &&x->next!=NULL)
    {
        if(x->next==head)
        {
            head=y->next;
        }
        else if(y->next==head)
        {
            head=x->next;
        }
        if(x->next==tail)
        {
            tail=y->next;
        }
        else if(y->next==tail)
        {
            tail=x->next;
        }
        Node* a=y->next;             //swap previous
        y->next=x->next;
        x->next=a;
        a=y->next->next;               //swap next
        y->next->next=x->next->next;
        x->next->next=a;

    }
}
void LinkedList:: reverseList()
{
    Node *a=head,*b=NULL,*c;
    while(a!=NULL)
    {
        c=a->next;
        a->next=b;
        b=a;
        a=c;
    }
    a=head;
    head=tail;
    tail=a;
}

