/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:38:27 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/26 21:55:27 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, len1);
	ft_memcpy(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	return (res);
}
