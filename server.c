/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:45:37 by salmazro          #+#    #+#             */
/*   Updated: 2022/07/21 16:45:07 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	i;

	i = n;
	if (n < 0)
	{
		ft_putchar('-');
		i = n * -1;
	}
	if (i / 10 != 0)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + 48);
}

void	ft_signalhandler(int sig)
{
	static int				i;
	static unsigned char	str;

	str |= (sig == SIGUSR2);
	i++;
	if (i == 8)
	{
		ft_putchar(str);
		i = 0;
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "The PID number is:", 30);
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, ft_signalhandler);
	signal(SIGUSR2, ft_signalhandler);
	while (1)
		pause();
	return (0);
}
