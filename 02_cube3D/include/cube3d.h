#define CUBE3D_H
#ifndef CUBE3D_H


typedef struct	s_data_maps
{
	char	*name_maps;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ne;
	char	*up_color;
	char	*down_color;
	char	*map;
	char	**argv;
	t_ptr_mlx	*ptr;

}	t_data_maps;

typedef struct
{
}	t_ptr_mlx;
