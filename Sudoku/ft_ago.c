

int		ft_check_line(int **sudoku, int val, int i)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (sudoku[i][j] == val)
			return (0);
		j++;
	}
	return (1);
}

int		ft_check_col(int **sudoku, int val, int j)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (sudoku[i][j] == val)
			return (0);
		i++;
	}
	return (1);
}

int		ft_respect_norma(int **sudoku, int k, int i, int j)
{
	if (ft_check_line(sudoku, k, i) == 1 && ft_check_col(sudoku, k, j) == 1)
		return (1);
	return (0);
}
int		ft_solve(int **sudoku, int position)
{
	int i;
	int j;
	int k;

	if (position == 9 * 9)
		return (1);
	i = position / 9;
	j = position % 9;
	if (sudoku[i][j] != 0)
		return (ft_solve(sudoku, position + 1));
	k = 1;
	while (k <= 9)
	{
		if (ft_respect_norma(sudoku, k, i, j) == 1)
		{
			sudoku[i][j] = k;
			if (ft_solve(sudoku, position+ 1) == 1)
				return (1);
		}
		k++;
	}
	sudoku[i][j] = 0;
	return (0);
}
