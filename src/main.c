/* SPDX-License-Identifier: GPL-2.0-only */

#include "../include/service.h"
#include "../include/print.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <fcntl.h>

int main(void) {
  int operating_system = open("/etc/os-release", O_RDONLY);
  char operating_system_name[12];

  if (operating_system == -1) {
    perror("open");
    return 1;
  }

  char buffer[1024];
    
  ssize_t bytes_read = read(operating_system, buffer, sizeof(buffer) - 1);
    
  // 3. Close the file descriptor using close() from <unistd.h>
  close(operating_system);

  if (bytes_read <= 0) {
    perror("read");
    return 1;
  }
  buffer[bytes_read] = '\0'; // Null-terminate the string

  // 4. Parse the buffer to find PRETTY_NAME
  char *line = strtok(buffer, "\n");
  while (line != NULL) {
    if (strncmp(line, "PRETTY_NAME=", 12) == 0) {
      char msg[512];
      snprintf(msg, sizeof(msg), "Welcome to Tiramisu! running: %s", line + 12);

      // Print the value after "PRETTY_NAME="
      inform(msg);
      break;
    }
    line = strtok(NULL, "\n");
  }

  return 0;
}
