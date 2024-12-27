#include<iostream>
using namespace std;
int searching_id(int *emp_id,int size,int rollnum_digit){
	int start=0;
	int end=size-1;
	int mid=(start+end)/2;
	while(start<=end){
		if((emp_id[mid]==rollnum_digit)){
			return mid;
		}else if(emp_id[mid]>rollnum_digit){
			end=mid-1;
		}else{
			start=mid+1;
		}
		mid=(start+end)/2;
	}
	return start;
}
void sort(int *arr,int size){
	for(int i=0;i<size;i++){
		int min=i;
		for(int j=i+1;j<size;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}
void display(int *emp_id,int n){
	for(int i=0;i<n;i++){
		cout<<emp_id[i]<<" ";
	}
	cout<<endl;
}
void insertintoarray(int *&emp_id,int &n,int index,int roll_num_digit){
int *new_emp_id=new int[n+1];
int cnt=0;
	for(int i=0;i<n+1;i++){
		if(i==index){
			new_emp_id[index]=roll_num_digit;
		}else{
			new_emp_id[i]=emp_id[cnt];
			cnt++;
		}
	}
	delete[]emp_id;
	emp_id=new_emp_id;
	n++;
}
int main(){
	int n;
	cout<<"ENTER SIZE OF ARRAY:"<<endl;
	cin>>n;
	int *emp_id=new int[n];
	cout<<"ENTER EMP IDS:"<<endl;
	for(int i=0;i<n;i++){
		cin>>emp_id[i];
	}
	sort(emp_id,n);
	int roll;
	cout<<"ENTER YOUR ROLL NUM:";
	cin>>roll;
	int last_two_digit=roll%100;
	int index=searching_id(emp_id,n,last_two_digit);
	if(index<n&&emp_id[index]==last_two_digit){
		cout<<"ID PRESENT AT INDEX "<<index<<endl;
	}else{
		insertintoarray(emp_id,n,index,last_two_digit);
		cout<<"AFTER UPDATION"<<endl;
		display(emp_id,n);
	}
	delete[]emp_id;
}
