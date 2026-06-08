/******************************************************************************
 * @file shell_loop.c
 * @author Paweł Czarny
 * @brief Główna pętla REPL MiniShell.
 ******************************************************************************/

#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "shell_loop.h"
#include "lexer.h"
#include "parser.h"

/**
 * @brief Główna pętla REPL.
 *
 * Odpowiada za:
 * - odczyt wejścia użytkownika,
 * - zapis historii,
 * - uruchomienie lexer'a,
 * - uruchomienie parsera,
 * - wyświetlenie wyników debugowania.
 *
 * @param shell Struktura przechowująca stan shella.
 */
void shell_loop(t_shell *shell)
{
    char        *line;
    t_token     *tokens;
    t_command   *commands;

    (void)shell;

    while (1)
    {
        line = readline("minishell> ");

        if (!line)
            break;

        if (*line)
            add_history(line);

        tokens = tokenize(line);

        if (tokens)
        {
            print_tokens(tokens);

            commands = parse_tokens(tokens);

            if (commands)
            {
                print_commands(commands);
                free_commands(commands);
            }

            free_tokens(tokens);
        }

        free(line);
    }
}
