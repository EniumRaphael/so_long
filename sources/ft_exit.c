/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:07:39 by rparodi           #+#    #+#             */
/*   Updated: 2024/03/10 17:53:42 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_maps(char **strs, char **copy)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	if (copy != NULL)
	{
		i = 0;
		while (copy[i] != NULL)
		{
			free(copy[i]);
			i++;
		}
		free(copy);
	}
}

void	ft_exit(t_mlx *mlx, void *p2, short int exit_status, char *leaving_msg)
{
	if (mlx != NULL)
	{
		if (mlx->fd_map > 0)
			close(mlx->fd_map);
		ft_free_image(mlx);
		if (mlx->window)
			mlx_destroy_window(mlx->init, mlx->window);
		if (mlx->init)
			mlx_destroy_display(mlx->init);
		ft_free_maps(mlx->map, NULL);
		free(mlx->init);
		free(mlx);
	}
	free(p2);
	if (exit_status == 1)
		ft_printf("\n\nError:\n> %s\n", leaving_msg);
	else if (exit_status == 0)
		ft_printf("\n\n> %s\n", leaving_msg);
	exit(exit_status);
}

int	ft_close(t_mlx *mlx)
{
	ft_exit(mlx, NULL, 0, "Your leaving? see you! (Reason: Red Cross)");
	return (42);
}
