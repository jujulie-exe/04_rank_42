/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:15:22 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/25 17:47:55 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void	check_and_charge_color(t_data_maps *ptr_maps)
{
	size_t	i;
	char *tmp;

	i = 0;
	tmp = ptr_masp->up_color + 1;
	while (*tmp && *tmp != ' ' && *tmp != '	')
		tmp++;
	while (i >= 9)
	{	
		if (ft_atol(tmp + i) <= 255)
			ft_free_all_and_exite(maps, MSG_ERROR);
		i + 3;
	}
}

void	clear_and_open_path(char *str, t_mlx *mlx_ptr, int flags)
{
	size_t	i;
	char	*ptr;
	char	*new_string[MAX_PATH];

	i = 0;
	new_string[i] = '\0';
	ptr = str + 2;
	while (*ptr != '\0' && *ptr != ' ' && *ptr != '	')
		ptr++;
	//ptr = strchr(str, ".");
	while (ptr != NULL &&  i < MAX_PATH && (ptr[i] != ' ' && ptr[i] != '	' && ptr[i] != '\0'))
	{
		ptr[i] = new_string[i];
		i++;
	}
	mlx_ptr->texture[flags] = mlx_xpm_file_to_image(mlx_ptr->mlx, new_string, WIDTH_XMP, HEIGHT_XMP);
	if (!mlx_ptr->texture[flags])
		ft_free_all_and_exite(maps, MSG_ERROR);
}

void	validazione(t_data_maps data)
{
	if (!(path_no || path_ne || path_we || path_so || up_color || down_color))
		ft_free_all_and_exite(maps, MSG_ERROR);
	clear_and_open_path(maps->path_no, maps->ptr_mlx, NO);
	clear_and_open_path(maps->path_so, maps->ptr_mlx, SO);
	clear_and_open_path(maps->path_we, maps->ptr_mlx, WE);
	clear_and_open_path(maps->path_ne, maps->ptr_mlx, NE);
	//check_and_charge_color(maps);
}

