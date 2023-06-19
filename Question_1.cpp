#include <iostream>
#include <ctime>
#include<cstdlib>
#include<fstream>

using namespace std;

void Deallocation(char** array, int rows)
{
	if (array != 0)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[]array[i];

		}
		delete[] array;
	}
}

//This function is used to count the number of words in the input file
int RowsCounter()   
{
	ifstream fin("input.txt");
	int rows = 0; 
	char ch;
	while (fin)
	{
		fin.get(ch);

		if (ch == '\n')
		{
			rows++;
		}

	}
	rows++;
	fin.close();
	return rows;
}

//This function is used to calculate the length of word without calculating spaces
int StringLenghtWithoutSpace(char* str)   
{
	int strLen = 0;
	int index = 0;

	while (str[index] != '\0')
	{
		if (str[index] != ' ')
		{
			strLen++;

		}
		index++;
	}

	return strLen;
}

//Calculate the size of grid by finding the maximum number by comparison with rows and cols
int Grid_Size(char** Grid)     //this function finds the dimension of the wordSearch Grid
{
	int maximum = 0;
	int rows = RowsCounter();

	int cols;

	for (int i = 0; i < rows; i++)
	{
		cols = StringLenghtWithoutSpace(Grid[i]);
		if (cols > maximum)
		{
			maximum = cols;
		}
	}

	if (rows > maximum)    
	{
		maximum = rows;
	}
	maximum = maximum + maximum;

	return maximum;
}

//Sorts the word according to their length
char** sortArray(char** Grid, int rows)    
{
	string temp_Array[100];

	for (int i = 0; i < rows; i++)
	{
		temp_Array[i] = Grid[i];
	}
	char** sortedArray = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		int length = temp_Array[i].length();
		sortedArray[i] = new char[length + 1];
		int k = 0;
		int j = 0;

		for (j = 0; j < length && k < length + 1; j++)
		{
			if (temp_Array[i][k] != ' ')
			{
				sortedArray[i][j] = temp_Array[i][k];
				k++;
			}
			else
			{
				k++;
				sortedArray[i][j] = temp_Array[i][k];
				k++;
			}
		}
		sortedArray[i][j] = '\0';
	}
	return sortedArray;
}

//Takes Input from File
char** ReadWordsFromFile()
{

	ifstream fin("Input.txt");
	const int rows = RowsCounter();

	char** Grid = new char* [rows];
	if (fin)
	{

		char abc[80];
		//fin.ignore();

		int i = 0;

		while (i < rows)
		{

			fin.getline(abc, 80);
			int cols = 0;
			cols = strlen(abc);
			*(Grid + i) = new char[cols + 1];
			int j = 0;
			for (j = 0; j < cols; j++) //deep copying
			{
				*(*(Grid + i) + j) = abc[j];
			}
			Grid[i][j] = '\0';
			i++;

		}
	}
	fin.close();


	return Grid;

}

//It initializes the grid to staric(*) to flag out all allocated grid
char** Initialize_Grid(char** Grid)
{
	int max = Grid_Size(Grid);
	char** grid = new char* [max];

	for (int i = 0; i < max; i++)
	{
		grid[i] = new char[max + 1];

	}

	for (int i = 0; i < max; i++)
	{
		int j = 0;
		for (j = 0; j < max; j++)
		{


			grid[i][j] = '*';


		}
		grid[i][j] = '\0';
	}

	return grid;

}

//It is used to Fill the remaining Grid
void Fill_All_Spaces(char**& grid, int max)
{
	for (int i = 0; i < max; i++)
	{

		for (int j = 0; j < max; j++)
		{


			if (grid[i][j] == '*')
			{

				char Letter;
				do {
					grid[i][j] = rand();


				} while (!(grid[i][j] >= 65 && grid[i][j] <= 90));
			}


		}

	}
}

//Generates Random Number
int RandomNumber(int number)
{
	int random;
	srand(time(0));
	random = 1 + rand() % number;
	return random;
}

//flags if the position to place an alphabet is valid or not
bool Place_Check(char** Grid, char* list, int row, int col, int orientation, int Max)
{
	int length = strlen(list);
	length = length - 1;

	bool flag = true;
	if (orientation == 1)
	{



		for (int n = col; n <= col + length && flag == true; n++)
		{
			if (Grid[row][n] != '*' || col + length == Max || col + length > Max)
			{
				flag = false;


			}

		}
	}
	if (orientation == 2)
	{

		for (int n = col; n >= col - length && flag == true; n--)
		{
			if (Grid[row][n] != '*' || col - length == 0 || col - length < 0)
			{
				flag = false;

			}
		}
	}
	if (orientation == 3)
	{


		for (int m = row; m < Max && flag == true; m++)
		{
			if (Grid[m][col] != '*' || row + length == Max || row + length > Max)
			{
				flag = false;

			}

		}
	}
	if (orientation == 4)
	{

		for (int m = row; m >= row - length && flag == true; m--)
		{
			if (Grid[m][col] != '*' || row - length == 0 || row - length < 0)
			{
				flag = false;

			}
		}
	}
	if (orientation == 5)
	{
		if ((row + length) > Max - 1 || (row - length) < 0)
		{
			flag = false;
			return flag;
		}

		for (int i = 0; i <= length && flag == true; i++)  //top left to bottom right
		{
			if (Grid[row + i][row + i] != '*')
			{
				flag = false;

			}
		}

	}
	if (orientation == 6)
	{
		if ((row + length) > Max - 1 || (row - length) < 0)
		{
			flag = false;
			return flag;
		}
		for (int i = 0; i <= length && flag == true; i++)  //top right to bottom left
		{
			if (Grid[row + i][row - i] != '*')
			{
				flag = false;

			}
		}

	}
	if (orientation == 7)
	{
		if ((row + length) > Max - 1 || (row - length) < 0)
		{
			flag = false;
			return flag;
		}
		for (int i = 0; i <= length && flag == true; i++)  //bottom left to top right
		{
			if (Grid[row - i][row + i] != '*')
			{
				flag = false;

			}
		}

	}
	if (orientation == 8)
	{
		if ((row - length) < 0)
		{
			flag = false;
			return flag;
		}

		for (int i = 0; i <= length && flag == true && (row - length) > -1; i++)  //bottom rightt to top left
		{
			if (Grid[row - i][row - i] != '*')
			{
				flag = false;

			}
		}
	}
	return flag;
}

