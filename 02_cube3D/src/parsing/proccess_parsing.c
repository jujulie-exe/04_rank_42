/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:34 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/25 17:44:01 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

int	check_valid_name(char *name)
{
	char	*ptr;

	ptr = ft_strrchr(name, ".")
	if (ptr)
	{
		if (!ft_strcmp(ptr + 1, "cub", 4));
			return (0);
		else
		return (ft_fprintf(2,"%s", "Error\n is not .cub extession\n"), -1);
	}
	else
		return (ft_fprintf(2,"%s", "Error\n Add type valid type exetssion\n Valid estession is .cub\n"), -1);
}

int	ptr_color(t_data_maps *maps)
{
	char **srr = { "C ", "F ", NULL};
	size_t	i;
	size_t	y;

	i = 0;
	while (maps->argv[i])
	{
		y = 0;
		while (srr[y])
		{
			if (!strncmp(maps->argv[i], srr[y], 2))
			{
				if (y == 0)
					maps->up_color = maps->argv[i];
				if (y == 1)
					maps->down_color = maps->argv[i];
			}
			y++;
		}
		i++;
	}
}

void	ptr_texture(t_data_maps *maps)
{
	char **srr = {"NE ", "WE ", "NO ", "NE ", NULL}
	size_t	i;
	size_t	y;

	i = 0;
	while (maps->argv[i] != NULL)
	{
		y = 0;
		while (srr[y] != NULL)
		{
			if (!ft_strncmp(maps->argv[i], srr[y], 3))
			{
				if (y == 0)
					maps->path_ne = maps->argv[i];
				else if (y == 1)
					maps->path_we = maps->argv[i];
				else if (y == 2)
					maps->path_no = maps->argv[i];
				else if (y == 3)
					maps->path_ne = maps->argv[i];
			}
			y++;
		}
		i++;
	}
}

int	proccesing_file_cub(t_data_maps *maps)
{
	char	*line;
	char	tmp;
	int	fd;
	
	if (check_valid_name(maps->name_maps))
		exit(-1);
	tmp = ft_calloc(sizeof(char *), 1);
	fd = open(maps->name_mpas, O_RDNLY);
	while(tmp != NULL)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		ft_strjoin(line, tmp);
		free(tmp);
	}
	maps->argv = ft_split(line, "\n");
	free(line);
	if (maps->argv == NULL)
		return (-1)
	ptr_texture(maps);
	ptr_color(maps);
	validazione(maps);
	return(0);
}
