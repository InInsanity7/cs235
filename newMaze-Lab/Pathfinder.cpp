#include "Pathfinder.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

const int MAZE_LENGTH = 5;



Pathfinder::Pathfinder() {
    srand(time(0));

    for (int i = 0; i < MAZE_LENGTH; i++) {
        for (int j = 0; j < MAZE_LENGTH; j++) {
            for (int k = 0; k < MAZE_LENGTH; k++) {
                maze[i][j][k] = 1;
            }
        }
    }
}
    
Pathfinder::~Pathfinder() {}
    
std::string Pathfinder::toString() {
    std::string mazeString;
    for (int i = 0; i < MAZE_LENGTH; i++) {
        for (int j = 0; j < MAZE_LENGTH; j++) {
            for (int k = 0; k < MAZE_LENGTH; k++) {
                mazeString += maze[i][j][k];
                mazeString += " ";
            }
            mazeString += "\n";
        }
    }
    return mazeString;
}



void Pathfinder::createRandomMaze() {
    for (int i = 0; i < MAZE_LENGTH; i++) {
        for (int j = 0; j < MAZE_LENGTH; j++) {
            for (int k = 0; k < MAZE_LENGTH; k++) {
                maze[i][j][k] = (rand() % 2);
            }
        }
    }
    maze[0][0][0] = 1;
    maze[4][4][4] = 1;
}

bool Pathfinder::importMaze(string file_name) {
    std::string tempMaze[MAZE_LENGTH][MAZE_LENGTH][MAZE_LENGTH];
    string line;  
    std::ifstream ifs;
    
    ifs.open(file_name, std::ifstream::in);
    if(!ifs.is_open()) {
        std::cout << "File didn't open" << std::endl;
        return false;
    }

    for (int i = 0; i < MAZE_LENGTH; i++) {
        for (int j = 0; j < MAZE_LENGTH; j++) {
            getline(ifs, line); 
            if(ifs.bad() || ifs.fail()) {
                std::cout << "Line read fail" << std::endl;
                return false;
            }
            while(line[line.size()-1] == ' ' ||
                  line[line.size()-1] == '\n' ||
                  line[line.size()-1] == '\r') {

                line = line.substr(0, line.size()-1);
            }
            if(line.size() != MAZE_LENGTH*2-1) {
                cout << "line wrong size: actual " << line.size() << 
                        ", expected: " << MAZE_LENGTH*2-1 << endl;
            return false;
            }
            for (int k = 0; k < MAZE_LENGTH; k++) {
                if (line[k*2] == 0 || line[k*2] == 1) {
                    tempMaze[i][j][k] = line[k*2];
                }
            }
        }
        if (!ifs.eof()) {
        getline(ifs, line);
        }
    }
    //overwrite class with successful import
    for (int i = 0; i < MAZE_LENGTH; i++) {
        for (int j = 0; j < MAZE_LENGTH; j++) {
            for (int k = 0; k < MAZE_LENGTH; k++) {
                maze[i][j][k] = tempMaze[i][j][k];
            }
        }
    }
    maze[0][0][0] = 1;
    maze[4][4][4] = 1;
}




std::vector<std::string> Pathfinder::solveMaze() {
    std::vector<std::string> path;
    int x,y,z = 0;
    std::vector<string> it;
    std::string currentLocation;

    bool findPath(int x, int y, int z) {
        //stringify current location
        currentLocation = "("
        currentLocation += std::to_string(x);
        currentLocation += ", ";
        currentLocation += std::to_string(y);
        currentLocation += ", ";
        currentLocation += std::to_string(z);
        currentLocation += ")";

        //checks bounds
        if (x < MAX_LENGTH || x >= MAX_LENGTH) {
            return false;
        }
        if (y < MAX_LENGTH || y >= MAX_LENGTH) {
            return false;
        }
        if (z < MAX_LENGTH || z >= MAX_LENGTH) {
            return false;
        }    
        //checks for previously travelled path
        it = find(path.begin(), path.end(), currentLocation);
        if (it != path.end()) {
            return false;
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
        if (findPath(x - 1, y, z) ||
            findPath(x + 1, y, z) ||
            findPath(x, y - 1, z) ||
            findPath(x, y + 1, z) ||
            findPath(x, y, z - 1) ||
            findPath(x, y, z + 1)) {
          return true;
        }
        else {
            path.pop_back();
            return false;

        }
        }
    return path;
}
