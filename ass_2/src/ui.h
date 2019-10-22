#ifndef UI_H
#define UI_H

#include "command.h"
#include <stdio.h>
#include <ncurses.h>
#include <ctype.h>

void startTrain();
void runTrain();
char getChoice();
void executeChoice(char, bool*);

#endif
