#include "sandpiles.h"


/**
 * _print - print a grind
 * @grid: the grid to print
 */
static void _print(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * _copy - copy grid to copied
 * @grid: the grid to be copied
 * @copied: the copy
 */
void _copy(int grid[3][3], int copied[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			copied[i][j] = grid[i][j];
}

/**
 * quick_add - add 2 grids
 * @grid: the grid 1
 * @grid0: the second grid
 */
void quick_add(int grid[3][3], int grid0[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] = grid[i][j] + grid0[i][j];
}

/**
 * sandpiles_sum - sum two sandpiles
 * @grid1: the first grid
 * @grid2: the second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int copy[3][3];
	int i, j, check;

	quick_add(grid1, grid2);
	while (1)
	{
		check = 0;
		_copy(grid1, copy);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (copy[i][j] > 3)
				{
					check = 1;
					grid1[i][j] = grid1[i][j] - 4;
					if (i - 1 >= 0)
						grid1[i - 1][j]++;
					if (i + 1 <= 2)
						grid1[i + 1][j]++;
					if (j - 1 >= 0)
						grid1[i][j - 1]++;
					if (j + 1 <= 2)
						grid1[i][j + 1]++;
				}
			}
		if (check == 0)
			break;
		printf("=\n");
		_print(copy);
	}
}
