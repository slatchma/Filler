/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 19:04:28 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 19:05:17 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct		s_filler
{
	char			p;
	int				map_dim[2];
	char			**map;
	int				pattern_dim[2];
	char			**pattern;
	int				xy[2];
	int				calcul;
	int				state;
	int				compt;
}					t_filler;
void				ft_map_malloc(t_filler *player);
void				ft_map_free(t_filler *player);
void				ft_map_write(t_filler *player, char *line);
void				ft_pattern_malloc(t_filler *player);
void				ft_pattern_free(t_filler *player);
void				ft_pattern_write(t_filler *player, char *line);
void				ft_algo(t_filler *player);
void				ft_map_value(t_filler *player);
void				ft_player_dim(t_filler *player, char *line, char choice);
void				ft_cleaning(t_filler *player);
void				ft_player_symbol(t_filler *player, char *line);
void				ft_algo_three(t_filler *player, int i, int j, int value);
#endif
