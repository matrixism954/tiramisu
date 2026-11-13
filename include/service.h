#ifndef SERVICE
#define SERVICE

void start_service(char* service);
void stop_service(char* service);

void system_startup_start_service(void);
void system_shutdown_stop_service(void);

#endif
