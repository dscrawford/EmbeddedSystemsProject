#include "command.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum {
    SWITCH_C,
    ROUTE,
    ENGINE,
    TRAIN,
    ACCESSORY,
    GROUP
} TARGET_TYPE;

bool buildCommand(TARGET_TYPE target, uint_fast8_t address, uint_fast8_t command, uint_fast8_t data);

//TRAIN API GOES HERE

bool buildCommand(TARGET_TYPE target, uint_fast8_t address, uint_fast8_t command, uint_fast8_t data) {
    uint8_t *toTrain = calloc(1, 3);
    toTrain[0] = 0xFE;

    switch (target) {
        case SWITCH_C : {
            toTrain[1] = (0b01 << 6) + ((address & 0x3F) >> 1);
        }
        case ROUTE : {
            toTrain[1] = (0b1101 << 4) + ((address & 0x0F) >> 1);
        }
        case ENGINE: {
            toTrain[1] = (0b00 << 6) + ((address & 0x3F) >> 1);
        }
        case TRAIN: {
            toTrain[1] = (0b11001 << 3) + ((address & 0x07) >> 1);
        }
        case ACCESSORY: {
            toTrain[1] = (0b10 << 6) + ((address & 0x3F) >> 1);
        }
        case GROUP: {
            toTrain[1] = (0b1100 << 4) + ((address & 0x0F) >> 1);
        }
    }

    toTrain[2] = ((address & 1) << 7) + ((command) & 0x3 << 5) + (data & 0x1F);

    printf("sending: 0x%02X%02X%02X", toTrain[0], toTrain[1], toTrain[2]);

    //TODO Oskari's serial write

    return false; //TODO CHANGE
}