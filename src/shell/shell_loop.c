#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "shell_loop.h"

void shell_loop(t_shell *shell)
{
    char *line;

    (void)shell;

    while (1)
    {
        line = readline("minishell> ");

        if (!line)
            break;

        if (*line)
            add_history(line);

        free(line);
    }
}
