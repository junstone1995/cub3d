/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:40:40 by junseole          #+#    #+#             */
/*   Updated: 2021/11/21 16:01:52 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (!src)
		return (0);
	len = ft_strlen(src);
	if (dst == 0 || size == 0)
		return (len);
	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}
