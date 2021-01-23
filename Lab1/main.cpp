#include "TodoList.h"

int main(int argc, char *argv[]) {
    std::string function;
    
    //validate usage:
    if (argc < 2 || argc > 4) {
        std::cout << "Usage: ./TODO <function> [option] [option1]" << std::endl;
    }
    else {
        function = argv[1];

        //initiate class
        TodoList userList;

        //ADD
        if (function.compare("add")==0) {
            //validate add
            if (argc != 4) {
                std::cout << "Usage: ./TODO add [date] [task]" << std::endl;
            }
            //do add
            else {
                userList.Add(argv[2], argv[3]);
            }
        }

        //REMOVE
        else if (function.compare("remove")==0) {
            //validate remove
            if (argc != 3) {
                std::cout << "Usage: ./TODO remove [task]" << std::endl;
            }
            //do remove
            else {
                userList.Remove(argv[2]);
            }
        }
        
        //PRINT_TODO_LIST
        else if (function.compare("printList")==0) {
            //validate print
            if (argc != 2) {
                std::cout << "Usage: ./TODO printList" << std::endl;
            }
            //do print
            else {
                userList.PrintTodoList();
            }
        }

        //PRINT_DAYS_TASKS
        else if (function.compare("printDay")==0) {
            //validate
            if (argc != 3) {
                std::cout << "Usage ./TODO printDay [day]" << std::endl;
            }
            //do
            else {
                userList.PrintDaysTasks(argv[2]);
            }
        }
    }

    return 0;
}

        /*
        for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "]=" << argv[i] << std::endl;
        }

        std::string function = argv[1];
        std::string argTwo = argv[2];
        */
