#ifndef TODO_LIST_INTERFACE_H
#define TODO_LIST_INTERFACE_H

#include <iostream>
#include <string>

class TodoListInterface {
    public:
        TodoListInterface() {}
        virtual ~TodoListInterface() {}

        /*  Adds an item to the todo list with the specified data by the std::string "_duedate" and the task specified by the "_task" */
        virtual void Add(std::string _duedate, std::string _task) = 0;

        /*  Removes an item from the todo list with the specified task name
         *
         *  returns 1 if it removes an item, 0 otherwise */
        virtual int Remove (std::string _task) = 0;

        /*  Prings out the full todo list to the console */
        virtual void PrintTodoList() = 0;

        /*  Prints out all items of a todo list with a particular due date (specified by _duedate) */
        virtual void PrintDaysTasks(std::string _date) = 0;
};

#endif
