#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int value;
    node* next;
    node(int data)
    {
        this->value=data;
        this->next=NULL;
    }
};
void insertStart(node* &head,int d)
{
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}
void insertEnd(node* &head,int d)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        
    }
    node* newNode=new node(d);
    temp->next=newNode;
}
void insertAtIndex(node* &head,int index,int d)
{
    node* temp=head;
    int i=1;
    while(i<index-1)
    {
        temp=temp->next;
        i++;
    }
    node* newNode=new node(d);
    newNode->next=temp->next;
    temp->next=newNode;
}
void deleteAtStart(node* &head)
{
    node* temp=head;
    head=head->next;
    delete temp;
}
void deleteAtEnd()
{

}
void deleteAtIndex()
{
    
}
void printList(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->value<<"  ";
        temp=temp->next;
    }
}
int main()
{
    node* node1=new node(1);
    node* head=node1;
    insertStart(head,3);
    insertStart(head,4);
    insertEnd(head,2);
    insertAtIndex(head,3,5);
    insertAtIndex(head,4,6);
    deleteAtStart(head);
    printList(head);
}