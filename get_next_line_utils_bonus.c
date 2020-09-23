/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:22:03 by flavon            #+#    #+#             */
/*   Updated: 2020/08/12 17:45:21 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_list_del_elem(t_list *list, t_list **begin_list)
{
	t_list	*elem;
	t_list	*tmp;

	elem = NULL;
	free(list->line->line);
	free(list->line);
	if (*begin_list != list)
	{
		tmp = *begin_list;
		while (tmp != 0 && tmp != list)
		{
			elem = tmp;
			tmp = tmp->next;
		}
		if (tmp == list)
			elem->next = list->next;
	}
	else
		*begin_list = list->next;
	free(list);
}

t_list		*ft_list_get_elem(int fd, t_list *list)
{
	while (list != 0)
	{
		if (list->line->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void		ft_list_clear(t_list *list)
{
	t_list	*tmp;

	while (list != 0)
	{
		free(list->line->line);
		free(list->line);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_list		*ft_list_new_add(int fd, t_list **begin_list)
{
	t_list	*list;

	if ((list = malloc(sizeof(t_list))) == 0 ||
		(list->line = malloc(sizeof(t_line))) == 0 ||
		(list->line->line = malloc(sizeof(char) * BUFFER_SIZE)) == 0)
		return (NULL);
	list->line->length = 0;
	list->line->buff = BUFFER_SIZE;
	list->line->fd = fd;
	list->next = *begin_list;
	*begin_list = list;
	return (list);
}

char		*ft_strjoin(char *dst, char *src, size_t len1, size_t len2)
{
	size_t	index;
	size_t	count;
	char	*out_src;

	index = -1;
	count = 0;
	if (((out_src = malloc(sizeof(char) * (len1 + len2))) == 0) &&
		(dst == 0 || src == 0))
		return (NULL);
	while (++index < len1)
		out_src[index] = dst[index];
	while (count < len2)
		out_src[index++] = src[count++];
	return (out_src);
}
