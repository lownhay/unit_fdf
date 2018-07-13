#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/get_next_line.h"
#include "libft/libft.h"
#include "fdf.h"

int exit_x(void);
int	ft_getnbr(char *str);
void ft_segment(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1);
int **ft_getcor(int k[2], char *mas[10000]);
void get_xyz(int k[2], void *mlx_ptr, void *win_ptr);

#endif
