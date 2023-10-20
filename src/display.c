# include "../inc/UTTT.h"

void	create_frame(t_img *img, void *mlx, int width, int height) {
	img->img = mlx_new_image(mlx, width, height);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
}

void	create_image(t_img *img, void *mlx, char *name) {
	img->img = mlx_xpm_file_to_image(mlx, name, &(img->width), &(img->height));
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
}


unsigned int	get_color(t_img *data, int x, int y)
{
	if (x > data->width)
		x = data->width;
	if (y > data->height)
		y = data->height;
	return (*(unsigned int *)(data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8))));
}

void	put_pixel_grid(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;
	if (color != 0x00FFFFFF)
		return ;
	if (!(x - OFFSET < 0 || x - OFFSET > data->width || y - OFFSET < 0 || y - OFFSET > data->height))
	{
		dst = data->addr + ((y - OFFSET) * data->line_length + (x - OFFSET) * (data->bits_per_pixel / 8));
		*(unsigned int *)dst += 0xFFFF0000;
	}
	if (!(x < 0 || x > data->width || y < 0 || y > data->height))
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst += 0xFF00FF00;
	}
	if (!(x + OFFSET < 0 || x + OFFSET > data->width || y + OFFSET < 0 || y + OFFSET > data->height))
	{
		dst = data->addr + ((y + OFFSET) * data->line_length + (x + OFFSET) * (data->bits_per_pixel / 8));
		*(unsigned int *)dst += 0xFF0000FF;
	}
}

void	print_small_grid(t_game *g)
{
	for (int oy = 0; oy < 3; oy++)
	{
		for (int ox = 0; ox < 3; ox++)
		{
			for (int y = 0; y < g->small_grid.height; y++)
			{
				for (int x = 0; x < g->small_grid.height; x++)
				{
					put_pixel_grid(&(g->frame), x + S_MARGIN + ox * SG_OFFSET, y + S_MARGIN + oy * SG_OFFSET, get_color(&(g->small_grid), x, y));
				}
			}
		}
	}
}

void	print_big_grid(t_game *g)
{
	for (int y = 0; y < g->big_grid.height; y++)
	{
		for (int x = 0; x <g->big_grid.height; x++)
		{
			put_pixel_grid(&(g->frame), x + MARGIN, y + MARGIN, get_color(&(g->big_grid), x, y));
		}
	}
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	create_grid(t_img *img, void *mlx, int width, int height, int thickness)
{
	img->img = mlx_new_image(mlx, width + thickness * 2, height + thickness * 2);
	img->width = width + thickness * 2;
	img->height = height + thickness * 2;
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	for (int x = 0; x < thickness; x++)
	{
		for (int y = 0; y < height + thickness * 2; y++)
		{
			put_pixel(img, x + height / 3, y, 0x00FFFFFF);
			put_pixel(img, x + (2 * height / 3) + thickness, y, 0x00FFFFFF);
		}
	}
	for (int y = 0; y < thickness; y++)
	{
		for (int x = 0; x < width + thickness * 2; x++)
		{
			put_pixel(img, x, y + width / 3, 0x00FFFFFF);
			put_pixel(img, x, y + (2 * width / 3) + thickness, 0x00FFFFFF);
		}
	}
}

void	put_pixel_add(t_img *data, int x, int y, int color)
{
	char	*dst;

	// dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// *(unsigned int *)dst = color;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (!*(unsigned int *)dst)
		return ;
	*(unsigned int *)dst += color;
}

void	my_mlx_pixel_put_add(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst += color;
}

void	dislplay(t_game *g)
{
	create_frame(&(g->frame), g->mlx, 1700, 1700);
	print_big_grid(g);
	print_small_grid(g);
	mlx_put_image_to_window(g->mlx, g->mlx_w, g->frame.img, 0, 0);
}