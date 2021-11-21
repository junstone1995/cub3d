/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:48:15 by junseole          #+#    #+#             */
/*   Updated: 2021/11/21 15:49:29 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buff;

	buff = (void *)malloc(size * nmemb);
	if (!buff)
		return (NULL);
	ft_bzero(buff, size * nmemb);
	return (buff);
}
