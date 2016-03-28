/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:32:26 by lucas             #+#    #+#             */
/*   Updated: 2016/03/28 14:44:06 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int     ft_exit(int i)
{
	struct termios term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag |= ECHO;
	term.c_lflag |= ICANON;
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
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
