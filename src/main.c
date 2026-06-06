#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    t_shell shell;

    (void)argc;
    (void)argv;

    shell.env = env_init(envp);
    shell.last_exit_status = 0;

    init_signals();

    env_destroy(shell.env);
    return (0);
}
