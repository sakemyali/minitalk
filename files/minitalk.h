/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:51:31 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/28 14:36:59 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	s_signal(int signo, void *handler, bool use_siginfo);
int		ft_atoi(const char *nptr);
void    k_kill(__pid_t pid, int signum);

#endif
