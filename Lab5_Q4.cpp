#include<iostream>
using namespace std;
int sum(int *arr[], int size[], int dim, int total) {
    if(total == dim) {  
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < size[dim]; i++) {
        ans += arr[dim][i]; 
    }
    ans += sum(arr, size, dim+1,total);
    return ans;
}

int main() {
    int *grid[5];
    grid[0] = new int[5]{1, 7, 9, 7, 6};  
    grid[1] = new int[3]{10, 70, 90};    
    grid[2] = new int[2]{19, 7};          
    grid[3] = new int[4]{7, 9, 7, 3};  
    grid[4] = new int[1]{1};              
    int size[5] = {5, 3, 2, 4, 1};
    cout << "Jagged array: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < size[i]; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    int sum_ = sum(grid, size,0, 5);
    cout << "Total sum of the elements: " << sum_ << endl;
    for(int i = 0; i < 5; i++){
        delete[] grid[i];
    }
}

