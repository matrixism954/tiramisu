/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef SERVICE
#define SERVICE

int start_service(char* service);
int stop_service(char* service);

void system_startup_start_service(void);
void system_shutdown_stop_service(void);

#endif
