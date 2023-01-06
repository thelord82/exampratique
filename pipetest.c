#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  int fd[2];  // File descriptor array to hold the pipe
  pid_t pid;  // PID of child process

  // Create the pipe
  if (pipe(fd) == -1) {
    perror("pipe");
    return 1;
  }

  // Fork a child process
  pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
  }

  // Child process
  if (pid == 0) {
    // Close the read end of the pipe
    close(fd[0]);

    // Write a message to the pipe
    write(fd[1], "Hello, world!", 13);

    // Close the write end of the pipe
    close(fd[1]);
  }
  // Parent process
  else {
    // Close the write end of the pipe
    close(fd[1]);

    // Read from the pipe
    char buf[1024];
    int n = read(fd[0], buf, 1024);
    if (n == -1) {
      perror("read");
      return 1;
    }

    // Print the message
    printf("Received message: %.*s\n", n, buf);

    // Close the read end of the pipe
    close(fd[0]);
  }

  return 0;
}