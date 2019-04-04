/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:12:26 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/03 22:13:49 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				op_sti(t_cor *cor, t_cursor *cursor)
{
	int32_t	reg;
	int32_t	value;
	int32_t	arg2;
	int32_t	arg3;

	cursor->step += OP_LEN + ARG_LEN;
	reg = cor->stage[find_adress(cursor->pos + cursor->step)];
	value = cursor->reg[reg - 1];
	cursor->step += REG_LEN;
	arg2 = take_op(cor, cursor, 2, true);
	arg3 = take_op(cor, cursor, 3, true);
	int_to_byte(cor, (cursor->pos + ((arg2 + arg3) % IDX_MOD)), value, DIR_SIZE);
}

void				op_fork(t_cor *cor, t_cursor *cursor)
{

}

void				op_lld(t_cor *cor, t_cursor *cursor)
{

}

void				op_lldi(t_cor *cor, t_cursor *cursor)
{

}

void				op_lfork(t_cor *cor, t_cursor *cursor)
{

}

void				op_aff(t_cor *cor, t_cursor *cursor)
{

}
