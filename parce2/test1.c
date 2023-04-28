#include "mlx/mlx.h"

int	mouse_move(int x, int y, void *ptr)
{
	if (x < 0)
		mlx_mouse_move(ptr, 499, y);
	return (0);
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "My Window");

	mlx_hook(win_ptr, 6, 0, mouse_move, win_ptr);

    mlx_loop(mlx_ptr);

    return 0;
}