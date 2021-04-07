#include "ScoreBoard.h"

ScoreBoard::ScoreBoard()
{
	inFile.open("scores.txt");

	if (!inFile) cout << "Score file failed to open.\n";

	char ch;
	while (inFile.get(ch))
	{
		if (ch == '\n')
			nNumberOfEntries++;
	}

	inFile.close();

	pScores = new ScoreEntry[nNumberOfEntries];
}

void ScoreBoard::ReadScoreFile()
{
	inFile.open("scores.txt");
	char chInput;
	for (int i = 0; i < nNumberOfEntries; i++)
	{
		string strName = "";
		string strScore = "";
		while (inFile.get(chInput))
		{
			if (chInput == '\n')
				break;

			if (chInput >= 65 && chInput <= 122)
				strName += chInput;
			else if (chInput >= 48 && chInput <= 57)
				strScore += chInput;
		}
		pScores[i].strEntryName = strName;
		pScores[i].nScore = ConvertStringToInt(strScore);
	}
	inFile.close();

	SortScores();
}

int ScoreBoard::ConvertStringToInt(string strScore)
{
	int nPlaceValue = strScore.length();
	int nRadix = 0; //Current value read in
	int nIntValue = 0; //Value to be summed and returned from this function.
	for (int i = 0; i < strScore.length(); i++, nPlaceValue--)
	{
		nRadix = strScore[i] - '0';
		
		for (int j = nPlaceValue; j > 1; j--)
		{
			nRadix *= 10;
		}

		nIntValue += nRadix;
	}

	return nIntValue;
}

void ScoreBoard::SortScores()
{
	/*Selection Sort*/
	int nIndexOfMax = 0;
	for (int nCurrent = 0; nCurrent < nNumberOfEntries - 1; nCurrent++)
	{
		nIndexOfMax = nCurrent;
		for (int j = nCurrent + 1; j < nNumberOfEntries; j++)
		{
			if (pScores[j].nScore > pScores[nIndexOfMax].nScore)
				nIndexOfMax = j;
		}

		if (pScores[nCurrent].nScore < pScores[nIndexOfMax].nScore)
			Swap(pScores[nCurrent], pScores[nIndexOfMax]);
	}
}

void ScoreBoard::Swap(ScoreEntry& item1, ScoreEntry& item2)
{
	struct ScoreEntry TempStruct = item1;
	item1 = item2;
	item2 = TempStruct;
}

ScoreBoard::~ScoreBoard()
{
	delete[] pScores;
}