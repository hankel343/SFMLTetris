#include "ScoreBoard.h"

ScoreBoard::ScoreBoard()
{
}

void ScoreBoard::ReadScoreFile()
{
	ifstream inFile;
	inFile.open("scores.txt");

	if (!inFile)
		cout << "Owie oochie owie my input file ouch";

	char chInput = '0';

	while (inFile.get(chInput))
	{
		if (pScores == nullptr) {
			ScoreEntry* pNewScore = new ScoreEntry;
			pNewScore->strName = "";
			pNewScore->strScore = "";

			pScores = pCurrentScore = pNewScore;
		}
		else if (chInput == '\n') {

			while (pCurrentScore->pNext != NULL)
				pCurrentScore = pCurrentScore->pNext;

			ScoreEntry* pNewScore = new ScoreEntry;
			pNewScore->strName = "";
			pNewScore->strScore = "0";

			pCurrentScore->pNext = pNewScore;
			pCurrentScore = pNewScore;
		}

		if (chInput >= 65 && chInput <= 122)
		{
			pCurrentScore->strName += chInput;

		}
		else if (chInput >= 48 && chInput <= 57) {

			pCurrentScore->strScore += chInput;

		}
	}
}

ScoreBoard::~ScoreBoard()
{
	delete[] pScores;
	delete pCurrentScore;
}