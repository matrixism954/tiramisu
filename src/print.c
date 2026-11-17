/* SPDX-License-Identifier GPL-2.0-only */

#include "../include/print.h"
#include "../include/colors.h"

#include <stdio.h>
#include <string.h>

// logging functions

void inform(char* msg) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sINFO%s]%s %s\n", black_light, cyan_light, black_light, reset, msg);
  
  printf(edit);
}

void warn(char* msg) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sWARN%s]%s %s\n", black_light, yellow_light, black_light, reset, msg);
  
  printf(edit);
}

void error(char* msg) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sERROR%s]%s %s\n", black_light, red_light, black_light, reset, msg);
  
  printf(edit);
}

void fatal(char* msg) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sFATAL%s]%s %s\n", black_light, magenta_blink, black_light, reset, msg);
  
  printf(edit);
}

void ok(char* msg) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sOK%s]%s %s\n", black_light, green_light, black_light, reset, msg);
  
  printf(edit);
}

// error() for services

void error_found(char* service) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sERROR%s]%s Failed to find service: %s\n", black_light, red_light, black_light, reset, service);
  
  printf(edit);
}

void error_stop(char* service) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sERROR%s]%s Failed to stop service: %s\n", black_light, red_light, black_light, reset, service);
  
  printf(edit);
}

void error_start(char* service) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sERROR%s]%s Failes to start service: %s\n", black_light, red_light, black_light, reset, service);
  
  printf(edit);
}

// ok() for services

void ok_stop(char* service) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sOK%s]%s Stopped service: %s\n", black_light, green_light, black_light, reset, service);
  
  printf(edit);
}

void ok_start(char* service) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sOK%s]%s Started service: %s\n", black_light, green_light, black_light, reset, service);
  
  printf(edit);
}

// fatal() for services

void fatal_found(char* service) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sFATAL%s]%s Failed to find service: %s\n", black_light, magenta_blink, black_light, reset, service);
  
  printf(edit);
}

void fatal_stop(char* service) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sFATAL%s]%s Failed to stop service: %s\n", black_light, magenta_blink, black_light, reset, service);
  
  printf(edit);
}
void fatal_start(char* service) {
  char edit[512];
  snprintf(edit, sizeof(edit), "%s[%sFATAL%s]%s Failed to start service: %s\n", black_light, magenta_blink, black_light, reset, service);
  
  printf(edit);
}
