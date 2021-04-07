#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Struct containing the user's three character code and their score.
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

	inline void Swap(ScoreEntry& item1, ScoreEntry& item2);
	//Pre: ScoreEntry objects have been created.
	//Post: The objects passed as arguments have their memory locations swapped.

public:
	ScoreBoard();
	~ScoreBoard();

	void ReadScoreFile();
	//Pre: File input stream opened successfully.
	//Post: Entries from the scores text file have been recorded in the pScores array.

	int ConvertStringToInt(string strScore);
	//Pre: A string has been read in from the score input file.
	//Post: The string representation of a number is converted into an integer.

	void SortScores();
	//Pre: Array pScores has been sucessfully dynamically allocated.
	//Post: The ScoreEntry objects in the pScores array are sorted according to their nScore value from greatest to least.

	//Pointer to a dynamically allocated array of ScoreEntry records.
	struct ScoreEntry* pScores = nullptr;
};

#endif SCOREBOARD_H