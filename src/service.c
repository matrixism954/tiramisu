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
  snprintf(command, sizeof(command), "%s %s", SHELL, path);
  
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
  snprintf(command, sizeof(command), "%s %s", SHELL, script);

  system(command);
}

int stop_service(char* service) {
  char path[1024];
  char command[2048];

  snprintf(path, sizeof(path), "%s/services/%s", PREFIX, service);
  snprintf(command, sizeof(command), "bash -c 'source %s; stop_service_%s'", path, service);

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
  snprintf(command, sizeof(command), "%s %s", SHELL, path);

  system(command);
}
