#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>
#include <vector>

#define MAZE_LENGTH 5

class AMaze {
public:
    AMaze() {}

    bool findPath(int x, int y, int z);

     
    std::vector<std::string> path;

};

#endif
