#ifndef TODO_LIST_H
#define TODO_LIST_H

#include "TodoListInterface.h"
#include <vector>
#include <fstream>

class TodoList: public TodoListInterface {
    public:
       TodoList() { //Read into date & task
           std::vector<std::string> file;
           std::string line;

           std::ifstream todoList ("list.txt");
           if (todoList.is_open()) {
               while (getline(todoList, line)) {
                   file.push_back(line);
               }
               for (int i = 0; i < file.size(); i = i + 2) {
                   date.push_back(file.at(i));
               }
               for (int i = 1; i < file.size(); i = i + 2) {
                   task.push_back(file.at(i));
               }
           }           
           todoList.close();
       }
       
       ~TodoList() { //Write out
           std::ofstream todoList ("list.txt", std::ios::trunc);
           if (todoList.is_open()) {
               for (int i = 0; i < date.size(); i++) {
                   todoList << date.at(i) << std::endl;
                   todoList << task.at(i) << std::endl;
               }
           }
           todoList.close();
       }
       
       void Add(std::string userDate, std::string userTask) {

           date.push_back(userDate);
           task.push_back(userTask);
	   }
       int Remove(std::string userTask) {

           int sizeCount = task.size();
           bool isRemoved = false;
           int removed;

           for (int i = 0; i < sizeCount; i++) {
               if (userTask.compare(task.at(i))==0) {
                   task.erase(task.begin() + i);
                   date.erase(date.begin() + i);
                   isRemoved = true;
                   --i;
                   --sizeCount;
               }
           }
           if (isRemoved) {
               return 1;
           }
           else {
               return 0;
           }
       }
       void PrintTodoList() {
           
           for (int i = 0; i < task.size(); i++) {
           std::cout << date.at(i) << ": " << task.at(i) << std::endl;
           } 
       }
       void PrintDaysTasks(std::string userDate) {

           std::cout << userDate << ": " << std::endl;
           for (int i = 0; i < date.size(); i++) {
               if (userDate.compare(date.at(i))==0) {
                   std::cout << task.at(i) << std::endl;
               }
           }
       }

    private:
       std::vector<std::string> date;
       std::vector<std::string> task;
};

#endif


