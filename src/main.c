/******************************************************************************
 * @file main.c
 * @author Paweł Czarny
 * @brief Punkt wejścia programu MiniShell.
 *
 * Inicjalizuje:
 * - środowisko procesu,
 * - obsługę sygnałów,
 * - główną strukturę shella.
 *
 * Następnie uruchamia pętlę REPL.
 ******************************************************************************/

#include "minishell.h"
#include "shell_loop.h"

/**
 * @brief Główna funkcja programu.
 *
 * Tworzy i inicjalizuje strukturę shella,
 * uruchamia obsługę sygnałów oraz główną pętlę REPL.
 *
 * @param argc Liczba argumentów programu.
 * @param argv Argumenty programu.
 * @param envp Zmienne środowiskowe procesu.
 *
 * @return Kod zakończenia procesu.
 */
int main(int argc, char **argv, char **envp)
{
    t_shell shell;

    (void)argc;
    (void)argv;

    shell.env = env_init(envp);
    shell.last_exit_status = 0;

    init_signals();

    shell_loop();

    env_destroy(shell.env);

    return (0);
}
