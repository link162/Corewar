/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:24:17 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/30 08:25:25 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "corewar.h"

typedef struct		s_cursor
{
	int				id;
	int				carry;
	int				last_live;
	int				pos;
	int				operation;
	int				cycle_wait;
	int				step;
	int				reg[REG_NUMBER];
	struct s_cursor	*next;
}					t_cursor;

typedef struct		s_hero
{
	int				id;
	int				size;
	char			*name;
	char			*comment;
	char			*file;
	uint8_t			*code;
}					t_hero;

typedef struct		s_files
{
	char			*file;
	int				id;
	struct s_files	*next;
}					t_files;

typedef struct		s_cor
{
	uint8_t			stage[MEM_SIZE];
	t_hero			heroes[MAX_PLAYERS];
	t_files			*list;
	t_cursor		*cursor;
	ssize_t			cycles;
	ssize_t			cycles_to_die;
	ssize_t			cycles_after_check;
	int				cursors;
	int				count_heroes;
	int				dump_cycle;
	int				visual;
	int				last_alive;
}					t_cor;

#endif
