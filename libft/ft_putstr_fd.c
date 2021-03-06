/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:41:57 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/17 22:47:59 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*ptr;

	while (!s)
		return ;
	ptr = (char *)s;
	while (*ptr != '\0')
		write(fd, ptr++, 1);
}
