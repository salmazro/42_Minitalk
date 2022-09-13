/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:49:08 by salmazro          #+#    #+#             */
/*   Updated: 2022/07/21 16:44:07 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *error)
{
	while (*error)
		write(1, error++, 1);
	exit(1);
}

int	ft_errorhandler(pid_t pid)
{
	if (pid <= 0 || pid >= 100000)
		ft_error("Invalid PID out of range\n");
	return (1);
}
