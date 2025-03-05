/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:31:16 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/28 14:55:43 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	total_len;

	if (count == 0 || size == 0)
		return (malloc(0));
	total_len = count * size;
	if (total_len / size != count)
		return (NULL);
	arr = (void *)malloc(total_len);
	if (!arr)
		return (NULL);
	ft_bzero(arr, (total_len));
	return (arr);
}

// int main()
// {
//     size_t count1 = 5;
//     size_t size1 = sizeof(int);
//     int *arr1 = (int *)ft_calloc(count1, size1);
//     if (arr1)
//     {
//         printf("Allocated %zu integers:\n", count1);
//         for (size_t i = 0; i < count1; i++)
//         {
//             printf("arr1[%zu] = %d\n", i, arr1[i]);
//         }
//         free(arr1);
//     }
//     else
//         printf("Memory allocation failed for arr1\n");
//     size_t count2 = 0;
//     size_t size2 = sizeof(char);
//     char *arr2 = (char *)ft_calloc(count2, size2);
//     if (arr2 == NULL)
//         printf("Correctly returned NULL for 0 allocation request.\n");
//     return 0;
// }