/**************************************************
**
**  @file pinNumbers.h
**  @author Luis David Rodríguez-Centeno
**  @date 08/30/23
**  @version 0.1
**  @copyright Copyright (c) 2023
**
**************************************************/

/*///////////////////////////////////////////////////////////
//  Setting the number for each peristaltic pump conection //
///////////////////////////////////////////////////////////*/

// Reactor 1
#define pump4 19

// Reactor 2
#define pump3 18

// Reactor 3
#define pump2 17

// Reactor 4
#define pump1 16

/* Volume settings */
#define volume1 0
#define volume2 2
#define volume3 2
#define volume4 0
#define flowRate 0.83

/* Timer constants*/
long lastTime = 0;
long minutes = 0;
long hours = 0;
float totalTime = 0;

/* Operational time */

// Reactor 1
float vol1 = volume1 / flowRate;

// Reactor 2
float vol2 = volume2 / flowRate;

// Reactor 3
float vol3 = volume3 / flowRate;

// Reactor 4
float vol4 = volume4 / flowRate;