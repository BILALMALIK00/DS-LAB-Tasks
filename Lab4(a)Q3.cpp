#include<iostream>
using namespace std;
int getposition(string designation){
	if(designation=="CEO"){
		return 1;
	}else if(designation=="CTO"){
		return 2;
	}
	else if(designation=="CFO"){
		return 3;
	}else if(designation=="VP"){
		return 4;
	}
	else if(designation=="MGR"){
		return 5;
	}
	else {
		return 6;
	}
}void sorting_basis_on_designation(string cooperate[],int size){
	for(int i=1;i<size;i++){
		string temp=cooperate[i];
		int j=i-1;
		int position=getposition(cooperate[i]);//getting priority num 
		while(j>=0){
			if(getposition(cooperate[j])>position){
				cooperate[j+1]=cooperate[j];
			}else{
				break;
			}
			j--;
		}
		cooperate[j+1]=temp;
	}
}
int main(){
	string designations[]={"EMP","CFO","MGR","EMP","VP","CTO","MGR","CEO"};
	int size=sizeof(designations)/sizeof(designations[0]);
	cout<<"INITIAL ARRANGEMENT"<<endl;
	for(int i=0;i<size;i++){
		cout<<designations[i]<<" ";
	}
	cout<<endl;
	 sorting_basis_on_designation(designations,size);
	 cout<<"AFTER SORTING"<<endl;
	 	for(int i=0;i<size;i++){
		cout<<designations[i]<<" ";
	}
}
