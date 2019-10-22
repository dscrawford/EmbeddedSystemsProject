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
  uint8_t trainAddr = 0b1010;
  int8_t speed = 0;
  while (choice != 'e') {
    choice = getChoice();
    clear();
    if (choice == '0') {
      printw("Error: Invalid choice\n\n");
      continue;
    }
    executeChoice(choice, &speed, &trainStarted, trainAddr);
  }
}

void executeChoice(char choice, int8_t* speed,
		   bool* trainStarted, uint8_t trainAddr) {
  if (choice != ' ' && !*trainStarted) {
    printw("Error: Train not yet started\n\n");
    return;
  }
  switch (choice) {
  case ' ':
    //Check if train is already started
    if (!*trainStarted) {
      printw("Starting train..\n");
    }
    else {
      sysHalt();
      printw("Stopping train..\n");
    }
    *trainStarted = !(*trainStarted);
    break;
  case 'r':
    trainRingBell(trainAddr);
    printw("Ringing the bell..\n");
    break;
  case 'w':
    if (*speed != 5) {
      *speed += 1;
      engineSetRelSpeed(trainAddr, *speed);
      printw("Accelerating the train..\n");
    }
    break;
  case 'm':
    trainFwdDir(trainAddr);
    printw("Moving the train..\n");
    break;
  case 's':
    if (*speed != -5) {
      *speed -= 1;
      engineSetRelSpeed(trainAddr, *speed);
      printw("Decelerating the train..\n");
    }
    break;
  case 'e':
    sysHalt();
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
