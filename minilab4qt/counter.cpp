#include "counter.h"

Counter::Counter() { count = 0;}
void Counter::add() { count ++; }
int Counter::getCount() { return count; }
