#ifndef MYMSG
#define MYMSG

#define MAX_VALUE 1396

typedef struct {
  int type;
  char payload[MAX_VALUE];
} my_msg; 

#endif
