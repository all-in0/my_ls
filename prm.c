/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:24:24 by vnakonec          #+#    #+#             */
/*   Updated: 2017/10/26 23:26:18 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		big_r(t_dir *list, t_env *e)
{
	t_dir	*tp;

	tp = list;
	while (tp != NULL)
	{
		if (tp->is_d == 1 && tp->dir[0] != '.')
			make_ls(tp->full_path, e);
		tp = tp->next;
	}
}

void		perm_prt2(struct stat fstat)
{
	if (fstat.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	if (fstat.st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (fstat.st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (fstat.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		perm_prt(struct stat fstat)
{
	if (fstat.st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (fstat.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (fstat.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	if (fstat.st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (fstat.st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	perm_prt2(fstat);
}

void		perm_dir_link(t_dir *tmp, struct stat fstat)
{
	if (tmp->is_d)
		ft_putchar('d');
	else
	{
		if (S_ISLNK(fstat.st_mode))
			ft_putchar('l');
		else
			ft_putchar('-');
	}
	perm_prt(fstat);
	ft_putstr("  ");
}

void		prt_user(struct stat fstat)
{
	char			*str;
	struct passwd	*pswd;
	struct group	*grp;

	pswd = getpwuid(fstat.st_uid);
	grp = getgrgid(fstat.st_gid);
	str = ft_strjoin(ft_strjoin(pswd->pw_name, "  "), grp->gr_name);
	ft_putstr("  ");
	ft_putstr(str);
	ft_putstr("  ");
}
