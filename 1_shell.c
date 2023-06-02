#include "shell.h"

/**
  * visual_cue - Displays the prompt.
  */
void visual_cue(void)
{
	printf("simple_shell$ ");
}

/**
  * exec_directive - the command entered by the user.
  * @command: the command parameter.
 */
void exec_directive(const char *command)
{
	char path[MAX_COMMAND_LENGTH];

	snprintf(path, sizeof(path), "/bin/%s", command);

	if (access(path, X_OK) == 0)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			/*Child process*/
			execl(path, command, (char *)NULL);
			exit(EXIT_SUCCESS);
		}
		else if
		(pid > 0)
		{
			/*Parent process*/
			wait(NULL);
		}
		else
		{
			/*Error forking process*/
			perror("fork");
		}
	}
	else
	{
		printf("Command not found: %s\n", command);
	}
}

/**
  * main - Entry point.
  * Return: 0 (Success).
  */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		visual_cue();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			/*End of file (Ctrl+D) condition*/
			printf("\n");
			break;
		}

		/*Remove trailing newline character*/
		command[strcspn(command, "\n")] = '\0';

		exec_directive(command);
	}

	return (0);
}
