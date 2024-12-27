#include <iostream>
#include <cstdlib>
#include <ctime>
//It was not mentioned either to use linklist or array so i use array for this  
using namespace std;
class Task {
public:
    int taskid;   
    int priority;  
};
void adjustHeap(Task tasks[], int count, int current) {
    int maxIndex = current;          
    int leftChild = 2 * current + 1;
    int rightChild = 2 * current + 2; 
    if (leftChild < count && tasks[leftChild].priority > tasks[maxIndex].priority) {
        maxIndex = leftChild;
    }
    if (rightChild < count && tasks[rightChild].priority > tasks[maxIndex].priority) {
        maxIndex = rightChild;
    }
    if (maxIndex != current) {
        swap(tasks[current].priority, tasks[maxIndex].priority);
        swap(tasks[current].taskid, tasks[maxIndex].taskid);
        adjustHeap(tasks, count, maxIndex);
    }
}
void createMaxHeap(Task tasks[], int count) {
    for (int i = count / 2 - 1; i >= 0; i--) {
        adjustHeap(tasks, count, i);
    }
}
void removeHighestPriority(Task tasks[], int &count) {
    tasks[0] = tasks[count - 1];
    count--;
    adjustHeap(tasks, count, 0);
}

int main() {
    srand(time(0));

    int totalTasks;
    cout << "Enter the number of tasks to be scheduled: ";
    cin >> totalTasks;

   
    Task tasks[totalTasks];

	 cout << "\nGenerated tasks with their priorities:\n";
    for (int i = 0; i < totalTasks; i++) {
        tasks[i].taskid = i + 1;
        tasks[i].priority = rand() % 10 + 1; 
        cout << "Task " << tasks[i].taskid << " has Priority: " << tasks[i].priority << endl;
    }

    createMaxHeap(tasks, totalTasks);
	if(totalTasks>0){
    cout << "\nTask Execution Order (Highest Priority First):\n";
    while (totalTasks > 0) {
        cout << "Executing Task " << tasks[0].taskid << " with Priority " << tasks[0].priority << endl;
        removeHighestPriority(tasks, totalTasks);
    }
}else{
	cout<<"No Tasks To Schedule"<<endl;
}

    return 0;
}

