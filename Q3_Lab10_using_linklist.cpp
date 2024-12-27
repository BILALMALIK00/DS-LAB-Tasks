#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ComputerTask {
public:
    int id;       
    int priority;  
    ComputerTask* next; 

    ComputerTask(int taskId, int taskPriority) {
        id = taskId;
        priority = taskPriority;
        next = NULL;
    }
};
void insertTask(ComputerTask*& head, int taskId, int taskPriority) {
    ComputerTask* newTask = new ComputerTask(taskId, taskPriority);
        if (head == NULL || head->priority < taskPriority || 
        (head->priority == taskPriority && head->id > taskId)) {
        newTask->next = head;
        head = newTask;
        return;
    }
    
    ComputerTask* current = head;
    while (current->next != NULL && 
           (current->next->priority > taskPriority || 
            (current->next->priority == taskPriority && current->next->id < taskId))) {
        current = current->next;
    }
    newTask->next = current->next;
    current->next = newTask;
}
void executeTask(ComputerTask*& head) {
    if (head == NULL) return; 
    
    ComputerTask* taskToExecute = head;
    head = head->next;
    
    cout << "Executing Task " << taskToExecute->id << " with Priority " << taskToExecute->priority << endl;
    
    delete taskToExecute; 
}

int main() {
    srand(time(0));

    int taskCount;
    cout << "Enter the number of tasks to schedule: ";
    cin >> taskCount;

    ComputerTask* taskList = NULL; 

    cout << "\nGenerated tasks with their priorities:\n";
    for (int i = 0; i < taskCount; i++) {
        int taskPriority = rand() % 10 + 1;  
        insertTask(taskList, i + 1, taskPriority);
        cout << "Task " << i + 1 << " has Priority: " << taskPriority << endl;
    }
    cout << "\nTask Execution Order (Highest Priority First):\n";
    while (taskList != NULL) {
        executeTask(taskList);
    }

    return 0;
}

