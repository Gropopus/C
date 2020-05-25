# ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
void	ft_free(int **sudoku);
void	ft_display_grid(int **sudoku);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		**ft_start(char **str, int x, int y, int z);
int		ft_check_line(int **sudoku, int val, int i);
int		ft_check_col(int **sudoku, int val, int j);
int		ft_check_grid(int **sudoku, int val, int i, int j);
int		ft_solve(int **sudoku, int position);

#endif
