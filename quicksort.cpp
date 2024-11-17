#include<bits/stdc++.h>
using namespace std;

int partition(int *arr,int start,int end){
	
	int pivot=arr[start];
	int i=start;
	int j=end;
	
	do{
		do{
			i++;
		}while( i<=end &&arr[i]<=pivot);
		
		do{
			j--;
		}while(j>=start && arr[j]>=pivot);
		
		if(i<j){
			swap(arr[i],arr[j]);	
		}
	}while(i<j);
	swap(arr[start],arr[j]);
	
	return j;
}

void quickSort(int arr[],int low ,int high){
	if(low<high){
		int p=partition(arr,low,high+1);
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
	}
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
	int n;
	cout<<"Enter the number of array"<<endl;
	cin>>n;
	
	cout<<"Enter the elements of array"<<endl;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
	quickSort(arr,0,n-1);
	
	
	printArray(arr,n);
}
