#include <readline/readline.h>
#include <readline/history.h>

void shell_loop(void)
{
    char *line;

    while (1)
    {
        line = readline("minishell> ");

        if (!line)
            break;

        if (*line)
            add_history(line);

        /* tutaj później lexer */

        free(line);
    }
}
