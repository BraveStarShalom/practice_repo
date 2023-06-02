#ifndef SHELL_HEADER
#define SHELL_HEADER

#define MAX_COMMAND_LENGTH 256

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void visual_cue();
void exec_directive(const char *command);

#endif
