/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 18:08:15 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 22:57:12 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

static void	ft_map_value_three(t_filler *player, int value)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < player->map_dim[0])
	{
		j = 0;
		while (j < player->map_dim[1])
		{
			if (player->map[i][j] == 0)
				player->map[i][j] = value;
			j++;
		}
		i++;
	}
}

static int	ft_map_value_two(t_filler *player, int i_j[2], int value, int out)
{
	int l_k[2];

	l_k[0] = i_j[0] - 1;
	while (l_k[0] <= i_j[0] + 1)
	{
		l_k[1] = i_j[1] - 1;
		while (l_k[1] <= i_j[1] + 1)
		{
			if (l_k[0] >= 0 && l_k[1] >= 0 && l_k[0] < player->map_dim[0]
					&& l_k[1] < player->map_dim[1] &&
					player->map[l_k[0]][l_k[1]] == value &&
					player->map[i_j[0]][i_j[1]] == 0)
			{
				if (value == -3)
					player->map[i_j[0]][i_j[1]] = 1;
				else
					player->map[i_j[0]][i_j[1]] = value + 1;
				out = 1;
			}
			l_k[1]++;
		}
		l_k[0]++;
	}
	return (out);
}

void		ft_map_value(t_filler *player)
{
	int value;
	int i_j[2];
	int out;

	value = -3;
	out = 1;
	while (out > 0)
	{
		out = -1;
		i_j[0] = 0;
		while (i_j[0] < player->map_dim[0])
		{
			i_j[1] = 0;
			while (i_j[1] < player->map_dim[1])
			{
				out = ft_map_value_two(player, i_j, value, out);
				i_j[1]++;
			}
			i_j[0]++;
		}
		if (value == -3)
			value = 0;
		value++;
	}
	ft_map_value_three(player, value);
}

static void	ft_algo_two(t_filler *player, int i, int j)
{
	int k;
	int l;
	int test;
	int value;

	k = 0;
	test = 0;
	value = 0;
	while (k < player->pattern_dim[0])
	{
		l = 0;
		while (l < player->pattern_dim[1])
		{
			if (player->pattern[k][l] == '*' && player->map[i + k][j + l] == -5)
				test++;
			if (player->pattern[k][l] == '*' && player->map[i + k][j + l] == -3)
				test = 2;
			if (player->pattern[k][l] == '*' && player->map[i + k][j + l] > 0)
				value = value + player->map[i + k][j + l];
			l++;
		}
		k++;
	}
	if (test == 1 && value < player->calcul)
		ft_algo_three(player, i, j, value);
}

void		ft_algo(t_filler *player)
{
	int i;
	int j;

	i = 0;
	player->xy[0] = -1;
	player->xy[1] = -1;
	while (i < player->map_dim[0])
	{
		j = 0;
		while (j < player->map_dim[1])
		{
			if ((i + player->pattern_dim[0]) <= player->map_dim[0] &&
					(j + player->pattern_dim[1]) <= player->map_dim[1])
				ft_algo_two(player, i, j);
			j++;
		}
		i++;
	}
}
