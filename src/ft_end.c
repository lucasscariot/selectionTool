/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:32:26 by lucas             #+#    #+#             */
/*   Updated: 2016/03/29 05:52:59 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int     ft_exit(int i)
{
	tcsetattr( 0, TCSANOW, &g_save);
	if (i == 4)
	{
		ft_putstr_fd("genius\n", 2);
		exit(0);
	}
	exit(i);
}

int		ft_end(t_files *files)
{
	int i;

	i = 0;
	ft_putstr_fd("\033c", 3);
	while (files)
	{
		if (files->chckd || files->del)
		{
			if (i > 0)
				ft_putchar(' ');
			ft_putstr(files->name);
			i++;
		}
		files = files->next;
	}
	ft_exit(0);
	return (i);
}
