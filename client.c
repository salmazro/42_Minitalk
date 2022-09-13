/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:23:07 by salmazro          #+#    #+#             */
/*   Updated: 2022/07/21 16:43:04 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	num;
	int		i;
	int		sign;

	num = 0;
	i = 0;
	sign = -1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -sign;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i])
	{
		num = num * 10;
		num = num + (str[i++] - '0');
	}
	if (num > 2147483648 && sign == -1)
		return (0);
	else if (num > 2147483647 && sign == 1)
		return (1);
	return ((int) num);
}

void	ft_sig2kill(pid_t pid, char *str)
{
	int	i;

	while (*str != '\0')
	{
		i = 7;
		while (i >= 0 && *str)
		{
			if ((*str >> i) & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_error("Invalid PID SIGUSR2\n");
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error("Invalid PID SIGUSR1\n");
			}
			usleep(100);
			i--;
		}
		str++;
	}
}

int	main(int arc, char **arg)
{
	int	i;

	i = 0;
	if (arc != 3)
		ft_error("Invalid number of arguments\n");
	while (arg[1][i])
	{
		if (ft_isalpha(arg[1][i]))
			ft_error ("Invalid PID contains character\n");
		if (!arg[2][0])
			ft_error ("Empty string .. Nothing to send\n");
		i++;
	}
	if (!ft_errorhandler(ft_atoi(arg[1])))
		return (0);
	ft_sig2kill(ft_atoi(arg[1]), arg[2]);
	return (0);
}
