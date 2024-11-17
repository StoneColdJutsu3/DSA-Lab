#include<bits/stdc++.h>
using namespace std;
int priority(char s){
    if(s=='^')return 3;
    else if(s=='*' || s=='/')return 2;
    else if(s=='+' || s=='-')return 1;
    else return -1;
}
void infixToPostfix(string s){
    string ans;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){//all this can be replaced by if(isalnum(s[i])){}
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(!st.empty() && priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<ans<<endl;
    return;
}
int main(){
    string exp;
    cout<<"Enter a mathematical expression:"<<endl;
    cin>>exp;
    infixToPostfix(exp);
    return 0;
}