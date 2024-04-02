/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:51:53 by rparodi           #+#    #+#             */
/*   Updated: 2024/03/31 16:41:24 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_image(t_mlx *mlx)
{
	if (mlx->store.wall.img_ptr)
		mlx_destroy_image(mlx->init, mlx->store.wall.img_ptr);
	if (mlx->store.floor.img_ptr)
		mlx_destroy_image(mlx->init, mlx->store.floor.img_ptr);
	if (mlx->store.coins.img_ptr)
		mlx_destroy_image(mlx->init, mlx->store.coins.img_ptr);
	if (mlx->store.player.img_ptr)
		mlx_destroy_image(mlx->init, mlx->store.player.img_ptr);
	if (mlx->store.lock.img_ptr)
		mlx_destroy_image(mlx->init, mlx->store.lock.img_ptr);
	if (mlx->store.open.img_ptr)
		mlx_destroy_image(mlx->init, mlx->store.open.img_ptr);
}

void	map_size(t_mlx *mlx)
{
	size_t	i;
	size_t	prev_i;
	size_t	j;

	i = 0;
	j = 0;
	prev_i = 0;
	while (mlx->map[j] != NULL)
	{
		i = 0;
		while (mlx->map[j][i] != '\0' )
			i++;
		if (mlx->map[j][i - 1] == '\n')
			i--;
		if (i != prev_i && prev_i != 0)
			ft_exit(mlx, NULL, 1, "The map is not a rectangle");
		if (j == 0)
			prev_i = i;
		j++;
	}
	mlx->map_h = j * 32;
	mlx->map_l = i * 32;
}

t_image	ft_whitch_case(char c, t_mlx *mlx)
{
	if (c == '1')
		return (mlx->store.wall);
	else if (c == '0')
		return (mlx->store.floor);
	else if (c == 'C')
		return (mlx->store.coins);
	else if (c == 'P')
		return (mlx->store.player);
	else if (c == 'E')
		return (mlx->store.lock);
	else
		return (mlx->store.open);
}
