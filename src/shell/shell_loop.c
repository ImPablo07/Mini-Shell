/******************************************************************************
 * @file shell_loop.c
 * @author Paweł Czarny
 * @brief Główna pętla REPL MiniShell.
 *
 * Odpowiada za:
 * - odczyt poleceń użytkownika,
 * - historię poleceń,
 * - tokenizację,
 * - parsowanie,
 * - wykonywanie poleceń.
 ******************************************************************************/

#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "shell_loop.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"

/**
 * @brief Główna pętla REPL MiniShell.
 *
 * Funkcja działa do momentu otrzymania EOF
 * (np. Ctrl+D).
 *
 * @param shell Struktura przechowująca stan shella.
 */
void shell_loop(t_shell *shell)
{
    char        *line;
    t_token     *tokens;
    t_command   *commands;

    while (1)
    {
        line = readline("minishell> ");

        /* Ctrl+D */
        if (!line)
        {
            write(STDOUT_FILENO, "exit\n", 5);
            break;
        }

        /* Pomijamy puste polecenia */
        if (*line == '\0')
        {
            free(line);
            continue;
        }

        add_history(line);

        tokens = tokenize(line);

        if (!tokens)
        {
            free(line);
            continue;
        }

        commands = parse_tokens(tokens);

        if (commands)
        {
            shell->last_exit_status =
    execute_command(shell,
                    commands);

            free_commands(commands);
        }

        free_tokens(tokens);
        free(line);
    }
}
