/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:57:51 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/26 12:49:51 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libftprintf/libftprintf.h"
# include "op.h"

typedef struct      s_cor
{
    uint8_t         stage[MEM_SIZE];
    t_hero          heroes[MAX_PLAYERS];
    int             count_heroes;
	__int128		dump_cycle;
	int				dump_number;
    int             visual;
}					t_cor;

void                read_flags(t_cor *cor, int argc, char **argv);

#endif
