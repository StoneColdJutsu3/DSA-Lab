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
bool searchAnElement(node* head,int val){
    bool ans=false;
    node* temp=head;
    while(temp){
        if(val==temp->data)ans=true;
        temp=temp->next;
    }
    return ans;
}
int main(){
    int arr[5]={7,2,9,12,15};
    node* head=arrToLl(arr);
    int val;
    cin>>val;
    int fs=searchAnElement(head,val);
    if(fs==1)cout<<endl<<"Element found";
    else cout<<endl<<"Elementy not found";
    return 0;
}
