/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:35:59 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/30 15:01:31 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_fc(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	if (str[i] == 'F')
	{
		data->tex->fl->red = ft_atoi(&str[i + 1]);
		while (str[i] != ',' && str[i])
			i++;
		data->tex->fl->green = ft_atoi(&str[++i]);
		while (str[i] != ',' && str[i])
			i++;
		data->tex->fl->blue = ft_atoi(&str[++i]);
	}
	if (str[i] == 'C')
	{
		data->tex->ce->red = ft_atoi(&str[i + 1]);
		while (str[i] != ',' && str[i])
			i++;
		data->tex->ce->green = ft_atoi(&str[++i]);
		while (str[i] != ',' && str[i])
			i++;
		data->tex->ce->blue = ft_atoi(&str[++i]);
	}
}

bool	check_rgb(t_rgb *rgb)
{
	if (rgb->red > 255 || rgb->red < 0)
		return (TRUE);
	if (rgb->green > 255 || rgb->green < 0)
		return (TRUE);
	if (rgb->blue > 255 || rgb->blue < 0)
		return (TRUE);
	return (FALSE);
}

bool	check_map(char **str, t_data *data)
{
	char	*str2;
	int		i;
	int		j;

	i = -1;
	str2 = ft_strtrim(str[0], " 	\n");
	if (str2 && ft_strlen(str2))
	{
		while (str[++i])
		{
			j = -1;
			while (str[i][++j])
			{
				if (ft_isdigit(str[i][j]))
					break ;
			}
			if (j != 0 && str[i][j] == '\0' && data->cm++)
				return (free(str2), FALSE);
		}
		return (free(str2), TRUE);
	}
	return (free(str2), FALSE);
}

bool	check_all(t_data *data)
{
	if (data->cm)
		return (printf("Error\nMap should be last arg of the file\n"), TRUE);
	if (!data->tex->no)
		return (printf("Error\nNo texture for North\n"), TRUE);
	if (!data->tex->so)
		return (printf("Error\nNo texture for South\n"), TRUE);
	if (!data->tex->we)
		return (printf("Error\nNo texture for West\n"), TRUE);
	if (!data->tex->ea)
		return (printf("Error\nNo texture for East\n"), TRUE);
	if (check_rgb(data->tex->fl))
		return (printf("Error\nNo rgb for the Floor\n"), TRUE);
	if (check_rgb(data->tex->ce))
		return (printf("Error\nNo rgb for the Ceiling\n"), TRUE);
	if (!data->map)
		return (TRUE);
	do_wh_map(data);
	return (FALSE);
}

bool	ft_strcmp(char *str, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str[j] == ' ' || str[j] == '	') && str[j])
		j++;
	while ((str[i + j] && str2[i]))
	{
		if (str[i + j] != str2[i])
			return (FALSE);
		i++;
	}
	if (str2[i])
		return (FALSE);
	return (TRUE);
}
