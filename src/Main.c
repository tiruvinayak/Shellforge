#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void)
{
    // Display a welcome banner
    printf("=====================================\n");
    printf("         Shellforge\n");
    printf(" A Unix Style Shell written in C\n");
    printf("=====================================\n");

    // Initialize history
    using_history();

    char *line;

    while (1)
    {
        // Read user input
        line = readline("shellforge$ ");

        if (line == NULL)
        {
            printf("\nGoodbye!\n");
            break;
        }

        // Ignore empty input
        if (strlen(line) == 0)
        {
            free(line);
            continue;
        }

        // Add command to history
        add_history(line);

        // Display history
        if (strcmp(line, "history") == 0)
        {
            HIST_ENTRY **hist_list = history_list();

            if (hist_list)
            {
                for (int i = 0; hist_list[i]; i++)
                {
                    printf("%d %s\n", i + history_base, hist_list[i]->line);
                }
            }

            free(line);
            continue;
        }

        // Exit command
        if (strcmp(line, "exit") == 0)
        {
            free(line);
            printf("Exiting...\n");
            break;
        }

        // Echo user input
        printf("YOU ENTERED : %s\n", line);

        free(line);
    }

    return 0;
}
