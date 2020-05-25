# include "sudoku.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
int		ft_is_d_or_p(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (-1);
		i++;
	}
	return (1);
}

int		ft_tmp_memory(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}
void	ft_tmp_zero(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = '0';
		i++;
	}
}

char	*ft_alloc(char *tmp)
{
	if ((tmp = (char*)malloc(sizeof(char) * 9)) == NULL)
		return (0);
	tmp[9] = '\0';
	return (tmp);
}

int		ft_check_double_l(char **str, int i, int j, int k)
{
	char *tmp = NULL;

	tmp = ft_alloc(tmp);
	while (str[i])
	{
		j = 0;
		k = 0;
		ft_tmp_zero(tmp);
		while (str[i][j])
		{
			if (ft_tmp_memory(tmp, str[i][j]) == 0)
				return (0);
			if (str[i][j] != '.')
			{
				tmp[k] = str[i][j];
				k++;
			}
			j++;
		}
		i++;
	}
	free(tmp);
	return (1);
}

int		ft_check_double_c(char **str, int i, int j, int k)
{
	char *tmp = NULL;

	tmp = ft_alloc(tmp);
	while (j < 9)
	{
		k = 0;
		ft_tmp_zero(tmp);
		while (i < 10)
		{
			if (ft_tmp_memory(tmp, str[i][j]) == 0)
				return (0);
			if (str[i][j] != '.')
			{
				tmp[k] = str[i][j];
				k++;
			}
			i++;
		}
		j++;
	}
	free(tmp);
	return (1);
}

int		 ft_check(char **str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (ft_strlen(str[i]) != 9)
			return (0);
		else if (ft_is_d_or_p(str[i]) < 0)
			return (0);
		i++;
	}
	if (ft_check_double_l(str, 1, 0, 0) == 0)
		return (0);
	if (ft_check_double_c(str, 1, 0, 0) == 0)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int **sudoku;
	if (ac != 10)
	{
		ft_putstr("Error1\n");
		return (0);
	}
	if (ft_check(av) == 0)
	{
		ft_putstr("Error2\n");
		return (0);
	}
	sudoku = ft_start(av, 0, 0, 1);
	if (ft_solve(sudoku, 0) == 0)
	{
		ft_putstr("Error3\n");
		return (0);
	}
	ft_display_grid(sudoku);
	ft_free(sudoku);
	return (0);
}
