/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 03:37:26 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 22:57:23 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	ft_processing(t_filler *player)
{
	ft_cleaning(player);
	ft_map_value(player);
	ft_algo(player);
	if (player->xy[0] == -1)
	{
		player->state = -1;
		ft_printf("-1 -1\n");
	}
	else
	{
		player->state = 1;
		player->calcul = 1000000;
		ft_printf("%d %d\n", player->xy[0], player->xy[1]);
	}
}

void	ft_state(t_filler *player, char *line)
{
	if (player->state == 1)
		ft_player_symbol(player, line);
	if (player->state == 2)
	{
		ft_player_dim(player, line, 'M');
		ft_map_malloc(player);
		player->compt = 0;
	}
	if (player->state == 4)
		ft_map_write(player, line + 4);
	if (player->state == 5)
	{
		ft_player_dim(player, line, 'P');
		ft_pattern_malloc(player);
	}
	if (player->state == 6)
		ft_pattern_write(player, line);
	if (player->state == 7)
	{
		ft_processing(player);
		ft_map_free(player);
		ft_pattern_free(player);
	}
}

void	ft_player_init(t_filler *player)
{
	player->p = 0;
	player->map_dim[0] = 0;
	player->map_dim[1] = 0;
	player->map = NULL;
	player->pattern_dim[0] = 0;
	player->pattern_dim[1] = 0;
	player->pattern = NULL;
	player->xy[0] = 0;
	player->xy[1] = 0;
	player->calcul = 1000000;
	player->state = 0;
	player->compt = 0;
}

int		main(void)
{
	t_filler	player;
	char		*line;

	ft_player_init(&player);
	line = NULL;
	while (player.state++ != -1)
	{
		get_next_line(0, &line);
		ft_state(&player, line);
		ft_strdel(&line);
	}
	return (0);
}
