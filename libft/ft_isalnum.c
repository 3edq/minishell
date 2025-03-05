/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:42:57 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/28 15:08:15 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

// int main()
// {
// 	printf("library :%d\n", isalnum('2'));
//     printf("zisaku  :%d\n", ft_isalnum('2'));
//     printf("library :%d\n", isalnum('A'));
//     printf("zisaku  :%d\n", ft_isalnum('A'));
//     printf("library :%d\n", isalnum('/'));
//     printf("zisaku  :%d\n", ft_isalnum('/'));
// 	return (0);
// }