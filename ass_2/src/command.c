#include "command.h"

// Switch Commands
bool throwSwitchThrough(uint8_t addr)
{
    if(addr > 0x7F) return false; // 7-bit address
    uint8_t command = 0; // 00
    uint8_t data = 0x00; // 00000
    return buildCommand(SWITCH, addr, command, data);
}

bool throwSwitchOut(uint8_t addr)
{
    if(addr > 0x7F) return false; // 7-bit address
    uint8_t command = 0; // 00
    uint8_t data = 0x1F; // 11111
    return buildCommand(SWITCH, addr, command, data);
}

bool setSwitchAddr(uint8_t addr)
{
    if(addr > 0x7F) return false; // 7-bit address
    uint8_t command = 1; // 01
    uint8_t data = 0x0B; // 01011
    return buildCommand(SWITCH, addr, command, data);
}

bool assignSwitchToRouteThrough(uint8_t addr, uint8_t rtaddr)
{
    if(addr > 0x7F) return false; // 7-bit address
    if(rtaddr > 0x1F) return false; // 5-bit data
    uint8_t command = 2; // 10
    return buildCommand(SWITCH, addr, command, rtaddr);
}

bool assignSwitchToRouteOut(uint8_t addr, uint8_t rtaddr)
{
    if(addr > 0x7F) return false; // 7-bit address
    if(rtaddr > 0x1F) return false; // 5-bit data
    uint8_t command = 3; // 11
    return buildCommand(SWITCH, addr, command, rtaddr);
}
