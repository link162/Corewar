/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:11:07 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/26 12:15:33 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	map_init(t_cor *cor)
{
	cor->count_herous = 0;
	cor->visual = 0;
}

int main(int argc, char **argv)
{
	t_cor cor;

	map_init(&cor);
	read_flags(&cor, argc, argv);
}
