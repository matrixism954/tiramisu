/* SPDX-License-Identifier: GPL-2.0-only */

#include "../include/service.h"
#include "../include/definitions.h"
#include "../include/print.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <fcntl.h>

#include <sys/wait.h>

int start_service(char* service) {
  char path[1024];
  char command[2048];

  snprintf(path, sizeof(path), "%s/services/%s", PREFIX, service);
  snprintf(command, sizeof(command), "sh %s &", path);
  
  int status = system(command);

  if (WIFEXITED(status) && WEXITSTATUS(status) == 1) {
    error_start(service);
    return 1;
  } else if (WIFEXITED(status) && WEXITSTATUS(status) == 127) {
    error_found(service);
    return 127;
  }
  
  ok_start(service);
  return 4;
}

void system_startup_start_service(void) {
  char script[1024];
  char command[2048];

  snprintf(script, sizeof(script), "%s/%s", PREFIX, "start.sh");
  snprintf(command, sizeof(command), "sh %s", script);

  system(command);
}

int stop_service(char* service) {
  char path[1024];
  char command[2048];

  snprintf(path, sizeof(path), "%s/services/%s", PREFIX, service);
  snprintf(command, sizeof(command), "sh -c 'source %s; stop_service_%s'", path, service);

  int status = system(command);

  if (WIFEXITED(status) && WEXITSTATUS(status) == 1) {
    error_stop(service);
    return 1;
  } else if (WIFEXITED(status) && WEXITSTATUS(status) == 127) {
    error_found(service);
    return 127;
  }

  ok_stop(service);
  return 4;
}

void system_shutdown_stop_service(void) {
  char path[1024];
  char command[2048];

  snprintf(path, sizeof(path), "%s/%s", PREFIX, "shutdown.sh");
  snprintf(command, sizeof(command), "sh %s", path);

  system(command);
}

int service_status(char* service) {
  char path[1024];
  char buffer[2048];

  ssize_t read_bytes;

  snprintf(path, sizeof(path), "%s/services/%s.status.txt", PREFIX, service);

  int fd = open(path, O_RDONLY);
  if (!fd) {
    perror("open");
    return 1;
  }

  printf("%s status: ", service);

  while ((read(fd, buffer, sizeof(buffer) - 1)) > 0) {
    buffer[read_bytes] = '\0';
    snprintf(buffer, sizeof(buffer), "%s", buffer[read_bytes]);

    printf("%s", buffer);
  }
}
