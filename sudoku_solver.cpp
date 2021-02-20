//sudoku solver
//put 0 in place of blanks
//author - aryan jain
//date - 2/7/2021
#include<iostream>
using namespace std;
int check(int u[][9], int row, int col, int n)
{
	int startrow = 0, startcol = 0;
	if (row <= 2)
		startrow = 0;
	else if (row <= 5)
		startrow = 3;
	else if (row <= 8)
		startrow = 6;
	if (col <= 2)
		startcol = 0;
	else if (col <= 5)
		startcol = 3;
	else if (col <= 8)
		startcol = 6;
	int i, j;
	for (i = startrow;i < 3 + startrow;i++)
	{
		for (j = startcol;j < 3 + startcol;j++)
		{
			if (u[i][j] == n)
				return 0;
		}
	}
	for (i = 0;i < 9;i++)
	{
		if (u[row][i] == n)
			return 0;
		if (u[i][col] == n)
			return 0;
	}

	// 	int m;
	// 	int r, c;

	// 	for (m = 1;m <= 9;m++)
	// 	{
	// 		int c1 = 1, c2 = 1, c3 = 1, count = 0;
	// 		for (i = startrow;i < 3 + startrow;i++)
	// 		{
	// 			for (j = startcol;j < 3 + startcol;j++)
	// 			{
	// 				if (u[i][j] == m)
	// 					c1 = 0;
	// 			}
	// 		}
	// 		if (c1 == 0)
	// 			continue;
	// 		for (i = startrow;i < 3 + startrow;i++)
	// 		{
	// 			for (j = startcol;j < 3 + startcol;j++)
	// 			{
	// 				if (u[i][j] == 0)
	// 				{
	// 					int c2 = 1;c3 = 1;
	// 					for (r = 0;r < 9;r++)
	// 					{
	// 						if (u[r][j] == m)
	// 							c2 = 0;
	// 					}
	// 					for (c = 0;c < 9;c++)
	// 					{
	// 						if (u[i][c] == m)
	// 							c3 = 0;
	// 					}
	// 					if (c2 == 1 && c3 == 1)
	// 						count++;
	// 				}

	// 			}
	// 		}
	// 		if (count == 0)
	// 		{
	// 			return 0;
	// 		}
	// 	}
	return 1;
}
void check_row(int u[][9], int row)
{
	int n;
	int i, j, col;
	for (n = 1;n <= 9;n++)
	{
		int count = 0;
		for (col = 0;col < 9;col++)
		{
			if (u[row][col] == 0 && check(u, row, col, n) == 1)
			{
				i = row;
				j = col;
				count++;
			}
		}
		if (count == 1)
		{
			u[i][j] = n;
		}
	}
}
void check_col(int u[][9], int col)
{
	int n;
	int i, j, row;
	for (n = 1;n <= 9;n++)
	{
		int count = 0;
		for (row = 0;row < 9;row++)
		{
			if (u[row][col] == 0 && check(u, row, col, n) == 1)
			{
				i = row;
				j = col;
				count++;
			}
		}
		if (count == 1)
		{
			u[i][j] = n;
		}
	}
}
int check_cube(int u[][9], int cube)
{
	int n, count = 0;
	int startrow, startcol;
	if (cube == 1 || cube == 4 || cube == 7)
		startcol = 0;
	else if (cube == 2 || cube == 5 || cube == 8)
		startcol = 3;
	else if (cube == 3 || cube == 6 || cube == 9)
		startcol = 6;
	if (cube == 1 || cube == 2 || cube == 3)
		startrow = 0;
	else if (cube == 5 || cube == 4 || cube == 6)
		startrow = 3;
	else if (cube == 9 || cube == 8 || cube == 7)
		startrow = 6;
	int i, j, row, col;

	for (n = 1;n <= 9;n++)
	{
		int c1 = 1, c2 = 1, c3 = 1, count = 0, R, C;
		for (i = startrow;i < 3 + startrow;i++)
		{
			for (j = startcol;j < 3 + startcol;j++)
			{
				if (u[i][j] == n)
					c1 = 0;
			}
		}
		if (c1 == 0)
			continue;
		for (i = startrow;i < 3 + startrow;i++)
		{
			for (j = startcol;j < 3 + startcol;j++)
			{
				if (u[i][j] == 0)
				{
					int c2 = 1;c3 = 1;
					for (row = 0;row < 9;row++)
					{
						if (u[row][j] == n)
							c2 = 0;
					}
					for (col = 0;col < 9;col++)
					{
						if (u[i][col] == n)
							c3 = 0;
					}
					if (c2 == 1 && c3 == 1)
					{
						count++;
						R = i;
						C = j;
					}
				}

			}
		}
		if (count == 0)
		{
			return 0;
		}
		if (count == 1)
			u[R][C] = n;
	}
	return 1;

}
void solve(int u[][9])
{
	int i, j, row, col;
	int t = 81;
	while (t--)
	{
		for (row = 0;row < 9;row++)
		{
			check_row(u, row);
		}
		for (col = 0;col < 9;col++)
		{
			check_col(u, col);
		}
		for (int cube = 1;cube <= 9;cube++)
		{
			check_cube(u, cube);
		}
	}
}
void fill(int s[][9], int u[][9], int row, int col, int x)
{
	int i, j, n, R, C;
	if (row > 8) return;
	if (x == 1 && (!(row == 0 && col == 0)))
	{
		R = row;
		C = col;
		if (col != 0)
			C = C - 1;
		else
		{
			R = R - 1;
			C = 8;
		}
		for (i = R;i >= 0;i--)
		{
			for (j = 8;j >= 0;j--)
			{
				if (i == R && j > C)
					j = C;
				if (s[i][j] == 0)
				{
					int z = u[i][j];
					while (1)
					{
						if (z == 9)
						{
							u[i][j] = 0;
							fill(s, u, i, j, 1);
							break;
						}
						z += 1;
						if (check(u, i, j, z) == 1)
						{
							u[i][j] = z;
							fill(s, u, i, j, 0);
							break;
						}
					}
					return;

				}
			}
		}
	}
	else {
		for (i = 0;i < 9;i++)
		{
			for (j = 0;j < 9;j++)
			{

				if (u[i][j] == 0)
				{
					for (n = 1;n <= 9;n++)
					{
						if (check(u, i, j, n) == 1)
						{
							u[i][j] = n;

							fill(s, u, i, j, 0);
							return;
						}
						else
						{
							if (n == 9)
							{
								u[i][j] = 0;
								fill(s, u, i, j, 1);
								return;
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	int u[9][9], s[9][9];
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			cin >> u[i][j];
			s[i][j] = u[i][j];
		}
	}
	solve(u); //fills unique value. Made it to reduce burden on recursion
	fill(s, u, 0, 0, 0);
	for (int a = 0;a < 9;a++)
	{
		for (int b = 0;b < 9;b++)
		{
			cout << u[a][b] << " ";
		}cout << "\n";
	}cout << "\n";

}