#include<iostream>
using namespace std;
int main(){
	int *grid[5];
	grid[0]=new int[5]{1,7,9,7,6};
	grid[1]=new int[5]{10,70,90,80,6};
	grid[2]=new int[5]{19,07,79,7,6};
	grid[3]=new int[5]{7,9,7,6,5};
	grid[4]=new int[5]{1,2,3,4,6};
	cout<<"Normal Ouput"<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"RESIZING EACH INDEX TO 10"<<endl;
		grid[0]=new int[10]{1,7,9,7,6,1,2,3,4,5};
		grid[1]=new int[10]{10,70,90,80,6,1,2,1,2,1};
		grid[2]=new int[10]{19,7,79,7,6,6,5,4,3,2};
		grid[3]=new int[10]{7,9,7,6,5,1,2,3,2,1};
		grid[4]=new int[10]{1,2,3,4,6,7,8,9,6,5};
		for(int i=0;i<5;i++){
			for(int j=0;j<10;j++){
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int i=0;i<5;i++){
			delete[]grid[i];
		}
		
}
