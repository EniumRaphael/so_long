/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:16:20 by rparodi           #+#    #+#             */
/*   Updated: 2024/03/08 12:34:08 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_value_image(t_image *img)
{
	img->img_ptr = NULL;
	img->addr = NULL;
	img->h = 0;
	img->w = 0;
	img->bpp = 0;
	img->endian = 0;
	img->line_len = 0;
}

void	ft_init_value_mlx(t_mlx *mlx)
{
	mlx->init = NULL;
	mlx->window = NULL;
	mlx->w_h = 0;
	mlx->w_l = 0;
	mlx->fd_map = -1;
	mlx->size_map = 0;
	mlx->map = NULL;
	mlx->map_h = 0;
	mlx->map_l = 0;
	mlx->img = NULL;
	mlx->count = 0;
}
