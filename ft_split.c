/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:49:18 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/03/10 15:52:06 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int			count_words(const char *str, char c)
{
	int i;
	int count;
	int words;

	i = 0;
	count = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			words = 0;
		else if (words == 0)
		{
			words = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_strlem(const char *s, char c, int d)
{
	int i;

	i = 0;
	while (s[d] != c && s[d] != '\0')
	{
		i++;
		d++;
	}
	return (i);
}

static char	**ft_frees(char **w, int j)
{
	while (--j)
		free(w[j]);
	free(w);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**w;
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (!(w = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (0);
	while (s[i] != '\0' && j < count_words(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(w[j] = (char*)malloc(sizeof(char) * ft_strlem(s, c, i) + 1)))
			return (ft_frees(w, j));
		while (s[i] != '\0' && s[i] != c)
			w[j][k++] = s[i++];
		w[j++][k] = '\0';
	}
	w[j] = 0;
	return (w);
}
