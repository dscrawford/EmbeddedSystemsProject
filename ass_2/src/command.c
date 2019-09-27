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

// Switch Commands (7-bit address)
bool switchThrowThrough(uint8_t addr)
{
    if(addr > 0x7F) return false; // 7-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x00; // 00000
    return buildCommand(SWITCH_C, addr, command, data);
}

bool switchThrowOut(uint8_t addr)
{
    if(addr > 0x7F) return false; // 7-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x1F; // 11111
    return buildCommand(SWITCH_C, addr, command, data);
}

bool switchSetAddr(uint8_t addr)
{
    if(addr > 0x7F) return false; // 7-bit address
    uint8_t command = 0x1; // 01
    uint8_t data = 0x0B; // 01011
    return buildCommand(SWITCH_C, addr, command, data);
}

bool switchAssignToRouteThrough(uint8_t addr, uint8_t rtaddr)
{
    if(addr > 0x7F) return false; // 7-bit address
    if(rtaddr > 0x1F) return false; // 5-bit data
    uint8_t command = 0x2; // 10
    return buildCommand(SWITCH_C, addr, command, rtaddr);
}

bool switchAssignToRouteOut(uint8_t addr, uint8_t rtaddr)
{
    if(addr > 0x7F) return false; // 7-bit address
    if(rtaddr > 0x1F) return false; // 5-bit data
    uint8_t command = 0x3; // 11
    return buildCommand(SWITCH_C, addr, command, rtaddr);
}

