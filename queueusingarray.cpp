#include<bits/stdc++.h>
using namespace std;
class Q{
    public:
        int arr[5],start=-1,end=-1,cursize=0;
    
    public:
        void push(int x){
            if(cursize>=5){ 
                cout<<"Queue is full";
                return;
            }
            if(cursize==0){
                start=0;
                end=0;
            }
            else end=(end+1)%5;
            arr[end]=x;
            cursize++;
            return;
        }
        void pop(){
            if(cursize==0){
                cout<<"Queue is empty"<<endl;
                return;
            }
            if(cursize==1){
                start=end=-1;
            }
            start=(start+1)%5;
            cursize--;
        }
        int top(){
            if(start==-1) cout<<"Queue is empty"<<endl;
            else return arr[start];
        }
};
int main(){
    Q q;
    int t=q.top();
    cout<<t<<endl;
    q.pop();
    q.push(3);
    q.push(7);
    q.push(9);
    q.pop();
    t=q.top();
    cout<<t<<endl;
    q.push(5);
    int size=q.cursize;
    cout<<size<<endl;
}