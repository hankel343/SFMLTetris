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

	inline void Swap(ScoreEntry& item1, ScoreEntry& item2);

public:
	ScoreBoard();
	~ScoreBoard();

	void ReadScoreFile();
	int ConvertStringToInt(string strScore);
	void SortScores();
};

#endif SCOREBOARD_H