#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};

Node* tail=NULL;
void insert(int element,int d)
{
    if(tail==NULL)
    {
        Node* newnode=new Node(d);
        tail=newnode;
        newnode->next=newnode;
    }
    else
    {
        Node* curr=tail;
        while(curr->data!=element)
        curr=curr->next;
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print()
{
    Node* temp=tail;
    if(tail==NULL)
    cout<<"list is empty";
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=tail);
    cout<<endl;
    
}
void deletion(int element)
{
    Node* prev=tail;
    Node* curr;
    while(curr->data!=element)
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr==prev)
    tail=NULL;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}
int main()
{
    Node* tail=NULL;
    insert(2,2);
    print();
    insert(2,5);
    insert(2,4);
    print();
    deletion(2);
    print();
}