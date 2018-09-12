#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read_command(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; 
  getline(&line, &bufsize, stdin);
  return line;
}

#define BASH_SPLIT " \t\r\n\a"
char **split_command(char *line)
{
  int bufsize = 64, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  //It returns a pointer to the first token,it is return pointers to within the string we give it, and place \0 bytes at the end of each token.
  token = strtok(line, BASH_SPLIT); 
  while (token != NULL) {
    tokens[position] = token;
    position++;


    token = strtok(NULL, BASH_SPLIT);
  }
  tokens[position] = NULL;
  return tokens;
}

int launch_command(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("Error");
    }
  } else if (pid < 0) {
    // Error forking
    perror("Error");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int execute_command(char **args)
{
  int i;
  if (args[0] == NULL) {
    return 1;
  }
  
  return launch_command(args);
}

void terminate(void)
{
  
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = read_command();
    args = split_command(line);
    status = execute_command(args);

    free(line);
    free(args);
  } while (status);  
}

int main(int argc, char **argv)
{
  terminate();
  return 0;
}
