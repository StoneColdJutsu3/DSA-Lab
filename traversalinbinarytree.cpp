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
void preorderTraversal(node* root){//TC=O(N) SC=O(height)
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(node* root){
    if(root==NULL)return;
    preorderTraversal(root->left);
    cout<<root->data<<" ";
    preorderTraversal(root->right);
}
void postorderTraversal(node* root){
    if(root==NULL)return;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    cout<<root->data<<" ";
}
int main(){
    int x;
    cout<<"Enter root node value: ";
    cin>>x;
    if(x==-1){
        cout<<"Binary Tree Not Created!"<<endl;
        return 0;
    }
    node* root=new node(x);
    queue<node*> q;
    q.push(root);
    int first,second;
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"Enter left child value for "<<temp->data<<" : ";
        cin>>first;
        if(first!=-1){
            temp->left=new node(first);
            q.push(temp->left);
        }
        cout<<"Enter right child value for "<<temp->data<<" : ";
        cin>>second;
        if(second!=-1){
            temp->right=new node(second);
            q.push(temp->right);
        }
    }
    preorderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
    return 0;
}