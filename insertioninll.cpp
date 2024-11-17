#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next;
    
    public:
        node(int data1,node* next1){
            data=data1;
            next=next1;
        }

        node(int data2){
            data=data2;
            next=nullptr;
        }
};
node* arrToLl(int arr[]){
    node* head=new node(arr[0]);
    node* mover=head;
    for(int i=1;i<5;i++){
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void printLl(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
node* insertAtHead(node* head,int el){
    node* temp=new node(el,head);
    return temp;//as temp becomes the new head
}
node* insertAtTail(node* head,int el){
    if(head==NULL){
        node* temp=new node(el);
        return temp;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new node(el);
    return head;
}
node* insertAtPos(node* head,int el,int k){//1 being insert at head
    if(head==NULL){
        if(k==1){
            node* temp=new node(el);
            return temp;
        }
        else return head;//or return NULL since head is already null and element can be added only to 1st pos
    }
    if(k==1){
        node* temp=new node(el,head);
        return temp;
    }
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count==k-1){
            node* x=new node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}
node* insertBeforeElement(node* head,int el,int befel){//1 being insert at head
    if(head==NULL) return head;
    if(head->data==befel){
        node* temp=new node(el,head);
        return temp;
    }
    node* temp=head;
    bool found=false;
    while(temp->next!=NULL){//checking temp->next!=NULL as temp will only go till 2nd last element
        if(temp->next->data==befel){
            node* x=new node(el,temp->next);
            temp->next=x;
            found=true;
            break;
        }
        temp=temp->next;
    }
    if(found==0)cout<<"Element not found"<<endl;
    return head;
}
int main(){
    int arr[5]={4,7,11,13,21};
    node* head=arrToLl(arr);
    printLl(head);
    int el;
    cin>>el; 
    //int pos;
    //cin>>pos;
    int befel;
    cin>>befel;
    //head=insertAtHead(head,el);
    //head=insertAtTail(head,el);
    //head=insertAtPos(head,el,pos);
    head=insertBeforeElement(head,el,befel);
    printLl(head);
    return 0;
}