/* SPDX-License-Identifier: GPL-2.0-only */

#include "../include/service.h"
#include "../include/print.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <fcntl.h>

// Lord, Verity.
// Master of humani, TEE.
// LOOORD, ack. VEWITY.
// Dey kall me Mastaah Mastahhh Masaaaahhhhhhh

void usage(char* name) {
  printf("usage: (sudo/doas/e.t.c) %s [start, stop, status] <service name>", name);
}

int main(int argc, char** argv) {
  if (geteuid() == 0) {
      inform("Running with root privileges.");
  } else {
      fatal("Tiramisu only runs with root privileges!");
      return 1;
  }

  int operating_system = open("/etc/os-release", O_RDONLY);
  char operating_system_name[12];

  if (operating_system == -1) {
    perror("open");
    return 1;
  }

  char buffer[1024];
    
  ssize_t bytes_read = read(operating_system, buffer, sizeof(buffer) - 1);
    
  // close the file descriptor using close() from <unistd.h>
  close(operating_system);

  if (bytes_read <= 0) {
    perror("read");
    return 1;
  }
  buffer[bytes_read] = '\0'; // Null-terminate the string

  // parse the buffer to find PRETTY_NAME
  char *line = strtok(buffer, "\n");
  while (line != NULL) {
    if (strncmp(line, "PRETTY_NAME=", 12) == 0) {
      char msg[512];
      snprintf(msg, sizeof(msg), "Welcome to Tiramisu! running: %s", line + 12);

      // print the value after "PRETTY_NAME="
      inform(msg);
      break;
    }
    line = strtok(NULL, "\n");
  }

  // argument handling.

  if (argc > 1 && strcmp(argv[1], "start") == 0 && argv[2]) {
    start_service(argv[2]);
  } else if (strcmp(argv[1], "stop") == 0) {
    stop_service(argv[2]);
  } else if (strcmp(argv[1], "status") == 0) {
    service_status(argv[2]);
  }

  return 0;
}
