#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ScoreEntry
{
	string strName;
	string strScore;
	ScoreEntry* pNext;
};

class ScoreBoard
{
private:
	ScoreEntry* pScores = nullptr;
	ScoreEntry* pCurrentScore = nullptr;
	ofstream outFile;
	ifstream inFile;

public:
	ScoreBoard();
	~ScoreBoard();

	void ReadScoreFile();


};

#endif SCOREBOARD_H