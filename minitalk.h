/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:27:43 by federico          #+#    #+#             */
/*   Updated: 2024/08/13 01:47:43 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define NOT_PID -1

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>

void	put_string(char *str);
int		pid_convert_int(char *str);
int		num_len(int num);
char	*pid_convert_str(int pid);

#endif