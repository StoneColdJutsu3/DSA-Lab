#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
Node* head=NULL;
class Linkedlist{
    public:
    void insert_start(int d)
    {
        if(head==NULL)
        {
            Node* temp=new Node(d);
            head=temp;
        }
        else
        {
            Node* temp=new Node(d);
            temp->next=head;
            head=temp;
        }

    }

    void insert_end(int d)
    {
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        Node* new_node=new Node(d);
        temp->next=new_node;
        new_node->prev=temp;
    }

    void print_list()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    void insert_at_index(int pos,int d)
    {
        Node* temp=head;
        int i=1;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        Node* new_node=new Node(d);
        new_node->next=temp->next;
        temp->next->prev=new_node;
        temp->next=new_node;
        new_node->prev=temp;
    }

    void delete_at_start()
    {
        Node* temp=head;
        head=head->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        delete temp;
    }

    void delete_at_end()
    {
        Node* curr=head;
        while(curr->next!=NULL)
        curr=curr->next;
        curr->prev->next=NULL;
        curr->prev=NULL;
        delete curr;
    }

    void delete_at_index(int pos)
    {
        Node* curr=head;
        int i=1;
        while(i<pos)
        {
            curr=curr->next;
            i++;
        }
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        delete curr;
    }
};

int main()
{
    Node* head=NULL;
    Linkedlist l;
    l.insert_start(10);
    l.insert_end(20);
    l.insert_at_index(2,30);
    l.delete_at_end();
    l.insert_at_index(2,20);
    l.insert_end(40);
    l.insert_end(50);
    l.delete_at_end();
    l.delete_at_start();
    l.delete_at_index(2);
    l.print_list();
}