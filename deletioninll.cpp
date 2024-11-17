#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next;
    
    public:
        node(int data1){
            data=data1;
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
node* deleteHead(node* head){
    if(head==NULL || head->next==NULL){//if linked list is empty or there is only one element return null
        return NULL;
    }
    node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
node* deleteTail(node *head){
    if(head==NULL || head->next==NULL) return NULL;
    node* temp=head;
    while(temp->next->next){//to traverse till second last and then point next to nullptr to delete tail
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
node* deleteAtPos(node* head,int k){
    if(head==NULL) return head;
    if(k==1){
        node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    node* temp=head;
    node* prev=NULL;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
node* deleteVal(node* head,int val){
    if(head==NULL) return head;
    if(head->data==val){
        node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    node* temp=head;
    node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==val){
            prev->next=prev->next->next;
            delete temp;;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
int main(){
    int arr[5]={5,8,11,18,6};
    node* head=arrToLl(arr);
    printLl(head);
    //head=deleteHead(head);
    //head=deleteTail(head);
    int k;
    cin>>k;
    head=deleteAtPos(head,k);
    //int val;
    //cin>>val;
    //head=deleteVal(head,val);
    printLl(head);
    return 0;
}