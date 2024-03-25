/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:53:59 by rparodi           #+#    #+#             */
/*   Updated: 2024/03/06 11:26:19 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_strsdup(char **s, t_mlx *mlx)
{
	const size_t	len = ft_count_line(mlx->path);
	size_t			i;
	char			**to_return;

	i = 0;
	to_return = (char **)malloc(sizeof(char *) * mlx->size_map);
	if (!to_return)
		return (NULL);
	while (i < len)
	{
		to_return[i] = ft_strdup(s[i]);
		i++;
	}
	to_return[i] = NULL;
	return (to_return);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*to_return;

	len = ft_strlen(s) + 1;
	to_return = (char *)malloc(sizeof(char) * len);
	if (!to_return)
		return (NULL);
	ft_strlcpy(to_return, s, len);
	return (to_return);
}
