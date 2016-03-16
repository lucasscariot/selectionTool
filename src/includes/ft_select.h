/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:41 by lucas             #+#    #+#             */
/*   Updated: 2016/03/16 13:33:18 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <unistd.h>
# include <termios.h>
# include <termcap.h>
# include <term.h>
# include <curses.h>
# include "libft.h"

typedef struct	s_files
{
	int				id;
	char			*name;
	int				chckd;
	struct s_files	*next;
}				t_files;

int		ft_aff(t_files *files, int cursor, int listlen);
t_files	*ft_save(char **av);
int		ft_list_len(t_files *files);
void    ft_inc_cursor(int *cursor, int maxlen, int version);
int		ft_check(t_files *files, int cursor);
int		ft_key_hook(char *buffer, int *cursor, int maxlen);
int		ft_exit(int i);
int		ft_can();
#endif
