#include "maze.h"
#include <algorithm>
#include <bits/stdc++.h>

bool AMaze::findPath(int x, int y, int z) {
    std::string currentLocation;
    std::stringstream output;

        //stringify current location
        output << "(" << x << ", " << y << ", " << z << ")" << std::endl;
   /* 
        currentLocation = "(";
        currentLocation += std::to_string(x);
        currentLocation += ", ";
        currentLocation += std::to_string(y);
        currentLocation += ", ";
        currentLocation += std::to_string(z);
        currentLocation += ")";
*/
        //checks bounds
        if (x < MAZE_LENGTH || x >= MAZE_LENGTH) {
            return false;
        }
        if (y < MAZE_LENGTH || y >= MAZE_LENGTH) {
            return false;
        }
        if (z < MAZE_LENGTH || z >= MAZE_LENGTH) {
            return false;
        }    
        //checks for previously travelled path
       for (int u = 0; u < path.size(); u++) {
           if (path[u] == output.str()) {
               return false;
           }
       }

       //check for open path
       if (maze[x][y][z] == 0;) {
           return false;
       }

       path.push_back(output.str());
        
        //if end of maze
        if(x == MAZE_LENGTH && y == MAZE_LENGTH && z == MAZE_LENGTH) {
            return true;
            std::cout << "End of Maze found" << std::endl;
        }

        //recurse to solve
        if (this->findPath(x - 1, y, z) ||
            this->findPath(x + 1, y, z) ||
            this->findPath(x, y - 1, z) ||
            this->findPath(x, y + 1, z) ||
            this->findPath(x, y, z - 1) ||
            this->findPath(x, y, z + 1)) {
          return true;
        }
        else {
            path.pop_back();
            return false;

        }
}
