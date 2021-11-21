/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:53:48 by junseole          #+#    #+#             */
/*   Updated: 2021/11/21 16:07:38 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_cnt(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

static char	*malloc_char(char **ret, int size)
{
	char	*s;

	s = (char *)malloc(size);
	if (!s)
	{
		ft_free(ret);
		return (0);
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*from;
	size_t	idx;
	size_t	size;

	ret = (char **)malloc(sizeof(char *) * (get_word_cnt(s, c) + 1));
	if (!ret || !s)
		return (ft_free(ret));
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				++s;
			size = s - from + 1;
			ret[idx] = malloc_char(ret, size);
			ft_strlcpy(ret[idx++], from, size);
		}
		else
			++s;
	}
	ret[idx] = 0;
	return (ret);
}
