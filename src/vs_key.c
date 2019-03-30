/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:21:42 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/29 14:22:07 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		print_control_key()
{
	mvwprintw(g_win_status_bar, 52, 20, "OPTIONS");
	mvwprintw(g_win_status_bar, 54, 5, "[SPACE] == pause/resume");
	mvwprintw(g_win_status_bar, 55, 5, "[↑] == speed++++");
	mvwprintw(g_win_status_bar, 56, 5, "[↓] == speed----");
	mvwprintw(g_win_status_bar, 57, 5, "[ESC] == exit");
}

static void		pause_mode()
{
	int		ch;

	mvwprintw(g_win_status_bar, 64, 52, "PAUSE");
	system("killall sh music.sh afplay");
	update(g_win_status_bar);
	while ((ch = getch()) != 32)
		if (ch == 27)
			dinit_win();
	mvwprintw(g_win_status_bar, 64, 52, "     ");
	update(g_win_status_bar);
	system(g_music_set);
}


static void		speed_up()
{
	char		*tmp[25];
	char		*sp;
	
	free(g_music_set);
	if (g_delay < 10000000)
	{
		g_delay *= 10;
		g_speed += 0.2;
		ft_strcpy(tmp, "./music.sh -r ");
		ft_strcat(tmp, (sp = ft_itoa(g_speed)));
		ft_strcat(tmp, " &");
		g_music_set = ft_strdup(tmp);
		mvwprintw(g_win_status_bar, 64, 52, "Speed ↑ = %s", sp);
		free(sp);
		system("killall sh music.sh afplay");
		system(g_music_set);
		update(g_win_status_bar);
	}
	else
		mvwprintw(g_win_status_bar, 64, 52, "Its max speed");
}

static void		slow_down()
{
	char		*tmp[25];
	char		*sp;
	
	free(g_music_set);
	if (g_delay > 10)
	{
		g_delay /= 10;
		g_speed -= 0.2;
		ft_strcpy(tmp, "./music.sh -r ");
		ft_strcat(tmp, (sp = ft_itoa(g_speed)));
		ft_strcat(tmp, " &");
		g_music_set = ft_strdup(tmp);
		mvwprintw(g_win_status_bar, 64, 52, "Speed ↓ = %s", sp);
		free(sp);
		system("killall sh music.sh afplay");
		system(g_music_set);
		update(g_win_status_bar);
	}
	else
		mvwprintw(g_win_status_bar, 64, 52, "Its min speed");
}

void			key_control()
{
	int		ch;

	while ((ch = getch()))
	{
		if (ch == KEY_ESC)
			dinit_win();
		else if (ch == KEY_SPACE)
			pause_mode();
		else if (ch == KEY_UP)
			speed_up();
		else if (ch == KEY_DOWN)
			slow_down();
	}
}
