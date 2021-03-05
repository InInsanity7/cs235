#include "maze.h"
#include "Pathfinder.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>


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

bool Pathfinder::importMaze(std::string file_name) {
    std::cout << "importMaze from "<<file_name<<std::endl;
    std::ifstream file(file_name.c_str());
    int tmpMaze[MAX_LENGTH][MAX_LENGTH][MAX_LENGTH];

		if (!file.is_open() || file.fail()) {
            std::cout << "File failed to open" << std::endl;
                    file.close();
            return false;
        }
        else {
            std::string line;
			int row_count = 0;
            std::cout << "is open" << std::endl;
            for (int xval = 0; xval < MAX_LENGTH; xval++) {

			for(int yval = 0; yval < MAX_LENGTH; yval++) {
				getline(file, line);
                //check file open and occupied
                if (file.bad() || file.fail()) {
                    std::cout << "line read fail" << std::endl;
                    file.close();
                    return false;
                }
                //remove end spaces from getline, check line size valid
                    while(line[line.size()-1] == ' ' ||
                          line[line.size()-1] == '\n' ||
                          line[line.size()-1] == '\r') {
                        line = line.substr(0, line.size()-1);
                    }
                    if(line.size() != MAX_LENGTH*2-1) {
                        cout << "line wrong size: actual " <<
                                line.size() << ", expected: " <<
                                MAX_LENGTH*2-1 << endl;
                    file.close();
                        return false;
                    }
                    //check only 0 or 1
                    for (int a = 0; a < MAX_LENGTH; a++) {
                        if (line.at(a*2) != '0' && 
                            line.at(a*2) != '1') {
                           
                            std::cout << "invalid character(s)" << std::endl;
                    file.close();
                            return false;
                        }
                    }

                std::stringstream ss(line);
				for(int zval = 0; zval < MAX_LENGTH; zval++) {
					int value;
					ss >> value;

                    //check valid numbers
                    if (value == 0 || value == 1) {
					    cout << "["<<xval<<"]["<<yval<<"]["<<zval<<"]="
                             <<value<<endl;
				    	tmpMaze[xval][yval][zval] = value;
                    }
                    else {
                        std::cout << "bad number" << std::endl;
                    file.close();
                        return false;
                    }
				}
            }
            //allow newline following maze end
                           if(!file.eof()) {
                    getline(file, line);
                }
		    }
            //check extra lines invalid
                if (!file.eof()) {
                    std::cout << "too many extra lines" << std::endl;
                    file.close();
                    return false;
                }
                //check not enough lines/characters
                if (file.eof() && 
                    tmpMaze[4][4][4] != 1 && 
                    tmpMaze[4][4][4] != 0) {
                      std::cout << "invalid file, too short." << std::endl;
                    file.close();
                      return false;
                }
                if (tmpMaze[4][4][4] != 1 || 
                         tmpMaze[0][0][0] != 1) {
                    std::cout << "invalid start/end" << std::endl;
                    file.close();
                    return false;
                }
        }
        file.close();

        //output maze buffer to class store
        for (int x = 0; x < MAX_LENGTH; x++) {
            for (int y = 0; y < MAX_LENGTH; y++) {
                for (int z = 0; z < MAX_LENGTH; z++) {
                    maze[x][y][z] = tmpMaze[x][y][z];
                }
            }
        }
  std::cout << "successful import" << std::endl;
                    file.close();
  return true;
}



std::vector<std::string> Pathfinder::solveMaze() {
   AMaze theMaze;
   if (theMaze.findPath(0,0,0)) {
   return theMaze.path;
}
   else { 
        std::vector<std::string> empty;
        return empty;
   }
}
