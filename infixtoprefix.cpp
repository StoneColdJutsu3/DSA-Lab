#include<bits/stdc++.h>
using namespace std;
string rev(string s){
    reverse(s.begin(),s.end());
    return s;
}
string revWithBrackets(string s){
   string rs=rev(s);
    for(int i=0;i<rs.length();i++){
        if(rs[i]==')')rs[i]='(';
        else if(rs[i]=='(')rs[i]=')';
    }
    return rs;
}
int priority(char s){
    if(s=='^')return 3;
    else if(s=='*' || s=='/')return 2;
    else if(s=='+' || s=='-')return 1;
    else return -1;
}
void infixToPrefix(string s){
    string ans;
    stack<char> st;
    string rs=revWithBrackets(s);
    for(int i=0;i<rs.length();i++){
        if((rs[i]>='A' && rs[i]<='Z') || (rs[i]>='a' && rs[i]<='z') || (rs[i]>='0' && rs[i]<='9')){//all this can be replaced by if(isalnum(rs[i])){}
            ans+=rs[i];
        }
        else if(rs[i]=='('){
            st.push(rs[i]);
        }
        else if(rs[i]==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(rs[i]=='^'){
                while(!st.empty() && priority(rs[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(rs[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(rs[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    string finalAns=rev(ans);
    cout<<finalAns<<endl;
    return;
}
int main(){
    string exp;
    cout<<"Enter a mathematical expression:"<<endl;
    cin>>exp;
    infixToPrefix(exp);
    return 0;
}