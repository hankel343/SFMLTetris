#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ScoreEntry
{
	string strEntryName = "";
	int nScore = 0;
};

class ScoreBoard
{
private:
	ifstream inFile;
	unsigned int nNumberOfEntries = 0;
	struct ScoreEntry* pScores = nullptr;

public:
	ScoreBoard();
	~ScoreBoard();

	void ReadScoreFile();
	int ConvertStringToInt(string strScore);
};

#endif SCOREBOARD_H