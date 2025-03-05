/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:19:27 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/25 18:09:47 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!dest || !src)
		return (count);
	while (src[count])
		count++;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size)
		dest[i] = '\0';
	return (count);
}

// int main()
// {
//     const char *src = "Hello, World!";
//     char dest1[20];
//     char dest2[5];
//     size_t result1 = ft_strlcpy(dest1, src, sizeof(dest1));
//     printf("Copied string: %s\n", dest1);
//     printf("Length of source string: %zu\n", result1);
//     size_t result2 = ft_strlcpy(dest2, src, sizeof(dest2));
//     printf("Copied string (with limited size): %s\n", dest2);
//     printf("Length of source string: %zu\n", result2);
//     return 0;
// }