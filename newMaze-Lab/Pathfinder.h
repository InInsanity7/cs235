#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "PathfinderInterface.h"
#include <iostream>
#include <string>
#include <vector>

class Pathfinder: public PathfinderInterface {
public:
	Pathfinder() {}
	 ~Pathfinder() {}

	 string toString() const;

	 void createRandomMaze();

	 bool importMaze(string file_name);

	 vector<string> solveMaze();

private:

    int maze [MAZE_LENGTH][MAZE_LENGTH][MAZE_LENGTH];
    std::vector<std::string> path;

};

#endif
