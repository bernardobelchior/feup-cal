/*
 * labirinth.cpp
 */

#include "Labirinth.h"

#include <iostream>
using namespace std;



Labirinth::Labirinth(int values[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			labirinth[i][j]=values[i][j];
}


void Labirinth::initializeVisited(int x, int y)
{
	for (int i = 0; i < 10; i++)
		for (int a = 0; a < 10; a++)
			visited[i][a] = false;
	visited[y][x] = true;
}


void  Labirinth::printLabirinth()
{
	for (int i = 0; i < 10; i++)
	{
		for (int a = 0; a < 10; a++)
			cout << labirinth[i][a] << " ";

		cout << endl;
	}
}


bool Labirinth::findGoal(int x, int y)
{
	initializeVisited(x, y);
	return findActualGoal(x, y);
}

bool Labirinth::findActualGoal(int x, int y) {

	if(labirinth[y][x] == 2)
		return true;

	//Goes right
	if(labirinth[y][x+1] != 0 && visited[y][x+1] == false){
		visited[y][x+1] = true;
		if(findActualGoal(x + 1, y))
			return true;
	}

	//Goes down
	if(labirinth[y+1][x] != 0 && visited[y+1][x] == false){
		visited[y+1][x] = true;
		if(findActualGoal(x, y+1))
			return true;
	}

	//Goes left
	if(labirinth[y][x-1] != 0 && visited[y][x-1] == false){
		visited[y][x-1] = true;
		if(findActualGoal(x-1, y))
			return true;
	}

	//Goes up
	if(labirinth[y-1][x] != 0 && visited[y-1][x] == false){
		visited[y-1][x] = true;
		if(findActualGoal(x, y-1))
		return true;
	}

	return false;
}


