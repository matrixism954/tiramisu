/* SPDX-License-Identifier: GPL-2.0-only */

#include "../include/service.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

int main(void) {
  start_service("notepad"); // Test.
  sleep(5);
  stop_service("notepad");
  return 0;
}
