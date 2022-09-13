/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:50:09 by salmazro          #+#    #+#             */
/*   Updated: 2022/07/21 16:25:27 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_signalhandler(int sig);
void	ft_error(char *error);
int		ft_errorhandler(pid_t pid);
int		ft_isalpha(int c);
int		ft_atoi(const char *str);
void	ft_sig2kill(pid_t pid, char *str);

#endif
