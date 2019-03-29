/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:45:44 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/29 13:41:34 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIUSAL_H
# define VIUSAL_H

# include "corewar.h"
# include <ncurses.h>
# define KEY_ESC 27
# define KEY_SPACE 32

WINDOW *g_win_arena;
WINDOW *g_win_status_bar;

void	init_win(t_cor *cor);
void	dinit_win();
void	init_status_bar(t_cor *cor);
void	update_arena(t_cor *cor);
void	update(WINDOW *win);
void	key_control();
void	print_control_key();

char	*g_music_set;
int		g_delay;

#endif
