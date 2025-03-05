/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:34:38 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/29 16:51:23 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	n_len;

	if (*needle == '\0')
		return ((char *)str);
	n_len = ft_strlen((char *)needle);
	while (*str != '\0' && len >= n_len)
	{
		if (*str == *needle && ft_memcmp(str, needle, n_len) == 0)
		{
			return ((char *)str);
		}
		str++;
		len--;
	}
	return (NULL);
}

// int main()
// {
// 	char str81_0[] ="nesugosita!!!";
//     char str81_1[] ="go";
//     printf("zisaku  : %s\n", ft_strnstr(str81_0, str81_1, 5));
//     printf("library : %s\n", strnstr(str81_0, str81_1, 5));
//     printf("zisaku  : %s\n", ft_strnstr(str81_0, str81_1, 6));
//     printf("library : %s\n", strnstr(str81_0, str81_1, 6));
// 	return (0);
// }