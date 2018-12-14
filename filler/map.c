/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 18:54:51 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 22:57:33 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	ft_map_malloc(t_filler *player)
{
	int i;

	i = 0;
	if ((player->map = (char**)malloc(sizeof(char*) * (player->map_dim[0]
						+ 1))) == NULL)
		return ;
	player->map[player->map_dim[0]] = NULL;
	while (i < player->map_dim[0])
	{
		if ((player->map[i] = (char*)malloc(sizeof(char) * (player->map_dim[1]
						+ 1))) == NULL)
			return ;
		player->map[i][player->map_dim[1]] = '\0';
		i++;
	}
}

void	ft_map_free(t_filler *player)
{
	int i;

	i = 0;
	while (i <= player->map_dim[0])
	{
		free(player->map[i]);
		i++;
	}
	free(player->map);
	player->map = NULL;
}

void	ft_map_write(t_filler *player, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		player->map[player->compt][i] = line[i];
		i++;
	}
	player->compt++;
	if (player->compt < player->map_dim[0])
		player->state = 3;
	else
	{
		player->compt = 0;
	}
}
