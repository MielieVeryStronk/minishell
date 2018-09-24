/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:14:06 by enikel            #+#    #+#             */
/*   Updated: 2018/09/24 14:44:43 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include <stdlib.h>

void	ft_printcolour(char *colour);
void	ms_printprompt();
void	ms_cmd_all(char **av, char **env);
void	ms_cmd_echo(char **av);
void	ms_err(int	err);
void	ms_get_av(char **env);
char	**ms_arg_split(char *str);

#endif
