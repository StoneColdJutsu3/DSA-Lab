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
void inorderTraversal(node* root){
    if(root==NULL)return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
int main(){
    int arr[8]={5,3,4,7,8,1,9,11};
    node* root=NULL;
    for(int i=0;i<8;i++)root=insert(root,arr[i]);
    inorderTraversal(root);//gives data in acsending order
    return 0;
}