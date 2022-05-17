/*
int	main()
{
	t_program program;
	t_window  window;
	window.x_width = 800;
	window.y_height = 600;

	int *texture_h = malloc(sizeof(int));
	int *texture_w = malloc(sizeof(int));



	program.mlx = mlx_init();
	program.mlx_window = mlx_new_window(program.mlx, window.x_width, window.y_height, "so_long");

	int	i;
	i = 0;
	while (i < window.x_width)
	{
		mlx_pixel_put(program.mlx, program.mlx_window, i, window.y_height / 5, 0xFF5733);
		i++;
	}

	program.img = mlx_xpm_file_to_image(program.mlx, "./download.xpm", texture_w, texture_h);
	mlx_put_image_to_window(program.mlx, program.mlx_window, program.img, *texture_w, *texture_w);

	mlx_loop(program.mlx);
}
*/

/*
typedef struct s_vars
{
	int		collectible;
	int		player;
	int		exit;

}			t_vars;

/* vector variables for the window & image 
typedef struct s_window
{
	int		x_width;
	int		y_height;
}			t_window;

/* image 
typedef struct s_image
{
	t_window	size;

}			t_image;

/*  mlx program 
typedef struct s_program
{
	void		*mlx;
	t_image		*img;
	t_window	*mlx_window;
}			t_program;
*/


mlx/libmlx.a -framework OpenGL -framework AppKit




typedef enum img_arg
{
	WALL,
	COLLECT,
	PLAYER,
	EMPTY,
	EXIT,
	IMG_COUNT
}	t_img;



/*int line_count;
	line_count = count_number_lines(argv);
	printf("%d\n", line_count);*/
	//printf("%d\n", game.img_width);
	//printf("%d\n", game.img_height);
	
	/* mlx/libmlx.a  */