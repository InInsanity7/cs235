#include "TodoList.h"

int main(int argc, char *argv[]) {
    std::string argOne;
    std::string argTwo;
    std::string argThree;

    //validate usage:
    if (argc < 2 || argc > 4) {
        std::cout << "Usage: ./TODO <function> [option] [option1]" << std::endl;
    }
    else {
        
        TodoList testList;

        /*
        for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "]=" << argv[i] << std::endl;
        }

        std::string argOne = argv[1];
        std::string argTwo = argv[2];
        */

        if (argOne.compare("add")==0) {
            std::cout << "Adding" << std::endl;

            testList.Add(argv[1], argv[2]);
            testList.PrintTodoList(); //FIXME test
        }
        else if (argOne.compare("remove")==0) {
            if (argc != 3) {
                std::cout << "Usage: ./TODO remove [task]" << std::endl;
            }
            else {
                argTwo = argv[2];
                testList.remove(argTwo);
            }
        }
        else if (argOne.compare("printList")==0) {
            if (argc != 2) {
                std::cout << "Usage: ./TODO printList" << std::endl;
            }
            else {
                testList.PrintTodoList();
            }
        }
        else if (argOne.compare("printDay"==0) {
            if (argc != 3) {
                std::cout << "Usage ./TODO printDay [day]" << std::endl;
            }
            else {
                //FIXME add check [day]

                testList.PrintDaysTasks(argv[2]);
        }
    }

    return 0;
}
