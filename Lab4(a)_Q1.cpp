#include<iostream>
using namespace std;
void bubble_sort(int*arr,int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j]<arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void display(int *arr,int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cout<<"ENTER SIZE OF ARRAY:"<<endl;
	cin>>n;
	int arr[n];
	cout<<"ENTER ELEMENT:"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"ORIGINAL ARRAY"<<endl;
	display(arr,n);
	bubble_sort(arr,n);
		cout<<"SORTED ARRAY"<<endl;
	display(arr,n);
}
