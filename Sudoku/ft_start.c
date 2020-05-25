# include "sudoku.h"
# include <stdlib.h>
# include <unistd.h>

void	ft_display_grid(int **sudoku)
{
	int x;
	int y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			ft_putnbr(sudoku[x][y]);
			if (y < 8)
				ft_putchar(' ');
			y++;
		}
		if (x < 9)
			ft_putchar('\n');
		x++;
	}
}

void	ft_free(int **sudoku)
{
	int i;

	i = 0;
	while (sudoku[i])
	{
		free(sudoku[i]);
		i++;
	}
	free(sudoku);
}

int		**ft_start(char **str, int x, int y, int z)
{
	int **sudoku;

	if ((sudoku = (int**)malloc(sizeof(int*) * 9)) == NULL)
		return (NULL);
	sudoku[9] = NULL;
	while (x < 9)
	{
		if ((sudoku[x] = (int*)malloc(sizeof(int) * 9)) == NULL)
			return (NULL);
		sudoku[x][9] = '\0';
		y = 0;
		while (y < 9)
		{
			if (str[z][y] == '.')
				sudoku[x][y] = 0;
			else
				sudoku[x][y] = str[z][y] - '0';
			y++;
		}
		x++;
		z++;
	}
	return (sudoku);
}
