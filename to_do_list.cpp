#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);
int main() {
    vector<Task> tasks;
    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume the newline character after the choice
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);
    return 0;
}
void addTask(vector<Task>& tasks) {
    string taskDescription;
    cout << "Enter the task description: ";
    getline(cin, taskDescription);
    tasks.push_back(Task(taskDescription));
    cout << "Task added successfully.\n";
}
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to show.\n";
        return;
    }
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " [Completed]";
        }
        cout << "\n";
    }
}
void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > tasks.size()) {cout << "Invalid task number.\n";}
	else {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
}
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > tasks.size()) {cout << "Invalid task number.\n";} 
	else {
        tasks.erase(tasks.begin() + (taskNumber - 1));
        cout << "Task removed successfully.\n";
    }
}
