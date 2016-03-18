/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:41 by lucas             #+#    #+#             */
/*   Updated: 2016/03/18 13:55:52 by lscariot         ###   ########.fr       */
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
	int				del;
	struct s_files	*next;
}				t_files;

int		ft_aff(t_files *files, int cursor, int listlen);
t_files	*ft_save(char **av);
int		ft_list_len(t_files *files);
void    ft_inc_cursor(int *cursor, int maxlen, int version);
int		ft_check(t_files *files, int cursor);
int		ft_key_hook(t_files *fil, char *buff, int *cursor, int maxlen);
void	ft_del_list(t_files *files, int cursor);
t_files	*ft_del_one(t_files *files);
void	ft_swap_cpy(t_files *dest, t_files *src);
void	ft_swap_list(t_files *f, t_files *s);
void	ft_free_one(t_files *var);
int		ft_can();
void	ft_index(t_files *files);
int		ft_exit(int i);
int		ft_print_color(t_files *files, int cursor, int fd);
void	ft_putnchar_fd(char c, int n, int fd);
int		ft_end(t_files *files);
#endif
