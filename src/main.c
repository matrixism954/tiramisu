#include "../include/service.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

int main(void) {
  start_service("notepad");
  return 0;
}
