/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:13:09 by rparodi           #+#    #+#             */
/*   Updated: 2024/03/10 17:50:02 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <strings.h>

unsigned int	count_coins(t_mlx *mlx)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	coins;

	i = 0;
	j = 0;
	coins = 0;
	while (mlx->map[j])
	{
		while (mlx->map[j][i] != '\0')
		{
			if (mlx->map[j][i] == 'C')
				coins++;
			i++;
		}
		i = 0;
		j++;
	}
	return (coins);
}

void	ft_check_end(t_mlx *mlx, unsigned int coins)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlx->map[y] && coins == 0)
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'E' || mlx->map[y][x] == 'F')
				break ;
			x++;
		}
		if (mlx->map[y][x] == 'E' || mlx->map[y][x] == 'F')
			break ;
		y++;
	}
	if (mlx->map[y][x] == 'E' && coins == 0)
		mlx->map[y][x] = 'F';
}

void	ft_check_pos(t_mlx *mlx, int *y, int *x)
{
	while (mlx->map[*y])
	{
		*x = 0;
		while (mlx->map[*y][*x])
		{
			if (mlx->map[*y][*x] == 'P')
				break ;
			(*x)++;
		}
		if (mlx->map[*y][*x] == 'P')
			break ;
		(*y)++;
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{
	unsigned int		coins;
	int					x;
	int					y;

	x = 0;
	y = 0;
	if (keycode == 53 || keycode == 65307)
		ft_exit(mlx, NULL, 0, "Your leaving? see you! (Reason: Esc)");
	ft_check_pos(mlx, &y, &x);
	coins = count_coins(mlx);
	if (keycode == 126 || keycode == 65362 || keycode == 119 || keycode == 122)
		ft_move_up(x, y, mlx, &mlx->count);
	else if (keycode == 125 || keycode == 65364 || keycode == 115)
		ft_move_down(x, y, mlx, &mlx->count);
	else if (keycode == 65361 || keycode == 97 || keycode == 113)
		ft_move_left(x, y, mlx, &mlx->count);
	else if (keycode == 124 || keycode == 65363 || keycode == 100)
		ft_move_right(x, y, mlx, &mlx->count);
	ft_check_end(mlx, coins);
	display_map(mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;
	int		temp;

	if (argc > 2)
		ft_exit(NULL, NULL, 1, "You have to give a single maps");
	if (argc < 2)
		ft_exit(NULL, NULL, 1, "You have to give a maps to see my project !");
	temp = open(argv[1], O_RDONLY);
	if (temp < 3)
		ft_exit(NULL, NULL, 1, "The file doesn't exist");
	close(temp);
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	bzero(mlx, sizeof(t_mlx));
	if (argc == 2)
		mlx->path = argv[1];
	else
		ft_exit(mlx, NULL, 1, "You have to give a map to see my project");
	ft_init_value_mlx(&(*mlx));
	if (!mlx)
		ft_exit(mlx, NULL, 1, "The allocation of mlx has crashed");
	mlx = ft_init_mlx(mlx, argc, argv);
	return (0);
}
