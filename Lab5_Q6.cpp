#include<iostream>
using namespace std;
#define N 4
void print(int arr[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool is_safe(int row,int col,int board[N][N]){
	int x=row;
	int y=col;
	
	while(y>=0){
		if(board[x][y]==1){
			return false;
		}
		y--;
	}
	x=row;
	y=col;
	while(x>=0&&y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}
	x=row;
	y=col;
	while(x<N&&y>=0){
		if(board[x][y]==1){
			return false;
		}
		x++;
		y--;
	}
	return true;
}
void solve(int board[N][N],int col,int count,int &max_flags){
	if(col==N){
	if (count > max_flags){
        max_flags = count;
        }
        return;
    }
		for(int rows=0;rows<N;rows++){
		if(is_safe(rows,col,board)){
			board[rows][col]=1;
		solve(board,col+1,count+1,max_flags);
			board[rows][col]=0;
		}
	}
			solve(board,col+1,count,max_flags);
}
int main(){

	int board[N][N]={0};
	int cnt=0;
	int max_flags=0;
	solve(board,0,cnt,max_flags);
 cout << "Maximum number of flags that can be placed: " << max_flags << endl;		
	};

