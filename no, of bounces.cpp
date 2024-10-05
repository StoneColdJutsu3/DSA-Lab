#include<iostream>
using namespace std;
int main()
{
	int count=0;
	float v;
	cout<<"Enter avg velocity of ball:";
	cin>>v;
	while(v>0.001)
	{
		count++;
		v/=2;
	}
	cout<<"Number of bounces="<<count<<endl;
	return 0;
}
