#include "../inc/UTTT.h"

char	B_check_horizontal(t_game *g)
{
	int	X = 0;
	int	O = 0;

	for (int row = 0; row < 3; row++)
	{
		X = 0;
		O = 0;
		for(int col = 0; col < 3; col++)
		{
			if (g->tac[row][col].result == 'x')
				X++;
			else if(g->tac[row][col].result == 'o')
				O++;
		}
		if (X == 3)
			return 'x';
		else if (O == 3)
			return 'o';
	}
	return ('\0');
}

char	B_check_vertical(t_game *g)
{
	int	X = 0;
	int	O = 0;

	for (int col = 0; col < 3; col++)
	{
		X = 0;
		O = 0;
		for(int row = 0; row < 3; row++)
		{
			if (g->tac[row][col].result == 'x')
				X++;
			else if(g->tac[row][col].result == 'o')
				O++;
		}
		if (X == 3)
			return 'x';
		else if (O == 3)
			return 'o';
	}
	return ('\0');
}


char	B_check_diagonal(t_game *g)
{
	if (g->tac[1][1].result == 'x')
	{
		if (g->tac[0][2].result == 'x' && g->tac[2][0].result == 'x')
			return 'x';
		else if (g->tac[0][0].result == 'x' && g->tac[2][2].result == 'x')
			return 'x';
	}
	else if (g->tac[1][1].result == 'o')
	{
		if (g->tac[0][2].result == 'o' && g->tac[2][0].result == 'o')
			return 'o';
		else if (g->tac[0][0].result == 'o' && g->tac[2][2].result == 'o')
			return 'o';
	}
	return ('\0');
}

char	checker_big_sqr(t_game *g)
{
	char	flag = '\0';
	int	cx = 0;

	for (int row = 0; row < 3; row++)
		for(int col = 0; col < 3; col++)
			if (g->tac[g->play_x][g->play_y].result)
				cx++;
	flag = B_check_diagonal(g);
	if (flag)
		return flag;
	flag = B_check_horizontal(g);
	if (flag)
		return flag;
	flag = B_check_vertical(g);
	if (flag)
		return flag;
	if (cx == 9)
		return '-';
	return '\0';
}

char	S_check_diagonal(t_game *g)
{
	if (g->tac[g->play_x][g->play_y].tic[1][1] == 'x')
	{
		if (g->tac[g->play_x][g->play_y].tic[0][2] == 'x' && g->tac[g->play_x][g->play_y].tic[2][0] == 'x')
			return 'x';
		else if (g->tac[g->play_x][g->play_y].tic[0][0] == 'x' && g->tac[g->play_x][g->play_y].tic[2][2] == 'x')
			return 'x';
	}
	else if (g->tac[g->play_x][g->play_y].tic[1][1] == 'o')
	{
		if (g->tac[g->play_x][g->play_y].tic[0][2] == 'o' && g->tac[g->play_x][g->play_y].tic[2][0] == 'o')
			return 'o';
		else if (g->tac[g->play_x][g->play_y].tic[0][0] == 'o' && g->tac[g->play_x][g->play_y].tic[2][2] == 'o')
			return 'o';
	}
	return ('\0');
}

char	S_check_vertical(t_game *g)
{
	int	X = 0;
	int	O = 0;

	for (int col = 0; col < 3; col++)
	{
		X = 0;
		O = 0;
		for(int row = 0; row < 3; row++)
		{
			if (g->tac[g->play_x][g->play_y].tic[row][col] == 'x')
				X++;
			else if(g->tac[g->play_x][g->play_y].tic[row][col] == 'o')
				O++;
		}
		if (X == 3)
			return 'x';
		else if (O == 3)
			return 'o';
	}
	return ('\0');
}

char	S_check_horizontal(t_game *g)
{
	int	X = 0;
	int	O = 0;

	for (int row = 0; row < 3; row++)
	{
		X = 0;
		O = 0;
		for(int col = 0; col < 3; col++)
		{
			if (g->tac[g->play_x][g->play_y].tic[row][col] == 'x')
				X++;
			else if(g->tac[g->play_x][g->play_y].tic[row][col] == 'o')
				O++;
		}
		if (X == 3)
			return 'x';
		else if (O == 3)
			return 'o';
	}
	return ('\0');
}

int	checker_small_sqr(t_game *g)
{
	char	flag = '\0';

	flag = S_check_diagonal(g);
	if (flag)
	{
		g->tac[g->play_x][g->play_y].result = flag;
		return 1;
	}
	flag = S_check_horizontal(g);
	if (flag)
	{
		g->tac[g->play_x][g->play_y].result = flag;
		return 1;
	}
	flag = S_check_vertical(g);
	if (flag)
	{
		g->tac[g->play_x][g->play_y].result = flag;
		return 1;
	}
	return 0;
}

int	check_if_small_done(t_game *g)
{
	int	cx = 0;
	int	co = 0;

	for (int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			if (g->tac[g->play_x][g->play_y].tic[row][col] == 'x')
				cx++;
			else if (g->tac[g->play_x][g->play_y].tic[row][col] == 'o')
				co++;
		}
	}
	if (co < 3 && cx < 3)
		return 1;
	if (co + cx == 9)
	{
		g->tac[g->play_x][g->play_y].result = '-';
		return 0;
	}
	if (checker_small_sqr(g) == 1)
		return 0;
	return 1;
}

int	try_lock(t_game *g)
{
	if (g->lock == 1)
	{
		if (g->tac[g->play_x][g->play_y].tic[g->cursor_x][g->cursor_y])
			return 1;
		else
			return 0;
	}
	else
	{
		if (g->tac[g->play_x][g->play_y].result)
			return 1;
		else
		{
			g->lock = 1;
			return 1;
		}
	}
	return 1;
}