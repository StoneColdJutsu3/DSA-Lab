#include<bits/stdc++.h>
using namespace std;
void postfixToPrefix(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string combine=s[i]+t2+t1;
            st.push(combine);
        }
    }
    cout<<st.top()<<endl;
    return;
}
int main(){
    string exp;
    cout<<"Enter a postfix expression:"<<endl;
    cin>>exp;
    postfixToPrefix(exp);
    return 0;
}