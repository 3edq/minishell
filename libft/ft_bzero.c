/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:39:34 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/25 17:09:55 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// int main()
// {
// 	char str171[] ="radwimps";
//     char str172[] ="radwimps";
//     ft_bzero(str171, 3);
//     bzero(str172, 3);
//     printf("zisaku  : %s\n", str171 + 3);
//     printf("library  : %s\n", str172 + 3);
//     printf("zisaku  : %s\n", str171 + 2);
//     printf("library  : %s\n", str172 + 2);
// 	return(0);
// }