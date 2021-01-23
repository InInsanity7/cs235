#include "TodoList.h"

int main(int argc, char *argv[]) {

    //validate usage:
    if (argc < 2 || argc > 4) {
        std::cout << "Usage: ./TODO <function> [option] [option1]" << std::endl;
    }
    else {
        
        //initiate class
        TodoList testList;

        //ADD
        if (argOne.compare("add")==0) {
            //validate add
            if (argc != 4) {
                std::cout << "Usage: ./TODO add [date] [task]" << std::endl;
            }
            //do add
            else {
                testList.Add(argv[1], argv[2]);
            }
        }

        //REMOVE
        else if (argOne.compare("remove")==0) {
            //validate remove
            if (argc != 3) {
                std::cout << "Usage: ./TODO remove [task]" << std::endl;
            }
            //do remove
            else {
                testList.remove(argv[2]);
            }
        }
        
        //PRINT_TODO_LIST
        else if (argOne.compare("printList")==0) {
            //validate print
            if (argc != 2) {
                std::cout << "Usage: ./TODO printList" << std::endl;
            }
            //do print
            else {
                testList.PrintTodoList();
            }
        }

        //PRINT_DAYS_TASKS
        else if (argOne.compare("printDay"==0) {
            //validate
            if (argc != 3) {
                std::cout << "Usage ./TODO printDay [day]" << std::endl;
            }
            //do
            else {
                testList.PrintDaysTasks(argv[2]);
            }
        }
    }

    return 0;
}

        /*
        for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "]=" << argv[i] << std::endl;
        }

        std::string argOne = argv[1];
        std::string argTwo = argv[2];
        */
