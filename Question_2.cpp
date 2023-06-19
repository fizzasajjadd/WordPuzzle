#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

//cHECKS THE GRID FROM HORIZONTAL LEFT TO RIGHT
int HorizontalL_R(ofstream& fout, string Letter, int row, int col, char data[][100])
{
	int l = 0;
	int m = 0;

	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			m = j;

			while (data[i][m] == Letter[l] && Letter[l] != '\0')
			{
				m++;
				l++;
				if (Letter[l] == '\0')
				{

					fout << "{" << i << " ," << j << "} ";
					fout << "{" << i << " , " << (j - 1) + Letter.size() << "}" << endl;
					return 0;

				}

			}
			l = 0;
		}
	}
	return 1;
}

//cHECKS THE GRID FROM HORIZONTAL RIGHT TO LEFT
int HorizontalR_L(ofstream& fout, string Letter, int row, int  col, char data[][100])
{
	int l = 0;
	int	m = 0;

	for (int i = 0; i <= row; i++)
	{

		for (int j = col - 1; j >= 0; j--)
		{
			m = j;

			while (data[i][m] == Letter[l] && Letter[l] != '\0')
			{

				m--;
				l++;

				if (Letter[l] == '\0')
				{

					fout << "{" << i << " ," << j << "} ";
					fout << "{" << i << " ," << j - Letter.size() + 1 << "}" << endl;
					return 0;
				}
			}
			l = 0;
		}
	}
	return 1;
}

//cHECKS THE GRID FROM VERTICAL TOP TO BOTTOM
int VerticalT_B(ofstream& fout, string Letter, int col, char data[][100])
{

	int l = 0;
	int	m = 0;

	for (int j = 0; j <= col; j++)
	{
		for (int i = 0; data[i][j] != '\0'; i++)
		{
			m = i;

			while (data[m][j] == Letter[l] && Letter[l] != '\0')
			{

				m++;
				l++;

				if (Letter[l] == '\0')
				{

					fout << "{" << i << " ," << j << "} ";
					fout << "{" << i + Letter.size() - 1 << " ," << j << "}" << endl;
					return 0;
				}
			}

			l = 0;
		}
	}
	return 1;
}

//cHECKS THE GRID FROM VERTICAL BOTTOM TO TOP
int VerticalB_T(ofstream& fout, string Letter, int col, int  row, char data[][100])
{
	int l = 0;
	int m = 0;

	for (int j = 0; j < col - 1; j++)
	{
		for (int i = row - 1; i >= 0; i--)
		{
			m = i;

			while (data[m][j] == Letter[l] && Letter[l] != '\0')
			{

				m--;
				l++;

				if (Letter[l] == '\0')
				{

					fout << "{" << i << " ," << j << "} ";
					fout << "{" << i - Letter.size() + 1 << " ," << j << "}" << endl;
					return 0;
				}
			}
			l = 0;
		}
	}
	return 1;
}

//cHECKS THE GRID FROM DIAGONAL TOPLEFT TO BOTTOMRIGHT
int Diagonally_TopLeft_to_BottomRight(ofstream& fout, string Letter, int col, int  row, char data[][100])
{
	int l = 0;
	int last_row = 0;
	int last_col = 0;
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j < col - 1; j++)
		{
			last_row = i;
			last_col = j;
			while (data[last_row][last_col] == Letter[l] && Letter[l] != '\0')
			{
				last_row++;
				last_col++;
				l++;
				if (Letter[l] == '\0')
				{

					fout << "{" << i << " ," << j << "} ";
					fout << "{" << last_row - 1 << " ," << last_col - 1 << "} " << endl;
					return 0;
				}
			}
			l = 0;
		}
	}
	return 1;
}

//cHECKS THE GRID FROM DIAGONAL BOTTOMRIGHT TO TOPLEFT
int Diagonally_Bottomright_to_TopLeft(ofstream& fout, string Letter, int col, int  row, char data[][100])

{
	int a = 0;
	int last_row = 0;
	int last_col = 0;
	for (int i = row - 1; i > 0; i--)
	{
		for (int j = col - 1; j > 0; j--)
		{
			last_row = i;
			last_col = j;
			while (data[last_row][last_col] == Letter[a] && Letter[a] != '\0')
			{
				last_row--;
				last_col--;
				a++;
				if (Letter[a] == '\0')
				{

					fout << "{" << i << " ," << j << "} ";
					fout << "{" << last_row + 1 << " ," << last_col + 1 << "} " << endl;
					return 0;
				}
			}
			a = 0;
		}
	}
	return 1;
}

