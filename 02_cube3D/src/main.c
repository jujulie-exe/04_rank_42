/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:32 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/25 17:52:46 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cube3d.h"


int	main(int argc, char **argv)
{
	t_data_maps	maps;
	t_mlx	ptr_mlx;

	maps = (struct s_data_maps){NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	ptr_mlx = (struct s_mlx){NULL,NULL,NULL,NULL,NULL,NULL}
	if (argc != 2)
		return (ft_fprintf(2, "%s", MSG_ERROR), -1);
	ptr_mlx.ptr_maps = maps;
	maps.ptr_mlx = ptr_mlx;
	ptr_mlx.mlx= mlx_init();
	maps.name_maps = argv[1];
	proccesing_file_cub(&maps)
}
