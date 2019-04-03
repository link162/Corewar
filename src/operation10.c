/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:12:26 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/03 18:15:12 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				op_sti(t_cor *cor, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	value;
	int32_t	addr_1;
	int32_t	addr_2;

	cursor->step += OP_SIZE + ARGS_CODE_LEN;
	r_id = get_byte(vm, cursor->pc, cursor->step);
	value = cursor->reg[INDEX(r_id)];
	cursor->step += REG_LEN;
	addr_1 = get_op_arg(vm, cursor, 2, true);
	addr_2 = get_op_arg(vm, cursor, 3, true);
	int32_to_bytecode(vm->arena,
			(cursor->pc + ((addr_1 + addr_2) % IDX_MOD)), value, DIR_SIZE);
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
