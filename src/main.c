/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/03/29 12:45:18 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sig_handler(int signo)
{
	char	cmd[2];

	cmd[0] = g_term.c_cc[VSUSP];
	cmd[1] = '\0';
	if (signo == SIGWINCH)
		ft_aff(g_files, g_cursor, g_maxlen);
	if (signo == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		tcsetattr( 0, TCSANOW, &g_save);
		ioctl(0, TIOCSTI, cmd);
	}
	if (signo == SIGCONT)
	{
		ft_can();
		ft_aff(g_files, g_cursor, g_maxlen);
	}
}

int		main(int ac, char **av)
{
	char		buffer[3];

	(void)ac;
	g_cursor = 0;
	g_files = ft_save(av);
	g_maxlen = ft_list_len(g_files);
	if (!g_files)
		ft_exit(4);
	signal(SIGWINCH, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGCONT, sig_handler);
	ft_can();
	ft_aff(g_files, g_cursor, g_maxlen);
	while (read(0 , buffer, 3))
	{
		g_maxlen = ft_list_len(g_files);
		ft_key_hook(g_files, buffer, &g_cursor, g_maxlen);
		ft_aff(g_files, g_cursor, g_maxlen);
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
	}
	return (0);
}
