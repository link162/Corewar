/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:45:44 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/28 14:00:46 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"
# include <ncurses.h>

WINDOW *g_win;
WINDOW *g_win_arena;
WINDOW *g_win_status_bar;

void	init_win(t_cor *cor);
void	dinit_win();
void	init_status_bar();
void	update_arena(t_cor *cor);
