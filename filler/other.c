/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   other.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 18:57:47 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 22:57:45 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

static int	ft_nbre_len(int nbre)
{
	int i;

	i = 1;
	while (nbre > 0)
	{
		nbre = nbre / 10;
		i++;
	}
	return (i);
}

void		ft_player_dim(t_filler *player, char *line, char choice)
{
	int	margin;

	if (choice == 'M')
	{
		margin = 7;
		player->map_dim[0] = ft_atoi(line + margin);
		player->map_dim[1] = ft_atoi(line + margin +
				ft_nbre_len(player->map_dim[0]));
		player->state = 2;
	}
	else
	{
		margin = 5;
		player->pattern_dim[0] = ft_atoi(line + margin);
		player->pattern_dim[1] = ft_atoi(line + margin +
				ft_nbre_len(player->pattern_dim[0]));
	}
}

void		ft_cleaning(t_filler *player)
{
	int i;
	int j;

	i = 0;
	while (i < player->map_dim[0])
	{
		j = 0;
		while (j < player->map_dim[1])
		{
			if (player->map[i][j] == '.')
				player->map[i][j] = 0;
			else if (player->map[i][j] == player->p
				|| player->map[i][j] == (player->p + 32))
				player->map[i][j] = -5;
			else
				player->map[i][j] = -3;
			j++;
		}
		i++;
	}
}

void		ft_player_symbol(t_filler *player, char *line)
{
	if (line[10] == '1')
		player->p = 'O';
	else
		player->p = 'X';
	player->state = 1;
}

void		ft_algo_three(t_filler *player, int i, int j, int value)
{
	player->calcul = value;
	player->xy[0] = i;
	player->xy[1] = j;
}
