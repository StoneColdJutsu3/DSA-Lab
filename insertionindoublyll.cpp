#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* prev;
        node* next;
    
    public:
        node(int data1,node* prev1,node* next1){
            data=data1;
            prev=prev1;
            next=next1;
        }
        node(int data2){
            data=data2;
            prev=nullptr;
            next=nullptr;
        }
};
node* arrToDll(int arr[]){
    node* head=new node(arr[0]);
    node* back=head;
    for(int i=1;i<5;i++){
        node* temp=new node(arr[i],back,nullptr);
        back->next=temp;
        back=temp;
    }
    return head;
}
void printDll(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
node* insertBeforeHead(node* head,int val){//assuming their is a list with atleast one element which is obv head
    node* newHead=new node(val,nullptr,head);
    head->prev=newHead;
    return newHead;
}
node* insertBeforeTail(node* head,int val){
    node* temp=head;
    if(temp->prev==NULL && temp->next==NULL)return insertBeforeHead(head,val);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node* back=temp->prev;
    node* beftail=new node(val,back,temp);
    back->next=beftail;
    temp->prev=beftail;
    return head;
}
node* insertBeforePos(node* head,int val,int k){
    if(head==NULL)return head;
    node* temp=head;
    int count=0;
    bool found=false;
    while(temp!=NULL){
        count++;
        if(count==k){
            found=true;
            break;
        }
        temp=temp->next;
    }
    if(found==false)return head;
    if(temp->prev==NULL && temp->next==NULL)return head;
    if(temp->prev==NULL)return insertBeforeHead(head,val);
    if(temp->next==NULL)return insertBeforeTail(head,val);
    node* back=temp->prev;
    node* newNode=new node(val,back,temp);
    back->next=newNode;
    temp->prev=newNode;
    return head;
}
void insertBeforeNode(int val,node* givenNode){
    node* back=givenNode->prev;
    node* newNode=new node(val,back,givenNode);
    back->next=newNode;
    givenNode->prev=newNode;
}
int main(){
    int arr[5]={2,6,9,15,19};
    node* head=arrToDll(arr);
    printDll(head);
    int val;
    cin>>val;
    //head=insertBeforeHead(head,val);
    //head=insertBeforeTail(head,val);
    //int k;
    //cin>>k;
    //head=insertBeforePos(head,val,k);
    insertBeforeNode(val,head->next);
    printDll(head);
    return 0;
}