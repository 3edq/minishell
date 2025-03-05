/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:27:18 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/25 17:42:12 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

// int main()
// {
// 	printf("library :%d\n", isalpha('2'));
//     printf("zisaku  :%d\n", ft_isalpha('2'));
//     printf("library :%d\n", isalpha('A'));
//     printf("zisaku  :%d\n", ft_isalpha('A'));
//     printf("library :%d\n", isalpha('/'));
//     printf("zisaku  :%d\n", ft_isalpha('/'));
// 	return (0);
// }