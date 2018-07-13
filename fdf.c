#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/get_next_line.h"
#include "libft/libft.h"
#include "fdf.h"
//gcc fdf.c -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit
//gcc gnltry2/get_next_line.c fdf.c -L ./gnltry2/libft/ -lft -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

int exit_x(void)
{
exit(1);
}

// int ft_ab_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
// {
// 	int color;
// 	int y;
// 	int x;
// 	double k;
// 	double d;

// 	color = 0;
// 	k = ((double)(y1 - y0))/(x1-x0);
// 	d = 2 * k - 1;
// 	y = y0;
// 	x = x0 + 1;
// 	mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
// 	while (x <= x1)
// 	{
// 		if (d > 0)
// 		{
// 			d += 2 * k - 2;
// 			y++;
// 		}
// 		else
// 			d += 2 * k;
// 		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
// 		x++;
// 	}
// 	return (1);
// }

int	ft_getnbr(char *str)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		result = result * (-1);
	return (result);
}

int color = 16711680;

void ft_segment(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
	
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x1 >= x0 ? 1 : -1;
	int sy = y1 >= y0 ? 1 : -1;

	
	//printf("color = %d\n", color);
	if (dy <= dx)
	{
		//printf("color1 = %d\n", color);
		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
		for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
		{
			if ( d >0)
			{
				d += d2;
				y += sy;
			}
			else
				d += d1;
			//color += 255;
			//color += 110;
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		}
		//printf("color2 = %d\n", color);
	}
	else
	{
		//printf("color1 = %d\n", color);
		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
		for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
		{
			if ( d >0)
			{
				d += d2;
				x += sx;
			}
			else
	  			d += d1;
	  		//color += 255;
	  		//color += 110;
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		}
		//printf("color2 = %d\n", color);
	}
	//color += 32640;
}

int **ft_getcor(int k[2], char *mas[10000])
{
	int i;
	int j;
	int m;
	int p;
	int **res;

	res = (int **)malloc(sizeof(int*) * k[0]);
	i = 0;
	while (mas[i])
	{
		m = 0;
		j = 0;
		res[i] = (int *)malloc(sizeof(int) * k[1]);
		while(mas[i][m])
		{
			res[i][j] = ft_getnbr(&(mas[i][m]));
			while (mas[i][m] && mas[i][m] != ' ')
				m++;
			while (mas[i][m] && mas[i][m] == ' ')
				m++;
			j++;
		}
		i++;
	}
	return (res);
}

void get_xyz(int k[2], void *mlx_ptr, void *win_ptr)
{
	int x[2];
	int y[2];
	int kl[2];

	kl[1] = k[1];
	kl[0] = k[0];
	x[0] = 700 / k[1];
	y[0] = 400 / k[0];
	x[1] = x[0];
	y[1] = y[0];
	while (kl[0] > 0)
	{
		ft_segment(mlx_ptr, win_ptr, x[1], y[1], x[1] * k[1], y[1]);
		y[1] += x[0];
		kl[0]--;
	}
	x[1] = x[0];
	y[1] = y[0];
	color += 65280;
	while (kl[1] > 0)
	{
		ft_segment(mlx_ptr, win_ptr, x[1], y[1], x[1], y[1] * k[0]);
		x[1] += y[0];
		kl[1]--;
	}
	printf("x = %d\ny = %d\n", k[1], k[0]);
}

int main(int argc, char **argv)
{
	void *mlx_ptr;;
	void *win_ptr;
	int fd;
	char *line;
	int **cords;
	int i;
	int j[2] = {0, 0};
	int k[2];
	char *mas[10000];
	char **klop;

	if (argc != 2)
		return (0);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 900, 600, argv[1]);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &(mas[i])))
	{
		mas[i + 1] = 0;
		i++;
	}
	k[0] = i;
	klop = ft_strsplit(mas[i - 1], ' ');
	i = 0;
	while (klop[i])
		i++;
	k[1] = i;
	cords = ft_getcor(k, mas);
	while (j[0] < k[0])
	{
		j[1] = 0;
		while (j[1] < k[1])
		{
			printf("%d\t", cords[j[0]][j[1]]);
			j[1]++;
		}
		printf("\n");
		j[0]++;
	}
	get_xyz(k, mlx_ptr, win_ptr);
	i = 0;
	// while (mas[i])
	// {
	// 	printf("%s\n", mas[i]);
	// 	i++;
	// }
//	printf("%d\n", 16711680 - 16776960);
	//printf("%d\n", 16711680 - 16750080);
	mlx_hook (win_ptr, 2, 5, exit_x, 0);
	mlx_loop(mlx_ptr);
	close(fd);
}
