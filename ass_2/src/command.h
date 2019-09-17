#ifndef COMMAND_H_20190917_111805
#define COMMAND_H_20190917_111805

#include <stdint.h>

typedef uint_fast8_t bool;
#define true 1
#define false 0

// Switch Commands
bool throwSwitchThrough(uint8_t addr);
bool throwSwitchOut(uint8_t addr);
bool setSwitchAddr(uint8_t addr); // I'm not sure what this command accomplishes
bool assignSwitchToRouteThrough(uint8_t addr, uint8_t rtaddr);
bool assignSwitchToRouteOut(uint8_t addr, uint8_t rtaddr);

#endif /* COMMAND_H_20190917_111805 */
