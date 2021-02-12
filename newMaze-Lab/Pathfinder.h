#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "PathfinderInterface.h"
#include <iostream>
#include <string>
#include <vector>

#define MAX_LENGTH 5

class Pathfinder: public PathfinderInterface {
public:
	Pathfinder();
	 ~Pathfinder();

	 string toString() const;

	 void createRandomMaze();

	 bool importMaze(string file_name);

	 vector<string> solveMaze();

private:

    int maze[MAX_LENGTH][MAX_LENGTH][MAX_LENGTH];

};

#endif
