#include "ui.h"

void startTrain() {
  initscr();
  raw();
  runTrain();
  endwin();
}

void runTrain() {
  printw("Starting program..\n\n");
  char choice = '\0';
  bool trainStarted = false;
  while (choice != 'e') {
    choice = getChoice();
    if (choice == '0') {
      printw("Error: Invalid choice\n");
      continue;
      clear();
    }
    clear();
    executeChoice(choice, &trainStarted);
  }
}

void executeChoice(char choice, bool* trainStarted) {
  switch (choice) {
  case ' ':
    //Check if train is already started
    if (!*trainStarted) {
      printw("Starting train..\n");
      
    }
    else {
      printw("Stopping train..\n");
    }
    *trainStarted = !(*trainStarted);
    break;
  case 'r':
    printw("Ringing the bell..\n");
    break;
  case 'w':
    printw("Accelerating the train..\n");
    break;
  case 'm':
    printw("Moving the train..\n");
    break;
  case 's':
    printw("Decelerating the train..\n");
    break;
  case 'e':
    printw("Exiting program and stopping train..");
    break;
  }
  printw("\n");
}
 
bool isValidChoice(char c) {
  const char validChoices[11] = {' ', 'R', 'r', 'W', 'w', 'M',
				 'm', 'S', 's', 'E', 'e'};
  for (int i = 0; i < 11; ++i) {
    if (c == validChoices[i])
      return true;
  }
  return false;
}

char getChoice() {
  printw("Space: Start/Stop the train\n");
  printw("R    : Ring the bell\n");
  printw("W    : Accelerate the train\n");
  printw("M    : Move the train\n");
  printw("S    : Decelerate the train\n");
  printw("E    : End program\n");
  
  char c = getch();
  if (!isValidChoice(c)) {
    return '0';
  }
  return tolower(c);
}
