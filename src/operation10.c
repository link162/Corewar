/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:12:26 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/29 17:13:30 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_bytes(uint8_t *memory,
							int32_t pos,
							int32_t value,
							size_t size)
{
	int8_t	i;

	i = 0;
	while (size)
	{
		memory[pos + size - 1] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

void				op_sti(t_cor *cor, t_cursor *cursor)
{
    int32_t	r_id;
	int32_t	val;
	int32_t	arg1_val;
	int32_t	arg2_val;

	cursor->step += 2;
	r_id = cor->stage[find_adress(cursor->pos + cursor->step)];

	val = cursor->reg[r_id - 1];
	cursor->step += 1;
	arg1_val = take_op(cor, cursor, 2, true);
	arg2_val = take_op(cor, cursor, 3, true);
	write_bytes(cor->stage,
			(cursor->pos + ((arg1_val + arg2_val) % IDX_MOD)), val, DIR_SIZE);

	// if (cor->visual)
	// 	update_map(cor, cursor, cursor->pos + ((arg1_val + arg2_val) % IDX_MOD),
	// 															DIR_SIZE);
    //     update_map ?


	// if (cor->log & OP_LOG
	// 	log_sti(cursor, r_id, arg1_val, arg2_val);
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
