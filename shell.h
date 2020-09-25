#ifndef _QUISH_MAIN_H
#define _QUISH_MAIN_H

int main(void);
static void loop(void);
static void execute(char *input[]);
static void split(char *restrict input, char* buffer[], const size_t bufsize);

#endif //_QUISH_MAIN_H
