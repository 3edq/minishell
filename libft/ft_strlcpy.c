/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:51:54 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/30 14:56:12 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	if (!src || (!dest && size > 0))
		return (0);
	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src[] = "what the fuck";
// 	char	dest[30];
// 	size_t	copied_len;

// 	copied_len = ft_strlcpy(dest, src, sizeof(dest));
// 	printf("Copied string: %s\n", dest);
// 	printf("Original string length: %zu\n", copied_len);
// 	return (0);
// }
