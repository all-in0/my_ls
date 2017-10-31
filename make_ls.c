/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:18:31 by vnakonec          #+#    #+#             */
/*   Updated: 2017/10/26 23:22:08 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			make_tot(t_dir *list)
{
	struct stat	fstat;
	int			total;
	t_dir		*tmp;

	tmp = list;
	total = 0;
	while (tmp != NULL)
	{
		lstat(tmp->full_path, &fstat);
		total += fstat.st_blocks;
		tmp = tmp->next;
	}
	ft_printf("total %d\n", total);
	return (1);
}

void		ft_print_ls(t_dir *list, t_env *e, char *path)
{
	t_dir	*tmp;

	if (e->fl[3] == 1)
		time_sort(&list, 0);
	if (e->fl[2] == 1)
		revers_list(&list, NULL);
	if (e->fl[4] == 1)
		ft_putstr(ft_strjoin(path, ":\n"));
	if (e->fl[0] == 1 && make_tot(list))
		print_l(list);
	else
	{
		tmp = list;
		while (tmp != NULL)
		{
			ft_putstr(tmp->dir);
			tmp = tmp->next;
			if (tmp != NULL)
				ft_putchar('\n');
		}
	}
	ft_putchar('\n');
	if (e->fl[4] == 1)
		big_r(list, e);
}

void		dir_sort(t_dir **head, int done)
{
	t_dir	**src;
	t_dir	*tmp;
	t_dir	*next;

	while (!done && *head != NULL && (*head)->next != NULL)
	{
		src = head;
		tmp = *head;
		next = (*head)->next;
		done = 1;
		while (next)
		{
			if (ft_strcmp(tmp->dir, next->dir) > 0 && (done = 0) == 0)
			{
				tmp->next = next->next;
				next->next = tmp;
				*src = next;
			}
			src = &tmp->next;
			tmp = next;
			next = next->next;
		}
	}
}

t_dir		*create_tp(t_env *e, char *dir)
{
	t_dir	*tp;

	tp = (t_dir *)malloc(sizeof(t_dir));
	tp->dir = e->dp->d_name;
	tp->full_path = ft_strjoin(ft_strjoin(dir, "/"), e->dp->d_name);
	lstat(tp->full_path, &e->sb);
	tp->time = e->sb.st_mtime;
	if (S_ISDIR(e->sb.st_mode) == 1)
		tp->is_d = 1;
	else
		tp->is_d = 0;
	return (tp);
}

void		make_ls(char *dir, t_env *e)
{
	t_dir	*list;
	t_dir	*tp;
//	int		a;
//
//	a = 0;
	list = NULL;
	if ((e->dirp = opendir(dir)) != NULL)
	{
		while ((e->dp = readdir(e->dirp)) != NULL)
		{
			if (e->dp->d_name[0] != '.' || e->fl[1] == 1)
			{
				tp = create_tp(e, dir);
				tp->next = list;
				list = tp;
//				a++;
//				if (a > 50)
//					break ;
			}
		}
		dir_sort(&list, 0);
		ft_print_ls(list, e, dir);
		return ;
	}
	ft_file_check(e);
}
