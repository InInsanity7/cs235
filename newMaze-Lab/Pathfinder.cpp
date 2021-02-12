#include "maze.h"
#include "Pathfinder.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>



Pathfinder::Pathfinder() {
    srand(time(0));

    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            for (int k = 0; k < MAX_LENGTH; k++) {
                maze[i][j][k] = 1;
            }
        }
    }
}
    
Pathfinder::~Pathfinder() {}
    
std::string Pathfinder::toString() const {
    std::string mazeString;
    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            for (int k = 0; k < MAX_LENGTH; k++) {
                mazeString += maze[i][j][k];
                mazeString += " ";
            }
            mazeString += "\n";
        }
    }
    return mazeString;
}



void Pathfinder::createRandomMaze() {
    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            for (int k = 0; k < MAX_LENGTH; k++) {
                maze[i][j][k] = (rand() % 2);
            }
        }
    }
    maze[0][0][0] = 1;
    maze[4][4][4] = 1;
}

bool Pathfinder::importMaze(string file_name) {
    std::string tempMaze[MAX_LENGTH][MAX_LENGTH][MAX_LENGTH];
    string line;  
    std::ifstream ifs;
    
    ifs.open(file_name, std::ifstream::in);
    if(!ifs.is_open()) {
        std::cout << "File didn't open" << std::endl;
        return false;
    }

    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
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
            if(line.size() != MAX_LENGTH*2-1) {
                cout << "line wrong size: actual " << line.size() << 
                        ", expected: " << MAX_LENGTH*2-1 << endl;
            return false;
            }
            for (int k = 0; k < MAX_LENGTH; k++) {
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
    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            for (int k = 0; k < MAX_LENGTH; k++) {
                //FIXME
                int tempInt;
                std::cout << tempMaze[i][j][k] << std::endl;
                tempInt = std::stoi(tempMaze[i][j][k]);
                maze[i][j][k] = tempInt;
            }
        }
    }
    maze[0][0][0] = 1;
    maze[4][4][4] = 1;

    return true;
}




std::vector<std::string> Pathfinder::solveMaze() {
   AMaze theMaze;
   if (theMaze.findPath(0,0,0)) {
   return theMaze.path;
}
   else {
        std::vector<string> empty;
        return empty;
   }
}
