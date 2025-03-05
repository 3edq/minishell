/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:59:59 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/25 17:56:58 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}

// int main()
// {
//     char *test_strings[] = {
//         "Hello, World!",
//         "This is a test.",
//         "ft_putendl_fd works!",
//         NULL
//     };
//     for (size_t i = 0; test_strings[i] != NULL; i++)
//     {
//         ft_putendl_fd(test_strings[i], 1);
//     }
//     return (0);
// }