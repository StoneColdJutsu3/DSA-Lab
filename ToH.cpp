#include<iostream>
using namespace std;
void toH(int n,char start,char aux,char end)
    {
        if(n==1) cout<<"Move from"<<start<<"to"<<end<<endl;
        else
        {
            toH(n-1,start,end,aux);
            cout<<"Move from"<<start<<"to"<<end<<endl;
            toH(n-1,aux,start,end);
        } 
        return;
    }
int main()
{
    int n;
    cout<<"Enter number of disks for Tower of Hanoi: ";
    cin>>n;
    char f='F',a='A',t='T';
    toH(n,f,a,t);
    return 0;
}