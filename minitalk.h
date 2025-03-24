/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:38:17 by araji             #+#    #+#             */
/*   Updated: 2025/03/23 23:53:19 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

void	send_message(int pid, unsigned char ch);
void	handle_signal(int signal, siginfo_t *info, void *context);

void	send_message(int pid, unsigned char ch);
void	handle_signal_bns(int signal, siginfo_t *info, void *context);
void	confirmation(int signal);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *s);
int		get_check_pid(char *pid);
int		ft_isdigit(int c);

#endif