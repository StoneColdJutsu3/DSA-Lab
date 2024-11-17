#include<bits/stdc++.h>
using namespace std;
bool checkBalanced(string s){
    stack<char> St;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')St.push(s[i]);
        else{
            if(St.empty())return false;
            char ch=St.top();
            St.pop();
            if((s[i]==')' && ch=='(') || (s[i]=='}' && ch=='{') || (s[i]==']' && ch=='['))continue;
            else return false;
        }
    }
    return St.empty();
}
int main(){
    string s;
    cout<<"Enter series of brackets:"<<endl;
    cin>>s;
    bool answer=checkBalanced(s);
    cout<<answer<<endl;
    return 0;
}