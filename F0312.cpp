#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void MapCreate(int Row, int Col, int *Arrayptr, int *Playerpos)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (i == 0 || j == 0 || i== (Row-1) || j == (Col-1))
			{
				Arrayptr[i * Col + j] = 1;

			}
			else if (i == Playerpos[0] && j == Playerpos[1])
			{
				Arrayptr[i * Col + j] = 2;
			}
			else
			{
				Arrayptr[i * Col + j] = 0;
			}
			
		}

	}
}

void PrintMap(int Row, int Col, int* Arrayptr)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			int val = Arrayptr[i * Col + j];
			if (val == 1)
			{
				cout << '*';
			}
			else if (val == 2)
			{
				cout << "P";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}

int main()
{
	int Row = 0;
	int Col = 0;
	int PRow = 0;
	int PCol = 0;

	cout << "How many rows for the map?";
	cin >> Row;
	cout << "How many cols for the map?";
	cin >> Col;

	int* Map = new int[Row * Col];
	int* PlayerPos = new int[2]{};

	cout << "Player position in X(row)?";
	cin >> PRow;
	cout << "Player position in Y(col)?";
	cin >> PCol;
	PlayerPos[0] = PRow;
	PlayerPos[1] = PCol;
	//create map based on rows and cols
	MapCreate(Row, Col, Map, PlayerPos);
	PrintMap(Row, Col, Map);

	while (true)
	{
		if (_kbhit())
		{
			char key = _getch();
			if (key == 'w' && Map[(PRow-1) * Col + PCol] == 0)
			{
				Map[PRow * Col + PCol] = 0;
				PRow = PRow - 1;
				Map[PRow * Col + PCol] = 2;
				system("cls");
				PrintMap(Row, Col, Map);
			}
			else if (key == 'a' && Map[(PRow) * Col + (PCol-1)] == 0)
			{
				Map[PRow * Col + PCol] = 0;
				PCol = PCol -1;
				Map[PRow * Col + PCol] = 2;
				system("cls");
				PrintMap(Row, Col, Map);
			}
			else if (key == 's' && Map[(PRow + 1) * Col + PCol] == 0)
			{
				Map[PRow * Col + PCol] = 0;
				PRow = PRow + 1;
				Map[PRow * Col + PCol] = 2;
				system("cls");
				PrintMap(Row, Col, Map);
			}
			else if (key == 'd' && Map[(PRow)*Col + (PCol + 1)] == 0)
			{
				Map[PRow * Col + PCol] = 0;
				PCol = PCol + 1;
				Map[PRow * Col + PCol] = 2;
				system("cls");
				PrintMap(Row, Col, Map);
			}
		}
	}
	return 0;
}





















