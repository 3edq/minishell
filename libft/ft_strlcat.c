/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:51:59 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/30 14:54:47 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	if (!src || (!dest && dstsize > 0))
		return (0);
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0' && dest_len < dstsize)
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize == 0)
		return (src_len);
	if (dest_len == dstsize)
		return (dstsize + src_len);
	i = 0;
	while (src[i] != '\0' && dest_len + i < dstsize - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i < dstsize)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char		dest1[15] = "Hello";
// 	const char	src1[] = " World";
// 	char		dest2[15] = "Hello";
// 	const char	src2[] = "";
// 	char		dest3[6] = "Hello";
// 	const char	src3[] = " World";
// 	char		*dest4;
// 	const char	src4[] = " World";

// 	dest4 = NULL;
// 	printf("%zu, %s\n", ft_strlcat(dest1, src1, sizeof(dest1)), dest1);
// 	printf("%zu, %s\n", ft_strlcat(dest2, src2, sizeof(dest2)), dest2);
// 	printf("%zu, %s\n", ft_strlcat(dest3, src3, sizeof(dest3)), dest3);
// 	printf("%zu, %s\n", ft_strlcat(dest4, src4, 0), "(NULL)");
// 	return (0);
// }
