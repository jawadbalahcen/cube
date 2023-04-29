#include "cub3d.h"

int	mouse_move(int x, int y, void *ptr)
{
	if (x < 0)
		mlx_mouse_move(ptr, 499, y);
	return (0);
}

int main()
{
    // void *mlx_ptr;
    // void *win_ptr;

    // mlx_ptr = mlx_init();
    // win_ptr = mlx_new_window(mlx_ptr, 500, 500, "My Window");



    // mlx_loop(mlx_ptr);
double a= 4.5616;
a++;
printf("{%lf}\n", a);
    return 0;
}