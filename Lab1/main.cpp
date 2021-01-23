#include "TodoList.h"

int main(int argc, char *argv[])
{
    TodoList testList;

    for (int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "]=" << argv[i] << std::endl;
    }

    std::string argOne = argv[1];
    std::string argTwo = argv[2];

    if (argOne.compare("add")==0)
    {
        std::cout << "Adding" << std::endl;

        testList.Add(argOne, argTwo);
        // testList.Print();
    }

    return 0;
}
