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
node* arrToLl(int arr[],int n){
    node* head=new node(arr[0]);
    node* mover=head;
    for(int i=1;i<n;i++){
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
//Traversal is very imp while(temp){temp=temp->next;}
int lengthOfLl(node* head){
    int count=0;
    node* temp=head;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->next;
        count++;
    }//Traversal and Finding length both take O(N) Time Complexity
    return count;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node* head=arrToLl(arr,n);
    cout<<endl<<lengthOfLl(head);
    return 0;
}

