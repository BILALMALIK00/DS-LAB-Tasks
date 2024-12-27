#include<iostream>
using namespace std;
void customized_shellsort(float *record,int n){
	for(int gap=n/4;gap>0;gap/=4){
		for(int j=gap;j<n;j++){
			float temp=record[j];
			int res=j;
			while(res>=gap&&record[res-gap]>temp){
				record[res]=record[res-gap];
				res-=gap;
				
			}
			record[res]=temp;
		}
	}
}
void display(float *arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cout<<"ENTER SIZE OF ARRAY:";
	cin>>n;
	float record[n];
	cout<<"ENTER WEIGHT OF EMPLOYEES:"<<endl;
	for(int i=0;i<n;i++){
		cin>>record[i];
	}
	cout<<"UNSORTED WEIGHTS"<<endl;
	display(record,n);
	customized_shellsort(record,n);
	cout<<"SORTED WEIGHTS"<<endl;
	display(record,n);
}
