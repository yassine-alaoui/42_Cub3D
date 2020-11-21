/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:04:30 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/11/21 14:25:12 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_isdigit(int c)
{
	if (c == '-')
		return (1);
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_error(char *s)
{
	int		i;
	char	*e;

	i = -1;
	ft_lstclear(&g_mylist);
	e = "\033[1;31m Error\n >> \033[0;31m";
	write(1, e, ft_strlen(e));
	while (s[++i] != '\0')
		write(1, s + i, 1);
	write(1, "\n", 2);
	exit(EXIT_FAILURE);
}

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list *tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
