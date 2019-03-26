/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:42:51 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/26 12:39:00 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    visual_flag(t_cor *cor, int *i)
{
    cor->visual = 1;
    *i++;
}

void	dump_flag(t_cor *cor, int *i, int argc, char **argv)
{
	if (!cor->dump_number && i + 1 < argc)
	{
		*i++;
		
		cor->dump_cycle = ft_atoi(
}

void    read_flags(t_cor *cor, int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argv)
    {
        if (!ft_strcmp(argv[i], "-v"))
            visual_flag(cor, &i);
        else if (!ft_strcmp(argv[i], "-dump") || !ft_strcmp(argv[i], "-d"))
            dump_flag(cor, &i, argc, argv);
        else if (!ft_strcmp(argv[i], "-show"))
            show_flag(cor, &i, argc, argv);
    }
}
