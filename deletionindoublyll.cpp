#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node* prev;
    
    public:
        node(int data1,node* next1,node* prev1){
            data=data1;
            next=next1;
            prev=prev1;
        }
        node(int data2){
            data=data2;
            next=nullptr;
            prev=nullptr;
        }
};
node* arrToDll(int arr[]){
    node* head=new node(arr[0]);
    node* back=head;
    for(int i=1;i<5;i++){
        node* temp=new node(arr[i],nullptr,back);
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
node* deleteHead(node* head){
    if(head==NULL || head->next==NULL)return NULL;
    node* temp=head;
    head=head->next;
    head->prev=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}
node* deleteTail(node* head){
    if(head==NULL || head->next==NULL)return NULL;
    node* temp=head;
    while(temp->next!=NULL){//so that temp stays on last element and doesnt go ahead and become NULL,if while(temp) written temp goes after last element to NULL
        temp=temp->next;
    }
    node* back=temp->prev;
    back->next=nullptr;
    temp->prev=nullptr;
    delete temp;
    return head;
}
node* deleteAtPos(node* head,int k){
    if(head==NULL) return head;
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
    if(found==false){
        cout<<"Position not found"<<endl;
        return head;
    }
    if(temp->prev==NULL && temp->next==NULL)return NULL;
    if(temp->prev==NULL)return deleteHead(head);
    if(temp->next==NULL)return deleteTail(head);
    node* back=temp->prev;
    node* front=temp->next;
    back->next=front;
    front->prev=back;
    temp->prev=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}
void deleteNode(node* temp){//cant delete head as head will have to shift to next
    node* back=temp->prev;
    node* front=temp->next;
    if(front==NULL){
        back->next=nullptr;
        temp->prev=nullptr;
        delete temp;
    }
    back->next=front;
    front->prev=back;
    temp->next=temp->prev=nullptr;
    delete temp;
    return;
}
int main(){
    int arr[5]={3,5,9,11,16};
    node* head=arrToDll(arr);
    printDll(head);
    //head=deleteHead(head);
    //head=deleteTail(head);
    //int k;
    //cin>>k;
    //head=deleteAtPos(head,k);
    deleteNode(head->next->next);
    printDll(head);
    return 0; 
}