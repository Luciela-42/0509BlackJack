//Ä«µå ¼¼Àå ÇÑ¹ø¿¡ »Ì±â
#include <iostream>

using namespace std;

#define CARD 52

int main()
{
	int Data[CARD] = { 0, };
	int SplitCard[52] = { 0, };
	int DrawCard[6] = { 0, };
	int PlayerSum = 0;
	int AiSum = 0;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < CARD; ++i) //µ¦ ¼³Á¤
	{
		Data[i] = i;
	}


	for (int i = 0; i < 52; ++i) //Ä«µå ¼ÅÇÃ
	{
		int X = rand() % CARD;
		int Y = rand() % CARD;

		//Swap
		int Temp = Data[X];
		Data[X] = Data[Y];
		Data[Y] = Temp;
	}

	for (int k = 0; k < 6; ++k) //Ä«µå »Ì±â
	{
		SplitCard[k] = Data[k];

	}

	cout << "Player" << '\t' << "AI" << endl;

	//Draw
	for (int k = 0; k < 6; k++)
	{
		DrawCard[k] = SplitCard[k] % 13;

		if (DrawCard[k] == 12)
		{
			DrawCard[k] = 10;
			cout << "K" << " ";
		}
		else if (DrawCard[k] == 11)
		{
			DrawCard[k] = 10;
			cout << "Q" << " ";
		}
		else if (DrawCard[k] == 10)
		{
			DrawCard[k] = 10;
			cout << "J" << " ";
		}
		else if (DrawCard[k] == 0)
		{
			DrawCard[k] = 1;
			cout << "A" << " ";
		}
		else
		{
			DrawCard[k] += 1;
			cout << DrawCard[k] << " ";
		}

		cout << ((k % 2 == 0) ? '\t' : '\n');
	}

	for (int j = 0; j < 6; j++)
	{
		if (j % 2 == 0)
		{
			PlayerSum += DrawCard[j];
		}
		else
		{
			AiSum += DrawCard[j];
		}
	}

	cout << "Player : " << PlayerSum << endl;
	cout << "Ai : " << AiSum << endl;

	if (PlayerSum > 21 && AiSum > 21)
	{
		cout << "Player Win" << endl;
	}
	else if (PlayerSum > 21)
	{
		cout << "Player Bust / Ai Win" << endl;
	}
	else if (AiSum > 21)
	{
		cout << "Ai Bust / Player Win" << endl;
	}
	else if (PlayerSum == AiSum)
	{
		cout << "Player Win" << endl;
	}
	else if (PlayerSum > AiSum)
	{
		cout << "Player Win" << endl;
	}
	else
	{
		cout << "Ai Win" << endl;
	}

	return 0;
}
