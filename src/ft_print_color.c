/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:08:30 by lucas             #+#    #+#             */
/*   Updated: 2016/03/17 10:25:11 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_putnchar_fd(char c, int n, int fd)
{
	if (n <= 0)
		return ;
	while (n--)
	{
		ft_putchar_fd(c, fd);
	}
}

int		ft_print_color(t_files *files, int cursor, int fd)
{
	if (cursor == files->id)
		ft_putstr_fd(SOULIGNE, fd);
	if (files->chckd)
		ft_putstr_fd(BLUE, fd);
	ft_putstr_fd(files->name, fd);
	ft_putstr_fd("\033[0m", fd);
	return (0);
}
