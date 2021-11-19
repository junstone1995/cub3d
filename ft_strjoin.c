/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:58:18 by junseole          #+#    #+#             */
/*   Updated: 2021/11/19 15:02:43 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*buff;

	if (!s1 || !s2)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buff)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		buff[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		buff[i] = s2[j];
		i++;
		j++;
	}
	buff[i] = '\0';
	return (buff);
}
