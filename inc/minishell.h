/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:14:06 by enikel            #+#    #+#             */
/*   Updated: 2018/09/30 14:14:51 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <sys/types.h>
# include <signal.h>

void		ft_printcolour(char *colour);
void		ms_printprompt();
void		ms_cmd_all(char **av, int ac, char ***env);
void		ms_cmd_echo(char **av);
void		ms_err(int	err);
char		**ms_get_av(char ***env);
char		**ms_arg_split(char *str, int ac);
void		ms_cmd_env(char ***env);
char		**ms_env_mlc(char **old);
void		ms_free_tab(char **tab);
void		ms_sub_var(char ***av, char ***env);
int			ms_argscnt(const char *str);
void		ms_cmd_setenv(char ***av, int ac, char ***env);
int			ms_env_size(char **env);
char		**ms_new_env(char **av, char **old);
char		*ft_strjoin_mult(int ac, ...);
int			ms_find_env(char *av, char ***env);
void		ms_cmd_unsetenv(char ***av, int ac, char ***env);
void		ms_cmd_cd(char **av, int ac, char ***env);
void		ms_cmd_pwd(int ac);
char		*ft_strzstr(const char *haystack, const char *needle);

#endif
