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

// Switch Commands
bool throwSwitchThrough(uint8_t addr)
{
    if(addr > 0x7F) return false; // 7-bit address
    uint8_t command = 0; // 00
    uint8_t data = 0x00; // 00000
    return buildCommand(SWITCH_C, addr, command, data);
}

bool throwSwitchOut(uint8_t addr)
{
    if(addr > 0x7F) return false; // 7-bit address
    uint8_t command = 0; // 00
    uint8_t data = 0x1F; // 11111
    return buildCommand(SWITCH_C, addr, command, data);
}

bool setSwitchAddr(uint8_t addr)
{
    if(addr > 0x7F) return false; // 7-bit address
    uint8_t command = 1; // 01
    uint8_t data = 0x0B; // 01011
    return buildCommand(SWITCH_C, addr, command, data);
}

bool assignSwitchToRouteThrough(uint8_t addr, uint8_t rtaddr)
{
    if(addr > 0x7F) return false; // 7-bit address
    if(rtaddr > 0x1F) return false; // 5-bit data
    uint8_t command = 2; // 10
    return buildCommand(SWITCH_C, addr, command, rtaddr);
}

bool assignSwitchToRouteOut(uint8_t addr, uint8_t rtaddr)
{
    if(addr > 0x7F) return false; // 7-bit address
    if(rtaddr > 0x1F) return false; // 5-bit data
    uint8_t command = 3; // 11
    return buildCommand(SWITCH_C, addr, command, rtaddr);
}

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
