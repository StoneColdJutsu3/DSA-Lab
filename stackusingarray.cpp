#include<bits/stdc++.h>
using namespace std;
class stackUsingArray{
    public:
        int arr[5],last=-1,size=0;
    
    public:
        void push(int x){
            if(last>=5) return;
            last++;
            arr[last]=x;
            size++;
        }
        void pop(){
            if(last==-1){
                 cout<<"Stack is empty"<<endl;
                 return;
            }
            last--;
            size--;
        }
        int top(){
            if(last==-1)cout<<"Stack is empty"<<endl;
            else return arr[last];
        }
};
int main(){
    stackUsingArray st;
    int t=st.top();
    cout<<t<<endl;
    st.pop();
    st.push(5);
    t=st.top();
    cout<<t<<endl;
    st.push(2);
    st.push(3);
    st.pop();
    t=st.top();
    cout<<t<<endl;
    st.push(9);
    cout<<st.size<<endl;
    return 0;
}