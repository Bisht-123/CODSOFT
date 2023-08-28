#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks to display." << std::endl;
            return;
        }

        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            if (tasks[i].completed) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].description << std::endl;
        }
    }

    void deleteTask(size_t index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            std::cout << "Task deleted." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList todo;

    while (true) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Delete Task" << std::endl;
        std::cout << "4. Exit" << std::endl;
        
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter task description: ";
            std::string description;
            std::cin.ignore();
            std::getline(std::cin, description);
            todo.addTask(description);
        } else if (choice == 2) {
            todo.viewTasks();
        } else if (choice == 3) {
            std::cout << "Enter task index to delete: ";
            size_t index;
            std::cin >> index;
            todo.deleteTask(index - 1);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }

    return 0;
}
