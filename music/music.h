#include <time.h>

typedef struct _song song;

void play(song*);
void stop(song*);
time_t get_current_time(song*);
time_t get_max_time(song*);
