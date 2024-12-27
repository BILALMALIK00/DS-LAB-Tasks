#include<iostream>
using namespace std;
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
bool is_sorted(int *arr,int size){
	for(int i=0;i<size-1;i++){
		if(i+1<size){
		if(arr[i]>arr[i+1]){
			return false;
		}
	}
	}
	return true;
}
bool is_uniformly(int *data_set,int n){//if distance is not equal means they are not uniformly distributed
	if(n<=1){
		return true;
	}
	int difference=data_set[1]-data_set[0];
	for(int i=1;i<n-1;i++){
		if(data_set[i+1]-data_set[i]!=difference){
			return false;
		}
}
return true;
}
int interpolation_search(int*data_set,int n,int target){
	int start=0;
	int end=n-1;
	while(start<=end&&target>=data_set[start]&&target<=data_set[end]){
	 if (data_set[start] == data_set[end]) {
            if (data_set[start] == target) {
                return start;
            }
            return -1;
        }
    int position=start+((target-data_set[start])*(end-start))/(data_set[end]-data_set[start]);

		if(data_set[position]==target){
			return position;
		}else if(data_set[position]>target){
			start=position+1;
		}else{
			end=position-1;
		}
	}
	return -1;
}
void display(int *arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cout<<"ENTER SIZE OF DATA SET:"<<endl;
	cin>>n;
	cout<<"ENTER DATA:"<<endl;
	int *data_set=new int[n];
	for(int i=0;i<n;i++){
		cin>>data_set[i];
	}
	if(!is_sorted(data_set,n)){
		sort(data_set,n);
		cout<<"SORTED:"<<endl;
		display(data_set,n);
	}
	
	if(!is_uniformly(data_set,n)){
	cout<<"IT IS NOT UNIFORMLY"<<endl;
	}else{
	int target;
	cout<<"ENTER ELEMENT TO CHECK:";
	cin>>target;
	int index=interpolation_search(data_set,n,target);
	if(index!=-1){
	cout<<"ELEMENT PRESENT AT INDEX:"<<index<<endl;
}else{
	cout<<"ELEMENT NOT FOUND"<<endl;
}
}
}
