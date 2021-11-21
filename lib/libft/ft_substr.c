/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:46:30 by junseole          #+#    #+#             */
/*   Updated: 2021/11/21 15:47:04 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buff;

	if (!s)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			buff[i] = s[start + i];
			i++;
		}
	}
	buff[i] = '\0';
	return (buff);
}
