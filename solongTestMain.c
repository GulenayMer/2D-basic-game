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

mlx/libmlx.a -framework OpenGL -framework AppKit 