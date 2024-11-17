#include<bits/stdc++.h>
using namespace std;
void postfixToInfix(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){//all this can be replaced by if(isalnum(s[i])){}
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string combine='('+t2+s[i]+t1+')';
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
    postfixToInfix(exp);
    return 0;
}