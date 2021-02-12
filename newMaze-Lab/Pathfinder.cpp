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
    std::stringstream ss;
    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            for (int k = 0; k < MAX_LENGTH; k++) {
                ss << maze[i][j][k] << " ";
            }
            ss << std::endl;
        }
    }
    return ss.str(); 
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
    std::cout << "importMaze from "<<file_name<<std::endl;
    std::ifstream file (file_name.c_str());
    int tmpMaze[MAX_LENGTH][MAX_LENGTH][MAX_LENGTH];

		if (file.is_open()) {
            std::string line;
			int row_count = 0;
            std::cout << "is open" << std::endl;
            for (int xval = 0; xval < MAX_LENGTH; xval++) {

			for(int yval = 0; yval < MAX_LENGTH; yval++) {
				getline(file, line);
                std::stringstream ss(line);
				for(int zval = 0; zval < MAX_LENGTH; zval++) {
					int value;
					ss >> value;
                    if (value == 0 || value == 1) {
					    cout << "["<<xval<<"]["<<yval<<"]["<<zval<<"]="
                             <<value<<endl;
				    	tmpMaze[xval][yval][zval] = value;
                    }
                    else {
                        std::cout << "bad number" << std::endl;
                        return false;
                    }
				}
            }
            if (file.eof()) {
                std::cout << "reached end of file too soon" << std::endl;
                return false;
            }
            else {
                getline(file, line);
            }
		}
        for (int x = 0; x < MAZE_LENGTH; x++) {
            for (int y = 0; y < MAZE_LENGTH; y++) {
                for (int z = 0; z < MAZE_LENGTH; z++) {
                    maze[x][y][z] = tmpMaze[x][y][z];
                }
            }
        }

	    return(true);
        }
}




std::vector<std::string> Pathfinder::solveMaze() {
   AMaze theMaze;
   if (theMaze.findPath(0,0,0)) {
   return theMaze.path;
}
   else 
        std::vector<string> empty;
        return empty;
   }
}
