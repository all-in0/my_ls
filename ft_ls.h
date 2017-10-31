/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:29:38 by vnakonec          #+#    #+#             */
/*   Updated: 2017/10/26 23:32:45 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/ft_printf.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>

typedef struct		s_dir
{
	char			*dir;
	time_t			time;
	int				is_d;
	char			*full_path;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_env
{
	int				fl[5];
	DIR				*dirp;
	struct dirent	*dp;
	struct stat		sb;
	t_dir			*list;
}					t_env;

int					check_flags(t_env *e, char *arg);
void				do_lst(t_env *e);
void				ft_ls(t_env *e);
void				revers_list(t_dir **head_ref, t_dir *prev);
void				make_ls(char *dir, t_env *e);
void				perm_dir_link(t_dir *tmp, struct stat fstat);
void				prt_user(struct stat fstat);
void				big_r(t_dir *list, t_env *e);
void				print_l(t_dir *list);
int					prm_err(t_env *e);
int					ft_file_check(t_env *e);
int					open_dir(t_env *e);
void				time_sort(t_dir **head, int done);

#endif
