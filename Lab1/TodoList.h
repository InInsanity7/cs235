#ifndef TODO_LIST_H
#define TODO_LIST_H

#include "TodoListInterface.h"
#include <vector>

class TodoList: public TodoListInterface {
    public:
       TodoList() {
           std::cout << "In Constructor" << std::endl;
       }
       ~TodoList() {
           std::cout << "In Destructor" << std::endl;
       }
       void Add(std::string &userDate, std::string &userTask) {
           std::cout << "In Add" << std::endl;
           date.push_back(userDate);
           task.push_back(userTask);
       }
       int Remove(std::string task) {
           std::cout << "In Remove" << std::endl;
           return 0;
       }
       void PrintTodoList() {
           /* for (int i = 0; i < task.size(); i++) {
           std::cout << date.at(i) << std::endl;
           std::cout << task.at(i) << std::endl;
           } */
       }
       void PrintDaysTasks(std::string date) {
           std::cout << "In PrintTodoList" << std::endl;
       }

    private:
       std::vector<std::string> date;
       std::vector<std::string> task;
};

#endif
