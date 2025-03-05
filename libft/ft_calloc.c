/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:53:21 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/28 14:13:57 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (size != 0 && nmemb > ((size_t)-1) / size)
		return (NULL);
	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, nmemb * size);
	return (array);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		*arr;
// 	size_t	num_elements;
// 	size_t	i;

// 	num_elements = 5;
// 	arr = (int *)ft_calloc(num_elements, sizeof(int));
// 	if (arr == NULL)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	for (i = 0; i < num_elements; i++)
// 	{
// 		printf("%d\n", arr[i]);
// 	}
// 	free(arr);
// 	return (0);
// }
