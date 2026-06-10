#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <sys/types.h>

# include "parser.h"

/**
 * @brief Wykonuje pojedyncze polecenie.
 *
 * Funkcja rozpoznaje builtiny oraz
 * programy zewnętrzne.
 *
 * @param shell Struktura shella.
 * @param cmd Polecenie do wykonania.
 *
 * @return Kod zakończenia polecenia.
 */
int execute_command(t_shell *shell,
                    t_command *cmd);

int wait_for_child(pid_t pid);

void print_execution(t_command *cmd);

#endif