//cHECKS THE GRID FROM DIAGONAL TOPRIGHT TO BOTTOMLEFT
int Diagonally_TopRight_to_BottomLeft(ofstream& fout, string Letter, int col, int  row, char data[][100])
{

	int a = 0;
	int last_row = 0;
	int last_col = 0;
	for (int i = 0; i <= row; i++)
	{
		for (int j = col - 1; j > 0; j--)
		{
			last_row = i;
			last_col = j;
			while (data[last_row][last_col] == Letter[a] && Letter[a] != '\0')
			{

				last_row++;
				last_col--;
				a++;

				if (Letter[a] == '\0')
				{

					fout << "{" << i << " ," << j << "} ";
					fout << "{" << last_row - 1 << " ," << last_col + 1 << "} " << endl;
					return 0;
				}
			}
			a = 0;
		}
	}
	return 1;
}

//cHECKS THE GRID FROM DIAGONAL BOTTOMLEFT TO TOPRIGHT
int Diagonally_BottomLeft_to_TopRight(ofstream& fout, string Letter, int col, int  row, char data[][100])
{
	int a = 0;
	int last_row = 0;
	int last_col = 0;
	for (int i = row - 1; i > 0; i--)
	{
		for (int j = 0; j < col - 1; j++)
		{
			last_row = i;
			last_col = j;
			while (data[last_row][last_col] == Letter[a] && Letter[a] != '\0')
			{

				last_row--;
				last_col++;
				a++;

				if (Letter[a] == '\0')
				{

					fout << "{" << i << " ," << j << "} ";
					fout << "{" << last_row + 1 << " ," << last_col - 1 << "} " << endl;
					return 0;
				}
			}
			a = 0;
		}
	}
	return 1;
}

//FINDS THE WORD IN THE GRID BY CHECKING ALL THE ABOVE CONDITIONS
void Word_Find(ofstream& fout, char Grid[][100], string wordsearch, int rows, int cols)
{


	// Now we will pass these variables to each function in order to find the word.

	int L_R = HorizontalL_R(fout, wordsearch, rows, cols, Grid);
	int R_L = HorizontalR_L(fout, wordsearch, rows, cols, Grid);
	int T_B = VerticalT_B(fout, wordsearch, cols, Grid);
	int B_T = VerticalB_T(fout, wordsearch, cols, rows, Grid);

	int Diagonal1 = Diagonally_Bottomright_to_TopLeft(fout, wordsearch, cols, rows, Grid); //Diagonal bottom Right to top left
	int Diagonal2 = Diagonally_TopLeft_to_BottomRight(fout, wordsearch, cols, rows, Grid);  //Diagonal top left to bottom right
	int Diagonal3 = Diagonally_BottomLeft_to_TopRight(fout, wordsearch, cols, rows, Grid);  //Diagonal bottom left to top right
	int Diagonal4 = Diagonally_TopRight_to_BottomLeft(fout, wordsearch, cols, rows, Grid);  //Diagonal top right to bottom left

	//IF WORD DOES NOT EXIST 
	if (L_R == 1 && R_L == 1 && T_B == 1 &&
		B_T == 1 && Diagonal1 == 1 && Diagonal2 == 1 
		&& Diagonal3 == 1 && Diagonal4 == 1)
	{
		fout << "\nNot Found\n";
	}


}

void InputData(ifstream& fin, ofstream& fout)
{

	int Rows = 0;
	int	Cols = 0;
	int n = 0;
	char grid[100][100];		//creating a grid in which we will read data from input file.
	string Letter;

	fin >> Rows;
	fin >> Cols;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
			fin >> grid[i][j];
	}

	cout << "Rows:  " << Rows << " " << "Cols:  " << Cols << endl;
	//asking from the user on console for the number of words he wants to find
	cout << "Enter the number of Test cases : ";
	cin >> n;
	cout << "Enter " << n << " Words to be searched :  \n";
	for (int k = 0; k < n; k++)
	{
		cin >> Letter;
		Word_Find(fout, grid, Letter, Rows, Cols);
	}

}
int main()
{
	ifstream file1("input.txt");
	ofstream file2("output.txt");
	if (!file1.is_open())
	{
		cout << "File not opening\n";
	}
	else
	{
		InputData(file1, file2);
	}
	system("pause");
	return 0;
}

