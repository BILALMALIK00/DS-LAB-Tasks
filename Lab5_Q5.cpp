#include<iostream>
using namespace std;
#define N 5
bool is_safe(int maze[N][N],int solution[N][N],int x,int y) {
	if(x >=0 && x<N && y>=0 && y<N && maze[x][y]==1 &&solution[x][y]!=1) {
		return true;
	}
	return false;
}
bool solve(int maze[N][N], int solution[N][N], int x, int y) {
	if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
		solution[x][y] = 1;
		return true;
	}

	if (is_safe(maze, solution, x, y)) {
		solution[x][y] = 1;
		if (solve(maze, solution, x + 1, y)) return true;
		if (solve(maze, solution, x, y - 1)) return true;
		if (solve(maze, solution, x - 1, y)) return true;
		if (solve(maze, solution, x, y + 1)) return true;
		solution[x][y] = 0;
		return false;
	}
	return false;
}

void print(int solution[N][N]) {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cout<<solution[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main() {
	int maze[5][5]=
	 {{1,0,1,0,1},
		{1,1,1,1,1},
		{0,1,0,1,1},
		{1,0,0,1,1},
		{1,1,1,0,1}
	};
	int solution[N][N]= {0};
	if(solve(maze,solution,0,0)) {
		cout<<"solution exist"<<endl;
		print(solution);
	} else {
		cout<<"no solution exist"<<endl;
	}
}
