#ifndef PRINT
#define PRINT

void inform(char* msg);
void error(char* msg);
void warn(char* msg);
void fatal(char* msg);

void error_found(char* service);
void error_stop(char* service);
void error_start(char* service);

void ok_stop(char* service);
void ok_start(char* service);

void fatal_found(char* service);
void fatal_stop(char* service);
void fatal_start(char* service);

#endif
