#include "../include/cube3d.h"

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

void	clear_and_open_path(char *str, t_ptr_mlx *ptr)
{
	size_t	i;
	char	*ptr;
	char	*new_string[MAX_PATH];

	i = 0;
	new_string[i] = "\0";
	ptr = strchr(str, ".");
	while (ptr != NULL && (ptr[i] != " " || ptr[i] != "	" || ptr[i] != "\0"))
	{
		ptr[i] = new_string[i];
		i++;
	}
	ptr->texture = mlx_xpm_file_to_image(ptr->data_mlx, new_string, WIDTH, HEIGHT);
}

void	validazione(t_data_maps data)
{
	if (!(path_no || path_ne || path_we || path_so || up_color || down_color))
	{
		ft_free_maps(maps);
		ft_fprintf(2, "%s", MSG_ERROR);
		exit(-1)
	}
	clear_and_open_path(maps->path_no);
	clear_and_open_path(maps->path_so);
	clear_and_open_path(maps->path_we);
	clear_and_open_path(maps->path_ne);
	check_and_charge_color(maps);
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
		strjoin(line, tmp);
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

int	main(int argc, char **argv)
{
	t_data_maps	maps;

	maps = (struct s_data_maps){NULL};
	if (argc != 2)
		return (ft_message_argv());
	data = mlx_init();
	maps.name_maps = argv[1];
	proccesing_file_cub(&maps)
}
