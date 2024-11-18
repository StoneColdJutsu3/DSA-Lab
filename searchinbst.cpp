#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
    
    public:
        node(int data1){
            data=data1;
            left=right=nullptr;
        }
};
node* insert(node* root,int target){
    if(root==NULL){
        node* temp=new node(target);
        return temp;
    }
    if(target<root->data)root->left=insert(root->left,target);
    else root->right=insert(root->right,target);
    return root;
}
bool search(node* root,int key){//worst case TC=O(N)
    if(root==NULL)return 0;
    if(key==root->data)return 1;
    else if(key<root->data)return search(root->left,key);
    else return search(root->right,key);
}
int main(){
    int arr[8]={6,3,7,1,9,4,10,11};
    node* root=NULL;
    for(int i=0;i<8;i++)root=insert(root,arr[i]);
    int key;
    cout<<"Enter element to be searched: ";
    cin>>key;
    cout<<search(root,key);
    return 0;
}