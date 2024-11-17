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
int main(){
    int arr[5]={3,5,9,11,16};
    node* head=arrToDll(arr);
    printDll(head);
    return 0;
}