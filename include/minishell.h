#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "env.h"
# include "signals.h"
# include "pipes.h"
# include "redirections.h"
# include "utils.h"

typedef struct s_shell
{
    t_env   *env;
    int     last_exit_status;
} t_shell;

#endif
