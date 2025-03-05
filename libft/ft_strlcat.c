/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:41:00 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/25 17:11:49 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	else if (dest_len < size)
	{
		while (src[i] != '\0' && dest_len < size - 1)
		{
			dest[dest_len] = src[i];
			dest_len++;
			i++;
		}
		dest[dest_len] = '\0';
		return (dest_len + src_len - i);
	}
	return (src_len + size);
}

// int main()
// {
// 	char str151[10] ="12";
//     char str152[10] ="12";
//     char str153[] = "ABCDEFG";
//     printf("zisaku  : %zu, %s\n", ft_strlcat(str151,str153, 6), str151);
//     printf("library : %zu, %s\n", strlcat(str152,str153, 6), str152);
//     printf("zisaku  : %zu, %s\n", ft_strlcat(str151,str153, 1), str151);
//     printf("library : %zu, %s\n", strlcat(str152,str153, 1), str152);
// 	return (0);
// }