#include<iostream>
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

int partition(int*arr,int s,int e){
	int mid=(s+e)/2;
	int pivot=arr[mid];
	int i=s;
	int j=e;
	while(i<=j){
		while(arr[i]<pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<=j){
			swap(arr[i++],arr[j--]);
		}
	}
	return i;
}
void quick_sort(int *arr,int s,int e){
	if(s>=e){
		return;
	}
	int pivot=partition(arr,s,e);
	quick_sort(arr,s,pivot-1);
	quick_sort(arr,pivot,e);
}
void display(int *arr,int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cout<<"Enter size of array:"<<endl;
	cin>>n;
	int *arr=new int[n];
	cout<<"Enter Elements:"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int s=0;
	int e=n-1;
	cout<<"Sorted array:";
	quick_sort(arr,s,e);
	display(arr,n);
	delete[]arr;
}
