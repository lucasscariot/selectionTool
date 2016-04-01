/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:52:00 by lscariot          #+#    #+#             */
/*   Updated: 2016/04/01 16:37:08 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sig_handler(int signo)
{
	char	cmd[2];

	cmd[0] = g_term.c_cc[VSUSP];
	cmd[1] = '\0';
	if (signo == SIGINT)
		ft_exit(0);
	if (signo == SIGWINCH)
		ft_aff(g_files, g_cursor);
	if (signo == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		tcsetattr(0, TCSANOW, &g_save);
		ioctl(0, TIOCSTI, cmd);
	}
	if (signo == SIGCONT)
	{
		ft_can();
		ft_aff(g_files, g_cursor);
	}
}

int		ft_signal(void)
{
	signal(SIGWINCH, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGINT, sig_handler);
	signal(SIGCONT, sig_handler);
	return (0);
}

int		ft_secure(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], "TERM=xterm-256color") == 0)
			return (0);
		i++;
	}
	ft_exit(0);
	return (0);
}
