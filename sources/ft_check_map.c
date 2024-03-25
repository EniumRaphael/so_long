/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:52:02 by rparodi           #+#    #+#             */
/*   Updated: 2024/03/10 18:24:11 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	what_is_it(char *str, size_t i, size_t line, t_mlx *mlx)
{
	if (str[i] == '\n')
	{
		if (line == 0)
			line = i;
		else if (str[i - 1] == '1' && (str[i + 1] == '1' || str[i + 1] == '\0'))
			return (line);
		else
			ft_exit(mlx, str, 1, "The map is invalid (not a rectangle)");
	}
	else if (str[i] == '1')
		return (line);
	else if (str[i] == '0')
		return (line);
	else if (str[i] == 'P')
		return (line);
	else if (str[i] == 'C')
		return (line);
	else if (str[i] == 'E')
		return (line);
	else
		ft_exit(mlx, str, 1, "The map is invalid (unassigned char)");
	return (line);
}

int	check_border(char *str, t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			ft_exit(mlx, str, 1, "The first line isn't good !");
		i++;
	}
	i = ft_strlen(str) - 2;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			ft_exit(mlx, str, 1, "The last line isn't good !");
		i--;
	}
	ft_parsing(str, mlx);
	return (1);
}

size_t	ft_linelen(t_mlx *mlx)
{
	size_t	line;
	size_t	i;
	char	*str;
	size_t	nb_coins;
	size_t	nb_exit;

	i = 0;
	line = 0;
	nb_coins = 0;
	nb_exit = 0;
	str = ft_reverse_split(mlx);
	while (str[i] != '\0')
	{
		line = what_is_it(str, i, line, mlx);
		if (str[i] == 'C')
			nb_coins++;
		if (str[i] == 'E')
			nb_exit++;
		i++;
	}
	if (nb_coins == 0 || nb_exit == 0)
		ft_exit(mlx, str, 1, "The map isn't valid (No Coins or Exit)");
	check_border(str, mlx);
	return (line);
}

void	check_args(int argc, char *argv[], t_mlx *mlx)
{
	mlx->fd_map = 0;
	if (argc == 2)
	{
		mlx->fd_map = open(argv[1], O_RDONLY);
		if (mlx->fd_map < 3)
			ft_exit(mlx, NULL, 1, "File opening failed !");
		else
		{
			ft_init_map(mlx, argv[1]);
			ft_linelen(mlx);
		}
	}
}
