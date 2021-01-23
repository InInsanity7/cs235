#ifndef TODO_LIST_H
#define TODO_LIST_H

#include "TodoListInterface.h"
#include <vector>
#include <fstream>

class TodoList: public TodoListInterface {
    public:
       TodoList() {
           std::cout << "In Constructor" << std::endl;
       }
       ~TodoList() {
           std::cout << "In Destructor" << std::endl;
       }
       void Add(std::string userDate, std::string userTask) {
           std::cout << "In Add" << std::endl;

	   std::ofstream todoList ("todo.txt", std::ios::app); //appending. Why trunc?
	   if (todoList.is_open()) {
		   todoList.seekp(0 ,std::ios::end);
		   todoList << userDate << std::endl;
		   todoList << userTask << std::endl;
		   todoList.close();
	   }
	   else {
		   std::cout << "Unable to open file" << std::endl;
	   }
	   
       }
       int Remove(std::string userTask) {
           std::cout << "In Remove" << std::endl;
           return 0;
       }
       void PrintTodoList() {
           std::cout << "In PrintTodoList" << std::endl;
           /*for (int i = 0; i < task.size(); i++) {
           std::cout << date.at(i) << std::endl;
           std::cout << task.at(i) << std::endl;
           } */
       }
       void PrintDaysTasks(std::string userDate) {
           std::cout << "In PrintDaysTasks" << std::endl;
           /* bool taskFound = false;

                  for (int i = 0; (i < task.size()) && (!taskFound); i++) {
                      if (userDate.compare(task.at(i))==0) {
                          std::cout << date.at(i) << std::endl;
                          std::cout << task.at(i) << std::endl;

                          taskFound = true;
                      }
                  } */
       }

    private:
       std::vector<std::string> date;
       std::vector<std::string> task;
};

#endif


