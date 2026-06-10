#ifndef BUILTINS_H
# define BUILTINS_H

# include "parser.h"
# include "minishell.h"

int is_builtin(char *cmd);

int builtin_echo(t_command *cmd);
int builtin_pwd(void);
int builtin_cd(t_command *cmd);
int builtin_env(t_shell *shell);
int builtin_exit(t_command *cmd);

int execute_builtin(t_shell *shell, t_command *cmd);

#endif