void Left_To_Right(char**& Grid, char** array, int length, int wordNumber, int row, int col)
{
	for (int j = 0; j <= length; j++)
	{
		Grid[row][col - j] = array[wordNumber][j];
	}
}

void Right_To_Left(char**& Grid, char** array, int length, int wordNumber, int row, int col)
{
	for (int j = 0; j <= length; j++)
	{
		Grid[row][col + j] = array[wordNumber][j];
	}
}

void Top_To_Bottom(char**& Grid, char** array, int length, int wordNumber, int row, int col)
{
	for (int j = 0; j <= length; j++)
	{
		Grid[row + j][col] = array[wordNumber][j];
	}
}

void Bottom_To_Top(char**& Grid, char** array, int length, int wordNumber, int row, int col)
{
	for (int j = 0; j <= length; j++)   //bottom to top
	{
		Grid[row - j][col] = array[wordNumber][j];
	}
}

void TopLeft_To_BottomTight(char**& Grid, char** array, int length, int wordNumber, int row)
{
	for (int j = 0; j <= length; j++)
	{
		Grid[row + j][row + j] = array[wordNumber][j];
	}
}

void TopRight_To_BottomLeft(char**& Grid, char** array, int length, int wordNumber, int row)
{
	for (int j = 0; j <= length; j++)   //top right to bottom left
	{
		Grid[row + j][row - j] = array[wordNumber][j];
	}
}

void BottomLeft_To_TopRight(char**& Grid, char** array, int length, int wordNumber, int row)
{
	for (int j = 0; j <= length; j++)   //bottom left to top right
	{
		Grid[row - j][row + j] = array[wordNumber][j];
	}
}

void BottomRight_To_TopLeft(char**& Grid, char** array, int length, int wordNumber, int row)
{
	for (int j = 0; j <=length; j++)  //bottom rightt to top left
	{
		Grid[row - j][row - j] = array[wordNumber][j];
	}
}
void PlaceWord(char**& Grid, char** array)
{
	int Rows = RowsCounter();
	int max = Grid_Size(array);

	for (int wordNumber = Rows - 1; wordNumber >= 0; wordNumber--)
	{
		int row, col, orientation;
		int length = strlen(array[wordNumber]);
		length = length - 1;
		bool flag = false;
		col = Rows - length - 1;
		if (wordNumber == Rows - 1)
		{
			BottomRight_To_TopLeft(Grid, array, length, wordNumber, 9);
			wordNumber--;
			length = strlen(array[wordNumber]);
			length = length - 1;
		}
		do
		{
			row = RandomNumber(max);
		
			row = row - 1;

			orientation = RandomNumber(7);
			flag = Place_Check(Grid, array[wordNumber], row, col, orientation, max);

		} while (flag == false);
		if (flag == true)
		{
			if (orientation == 1)   //right to left
			{
				Right_To_Left(Grid, array, length, wordNumber, row, col);
			}
			if (orientation == 2)   //left to right
			{
				Left_To_Right(Grid, array, length, wordNumber, row, col);

			}
			if (orientation == 3)  //top to bottom
			{
				Top_To_Bottom(Grid, array, length, wordNumber, row, col);
			}
			if (orientation == 4)
			{
				Bottom_To_Top(Grid, array, length, wordNumber, row, col);

			}
			if (orientation == 5)   //top left to bottom right
			{
				TopLeft_To_BottomTight(Grid, array, length, wordNumber, row);
			}
			if (orientation == 6)
			{
				TopRight_To_BottomLeft(Grid, array, length, wordNumber, row);

			}
			if (orientation == 7)
			{
				BottomLeft_To_TopRight(Grid, array, length, wordNumber, row);
			}
			if (orientation == 8)
			{
				BottomRight_To_TopLeft(Grid, array, length, wordNumber, row);

			}
		}
	}


	Fill_All_Spaces(Grid, max);

}
void PrintAllNames(char** Grid, int max)
{
	ofstream fout("Output.txt");
	fout << endl << endl;

	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			if (Grid[i][j] != ' ')
			{


				fout << Grid[i][j] << " ";
			}

		}
		fout << endl;
	}

}

void main()
{
	cout << endl << endl << "------------------------WORD SEARCH PUZZLE-------------------------------\n\n\n";
	cout << "Result Displayed in Output.txt\n\n";
	char** Grid = 0;
	int max;
	int rows = RowsCounter();
	char** grid = 0;
	char** sorted = 0;
	Grid = ReadWordsFromFile();

	max = Grid_Size(Grid);
	sorted = sortArray(Grid, rows);
	
	Deallocation(Grid, rows);
	grid = Initialize_Grid(sorted);
	PrintAllNames(grid, max);
	PlaceWord(grid, sorted);
	PrintAllNames(grid, max);
	Deallocation(sorted, rows);
}