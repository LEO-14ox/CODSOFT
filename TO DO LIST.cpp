#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool isCompleted;
};

void showMenu() {
    std::cout << "\n===============================\n";
    std::cout << "         TO-DO LIST            \n";
    std::cout << "===============================\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<Task> todoList;
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string taskDesc;
            std::cout << "Enter the task description: ";
            std::getline(std::cin, taskDesc);
            todoList.push_back({taskDesc, false});
            std::cout << "Task successfully added!\n";
        } 
        else if (choice == 2) {
            if (todoList.empty()) {
                std::cout << "\nYour list is empty.\n";
            } else {
                std::cout << "\n--- Your Tasks ---\n";
                for (size_t i = 0; i < todoList.size(); ++i) {
                    std::cout << i + 1 << ". [" << (todoList[i].isCompleted ? "Completed" : "Pending") << "] " << todoList[i].description << "\n";
                }
            }
        } 
        else if (choice == 3) {
            if (todoList.empty()) {
                std::cout << "No tasks available to mark completed.\n";
            } else {
                int index;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> index;
                if (index > 0 && index <= todoList.size()) {
                    todoList[index - 1].isCompleted = true;
                    std::cout << "Task marked as completed!\n";
                } else {
                    std::cout << "Invalid task number.\n";
                }
            }
        } 
        else if (choice == 4) {
            if (todoList.empty()) {
                std::cout << "No tasks available to remove.\n";
            } else {
                int index;
                std::cout << "Enter task number to remove: ";
                std::cin >> index;
                if (index > 0 && index <= todoList.size()) {
                    todoList.erase(todoList.begin() + (index - 1));
                    std::cout << "Task successfully removed.\n";
                } else {
                    std::cout << "Invalid task number.\n";
                }
            }
        } 
        else if (choice == 5) {
            std::cout << "Exiting system. Goodbye!\n";
            break;
        } 
        else {
            std::cout << "Invalid choice selection. Try again.\n";
        }
    }
    return 0;
}