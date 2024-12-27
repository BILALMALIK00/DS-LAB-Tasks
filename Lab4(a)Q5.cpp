#include<iostream>
using namespace std;
void customized_comb_sort(float *product_prices,int n){
	float shrink=2.2;
	int gap=n;
	bool swapped=true;
	while(gap>1||swapped){
		gap=(int)(gap/shrink);
		if(gap<1){
			gap=1;
		}
		swapped=0;
	for(int i=0;i+gap<n;i++){
		if(product_prices[i]>product_prices[i+gap]){
			float temp=product_prices[i];
			product_prices[i]=product_prices[i+gap];
			product_prices[i+gap]=temp;
			swapped=true;
		}
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
	cout<<"ENTER SIZE:";
	cin>>n;
	float product_price[n];
	cout<<"ENTER PRICES:"<<endl;
	for(int i=0;i<n;i++){
		cin>>product_price[i];
	}
	cout<<"ORIGINAL LIST:"<<endl;
	display(product_price,n);
	cout<<"SORTED LIST:"<<endl;
	customized_comb_sort(product_price,n);
	display(product_price,n);
}
