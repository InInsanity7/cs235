#include "maze.h"
#include <algorithm>
#include <bits/stdc++.h>

bool AMaze::findPath(int x, int y, int z) {
    x,y,z = 0;
    std::string currentLocation;

        //stringify current location
        currentLocation = "(";
        currentLocation += std::to_string(x);
        currentLocation += ", ";
        currentLocation += std::to_string(y);
        currentLocation += ", ";
        currentLocation += std::to_string(z);
        currentLocation += ")";

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
           if (path[u] == currentLocation) {
               return false;
           }
       }

        path.push_back(currentLocation);
        
        //if end of maze
        if(x == MAZE_LENGTH && y == MAZE_LENGTH && z == MAZE_LENGTH) {
            /*
            for (int i = 0; i < MAZE_LENGTH; i++) {
                for (int j = 0; j < MAZE_LENGTH; j++) {
                    for (int k = 0; k < MAZE_LENGTH; k++) {
                        if (maze[i][j][k] == 2) {
                            maze[i][j][k] = 1;
                        }
                    }
                }
            }
            */
            return true;
            std::cout << "End of Maze found" << std::endl;
        }

//        maze[i][j][k] = 2;
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