// Route Commands (5-bit address)
bool routeThrow(uint8_t addr)
{
    if(addr > 0x1F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x1F; // 11111
    return buildCommand(ROUTE, addr, command, data);
}

bool routeClear(uint8_t addr)
{
    if(addr > 0x1F) return false; // 5-bit address
    uint8_t command = 0x1; // 01
    uint8_t data = 0x0C; // 01100
    return buildCommand(ROUTE, addr, command, data);
}

// Engine Commands
bool engineFwdDir(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x00; // 00000
    return buildCommand(ENGINE, addr, command, data);
}

bool engineToggleDir(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x01; // 00001
    return buildCommand(ENGINE, addr, command, data);
}

bool engineRevDir(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x03; // 00011
    return buildCommand(ENGINE, addr, command, data);
}

bool engineBoost(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x04; // 00100
    return buildCommand(ENGINE, addr, command, data);
}

bool engineBrake(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x07; // 00111
    return buildCommand(ENGINE, addr, command, data);
}

bool engineOpenFCoupler(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x05; // 00101
    return buildCommand(ENGINE, addr, command, data);
}

bool engineOpenRCoupler(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x06; // 00110
    return buildCommand(ENGINE, addr, command, data);
}

bool engineBlowHorn1(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x1C; // 11100
    return buildCommand(ENGINE, addr, command, data);
}

bool engineRingBell(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x1D; // 11101
    return buildCommand(ENGINE, addr, command, data);
}

bool engineLetoffSound(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x1E; // 11110
    return buildCommand(ENGINE, addr, command, data);
}

bool engineBlowHorn2(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x1F; // 11111
    return buildCommand(ENGINE, addr, command, data);
}

bool engineAux1Off(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x08; // 01000
    return buildCommand(ENGINE, addr, command, data);
}

bool engineAux1Op1(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x09; // 01001
    return buildCommand(ENGINE, addr, command, data);
}

bool engineAux1Op2(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0A; // 01010
    return buildCommand(ENGINE, addr, command, data);
}

bool engineAux1On(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0B; // 01011
    return buildCommand(ENGINE, addr, command, data);
}

bool engineAux2Off(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0C; // 01100
    return buildCommand(ENGINE, addr, command, data);
}

bool engineAux2Op1(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0D; // 01101
    return buildCommand(ENGINE, addr, command, data);
}

bool engineAux2Op2(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0E; // 01110
    return buildCommand(ENGINE, addr, command, data);
}

bool engineAux2On(uint8_t addr)
{
    if(addr > 0x7F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0F; // 01111
    return buildCommand(ENGINE, addr, command, data);
}

bool engineNumeric(uint8_t addr, uint8_t command)
{
    if(addr > 0x7F) return false; // 5-bit address
    if(command > 0x09) return false; // command in [0, 9]; Prevent collision
    uint8_t com = 0x0; // 00
    uint8_t data = 0x10 + command; // 00000
    return buildCommand(ENGINE, addr, com, data);
}


// Engine Extensions
bool engineAssignToTrain(uint8_t addr, uint8_t traddr)
{
}

// Single Unit
bool engineAssignSUFwdDir(uint8_t addr)
{
}

bool engineAssignSURevDir(uint8_t addr)
{
}

// Head-end Unit
bool engineAssignHUFwdDir(uint8_t addr)
{
}

bool engineAssignHURevDir(uint8_t addr)
{
}

// Middle Unit
bool engineAssignMUFwdDir(uint8_t addr)
{
}

bool engineAssignMURevDir(uint8_t addr)
{
}

// Rear Unit
bool engineAssignRUFwdDir(uint8_t addr)
{
}

bool engineAssignRURevDir(uint8_t addr)
{
}

bool engineMomentumLow(uint8_t addr)
{
}

bool engineMomentumMedium(uint8_t addr)
{
}

bool engineMomentumHigh(uint8_t addr)
{
}

bool engineSetAddr(uint8_t addr)
{
}
 // Not sure what this does either

// Engine Speed Commands
bool engineSetAbsSpeed(uint8_t addr, uint8_t speed)
{
}

bool engineSetRelSpeed(uint8_t addr, int8_t relSpeed)
{
    // relSpeed in [-5, 5]
}

// Train Commands
bool trainFwdDir(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x00; // 00000
    return buildCommand(TRAIN, addr, command, data);
}

bool trainToggleDir(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x01; // 00001
    return buildCommand(TRAIN, addr, command, data);
}

bool trainRevDir(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x03; // 00011
    return buildCommand(TRAIN, addr, command, data);
}

bool trainBoost(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x04; // 00100
    return buildCommand(TRAIN, addr, command, data);
}

bool trainBrake(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x07; // 00111
    return buildCommand(TRAIN, addr, command, data);
}

bool trainOpenFCoupler(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x05; // 00101
    return buildCommand(TRAIN, addr, command, data);
}

bool trainOpenRCoupler(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x06; // 00110
    return buildCommand(TRAIN, addr, command, data);
}

bool trainBlowHorn1(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x1C; // 11100
    return buildCommand(TRAIN, addr, command, data);
}

bool trainRingBell(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x1D; // 11101
    return buildCommand(TRAIN, addr, command, data);
}

bool trainLetoffSound(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x1E; // 11110
    return buildCommand(TRAIN, addr, command, data);
}

bool trainBlowHorn2(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x1F; // 11111
    return buildCommand(TRAIN, addr, command, data);
}

bool trainAux1Off(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x08; // 01000
    return buildCommand(TRAIN, addr, command, data);
}

bool trainAux1Op1(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x09; // 01001
    return buildCommand(TRAIN, addr, command, data);
}

bool trainAux1Op2(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0A; // 01010
    return buildCommand(TRAIN, addr, command, data);
}

bool trainAux1On(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0B; // 01011
    return buildCommand(TRAIN, addr, command, data);
}

bool trainAux2Off(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0C; // 01100
    return buildCommand(TRAIN, addr, command, data);
}

bool trainAux2Op1(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0D; // 01101
    return buildCommand(TRAIN, addr, command, data);
}

bool trainAux2Op2(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0E; // 01110
    return buildCommand(TRAIN, addr, command, data);
}

bool trainAux2On(uint8_t addr)
{
    if(addr > 0x0F) return false; // 5-bit address
    uint8_t command = 0x0; // 00
    uint8_t data = 0x0F; // 01111
    return buildCommand(TRAIN, addr, command, data);
}

bool trainNumeric(uint8_t addr, uint8_t command)
{
    if(addr > 0x0F) return false; // 5-bit address
    if(command > 0x09) return false; // command in [0, 9]; Prevent collision
    uint8_t com = 0x0; // 00
    uint8_t data = 0x10 + command; // 00000
    return buildCommand(TRAIN, addr, com, data);
}


// Train Extensions
bool trainMomentumLow(uint8_t addr)
{
}

bool trainMomentumMedium(uint8_t addr)
{
}

bool trainMomentumHigh(uint8_t addr)
{
}

// Not sure what this does either
bool trainSetAddr(uint8_t addr)
{
}

// probably removes all engines from this train
bool trainClearLashup(uint8_t addr)
{
}

// Train Speed Commands
bool trainSetAbsSpeed(uint8_t addr, uint8_t speed)
{
}

bool trainSetRelSpeed(uint8_t addr, int8_t relSpeed)
{
}
 // relSpeed in [-5, 5]

// Accessory Commands
bool accAux1Off(uint8_t addr)
{
}

bool accAux1Op1(uint8_t addr)
{
}

bool accAux1Op2(uint8_t addr)
{
}

bool accAux1On(uint8_t addr)
{
}

bool accAux2Off(uint8_t addr)
{
}

bool accAux2Op1(uint8_t addr)
{
}

bool accAux2Op2(uint8_t addr)
{
}

bool accAux2On(uint8_t addr)
{
}

bool accNumeric(uint8_t addr, uint8_t command)
{
}


// Accessory Extensions
bool accAllOff(uint8_t addr)
{
}

bool accAllOn(uint8_t addr)
{
}

bool accSetAddr(uint8_t addr)
{
}

bool accAssignAux1ToGroup(uint8_t addr, uint8_t graddr)
{
}

bool accAssignAux2ToGroup(uint8_t addr, uint8_t graddr)
{
}


// Group Commands
bool groupOff(uint8_t addr)
{
}

bool groupOp1(uint8_t addr)
{
}

bool groupOp2(uint8_t addr)
{
}

bool groupOn(uint8_t addr)
{
}

bool groupClear(uint8_t addr)
{
}


// System Commands
bool sysHalt(void)
{
}

bool sysNop(void)
{
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
