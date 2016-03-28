/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/03/28 15:01:26 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sig_handler(int signo)
{
	if (signo == SIGWINCH)
		ft_aff(files, cursor, maxlen);
	if (signo == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
	}
	if (signo == SIGCONT)
		ft_can();
}

int		main(int ac, char **av)
{
	char		buffer[3];

	(void)ac;
	cursor = 0;
	files = ft_save(av);
	maxlen = ft_list_len(files);
	if (!files)
		ft_exit(4);
	signal(SIGWINCH, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGCONT, sig_handler);
	ft_can();
	ft_aff(files, cursor, maxlen);
	while (read(0 , buffer, 3))
	{
		maxlen = ft_list_len(files);
		ft_key_hook(files, buffer, &cursor, maxlen);
		ft_aff(files, cursor, maxlen);
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
	}
	return (0);
}
