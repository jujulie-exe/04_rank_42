/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:15:22 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/26 15:08:54 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void	check_and_charge_color(t_data_maps *ptr_maps)
{
	size_t	i;
	char *tmp;

	i = 0;
	tmp = ptr_maps->up_color + 1;
	while (*tmp && *tmp != ' ' && *tmp != '	')
		tmp++;
	while (i >= 9)
	{	
		if (ft_atol(tmp + i) <= 255)
			ft_free_all_and_exit(ptr_maps, MSG_ERROR);
		i += 3;
	}
}

void	clear_and_open_path(char *str, t_mlx *mlx_ptr, int flags)
{
	size_t	i;
	char	*ptr;
	char	new_string[PATH_MAX];

	i = 0;
	new_string[i] = '\0';
	ptr = str + 2;
	while (*ptr != '\0' && *ptr != ' ' && *ptr != '	')
		ptr++;
	//ptr = strchr(str, ".");
	while (ptr != NULL &&  i < PATH_MAX && (*ptr != ' ' && *ptr != '	' && *ptr != '\0'))
	{
		new_string[i] = *ptr;
		i++;
		ptr++;
	}
	mlx_ptr->texture[flags] = mlx_xpm_file_to_image(mlx_ptr->mlx, new_string, (int *)WIDTH_XMP, (int *)HEIGHT_XMP);
	if (!mlx_ptr->texture[flags])
		ft_free_all_and_exit(mlx_ptr->ptr_maps, MSG_ERROR);
}

void	validazione(t_data_maps *maps)
{
	if (!(maps->path_no || maps->path_ne || maps->path_we || maps->path_so || maps->up_color || maps->down_color))
		ft_free_all_and_exit(maps, MSG_ERROR);
	clear_and_open_path(maps->path_no, maps->ptr_mlx, NO);
	clear_and_open_path(maps->path_so, maps->ptr_mlx, SO);
	clear_and_open_path(maps->path_we, maps->ptr_mlx, WE);
	clear_and_open_path(maps->path_ne, maps->ptr_mlx, NE);
	//check_and_charge_color(maps);
}

