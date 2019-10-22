#include "ui.h"

void startTrain() {
  int choice = 0;
  while (choice != 6) {
    choice = getOption();
    if (choice == 0) {
      printf("Error: Invalid choice\n");
      continue;
    }

    printf("CHOICE: %d\n", choice);
    switch (choice) {
    case 1:
      //Check if train is already started
      printf("Starting train..\n");
      break;
    case 2:
      printf("Ringing the bell..\n");
      break;
    case 3:
      printf("Accelerating the train..\n");
      break;
    case 4:
      printf("Moving the train..\n");
      break;
    case 5:
      printf("Decelerating the train..\n");
      break;
    case 6:
      //Call function to stop train here
      printf("Stoppping train..\n");
    }
    printf("\n");
  }
}

int getOption() {
  printf("1. Start the train\n");
  printf("2. Ring the bell\n");
  printf("3. Accelerate the train\n");
  printf("4. Move the train\n");
  printf("5. Decelerate the train\n");
  printf("6. Stop the train\n");

  int option;
  printf("Choice: ");
  scanf("%d", &option);
  fflush(stdin);
  if (option > 6) {
    return 0;
  }
  return option;
}
