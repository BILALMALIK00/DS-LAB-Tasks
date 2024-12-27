#include <iostream>
using namespace std;

const int maxN = 100, maxM = 100;
int grid[maxN][maxM], visited[maxN][maxM];
int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void dfs(int n, int m, int row, int col) {
    visited[row][col] = 1;
    for (int d = 0; d < 8; ++d) {
        int newRow = row + directions[d][0];
        int newCol = col + directions[d][1];
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
            dfs(n, m, newRow, newCol);
        }
    }
}

int countIslands(int n, int m) {
    int islandCount = 0;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            if (grid[row][col] == 1 && !visited[row][col]) {
                ++islandCount;
                dfs(n, m, row, col);
            }
        }
    }
    return islandCount;
}

int main() {
    int n = 4, m = 2;
    int inputGrid[4][2] = {
        {0, 1},
        {1, 0},
        {1, 1},
        {1, 0}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid[i][j] = inputGrid[i][j];
            visited[i][j] = 0;
        }
    }

    cout << countIslands(n, m) << endl;
}

