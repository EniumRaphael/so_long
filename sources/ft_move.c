/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:19:03 by rparodi           #+#    #+#             */
/*   Updated: 2024/03/07 11:23:21 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(int x, int y, t_mlx *mlx, unsigned int *count)
{
	int	coins;

	coins = count_coins(mlx);
	if (y > 0 && mlx->map[y - 1][x] != '1' && mlx->map[y - 1][x] != 'E')
	{
		ft_printf("You have use %d moves\r", ++(*count));
		if (mlx->map[y - 1][x] != 'E' && mlx->map[y - 1][x] != 'F')
		{
			mlx->map[y][x] = '0';
			mlx->map[y - 1][x] = 'P';
		}
		else if (mlx->map[y - 1][x] == 'F' && coins == 0)
			ft_exit(mlx, NULL, 0, "You have finish the game !");
	}
}

void	ft_move_down(int x, int y, t_mlx *mlx, unsigned int *count)
{
	int	coins;

	coins = count_coins(mlx);
	if (mlx->map[y + 1] && mlx->map[y + 1][x] != '1'\
		&& mlx->map[y + 1][x] != 'E')
	{
		ft_printf("You have use %d moves\r", ++(*count));
		if (mlx->map[y + 1][x] != 'E' && mlx->map[y + 1][x] != 'F')
		{
			mlx->map[y][x] = '0';
			mlx->map[y + 1][x] = 'P';
		}
		else if (mlx->map[y + 1][x] == 'F' && coins == 0)
			ft_exit(mlx, NULL, 0, "You have finish the game !");
	}
}

void	ft_move_left(int x, int y, t_mlx *mlx, unsigned int *count)
{
	int	coins;

	coins = count_coins(mlx);
	if (x > 0 && mlx->map[y][x - 1] != '1' && mlx->map[y][x - 1] != 'E')
	{
		ft_printf("You have use %d moves\r", ++(*count));
		if (mlx->map[y][x - 1] != 'E' && mlx->map[y][x - 1] != 'F')
		{
			mlx->map[y][x] = '0';
			mlx->map[y][x - 1] = 'P';
		}
		else if (mlx->map[y][x - 1] == 'F' && coins == 0)
			ft_exit(mlx, NULL, 0, "You have finish the game !");
	}
}

void	ft_move_right(int x, int y, t_mlx *mlx, unsigned int *count)
{
	int	coins;

	coins = count_coins(mlx);
	if (x > 0 && mlx->map[y][x + 1] != '1' && mlx->map[y][x + 1] != 'E')
	{
		ft_printf("You have use %d moves\r", ++(*count));
		if (mlx->map[y][x + 1] != 'E' && mlx->map[y][x + 1] != 'F')
		{
			mlx->map[y][x] = '0';
			mlx->map[y][x + 1] = 'P';
		}
		else if (mlx->map[y][x + 1] == 'F' && coins == 0)
			ft_exit(mlx, NULL, 0, "You have finish the game !");
	}
}
