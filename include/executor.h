#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <sys/types.h>

# include "parser.h"

/**
 * @brief Wykonuje pojedyncze polecenie.
 *
 * @param cmd Polecenie do wykonania.
 * @return Kod zakończenia procesu.
 */
int execute_command(t_command *cmd);

int wait_for_child(pid_t pid);

void print_execution(t_command *cmd);

#endif
