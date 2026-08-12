#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

using color = vex::color;

/*COLORS*/
#define green color(0x00ff00)
#define red color(0xFF0000)
#define blue color(0x0000FF)
#define yellow color(0xFFFF00)
#define fontColor color(white)
#define iconOutlineColor color(white)
#define backgroundColor color(0x666666)
#define buttonColor color(0x191919)
#define pathColor color(0x2F3136)

/*GRAPHICAL*/
#define folder 0
#define auton 1
#define NULL __null

/*AUTONOMOUS*/
#define TIME 0
#define ENCO 1

#define LEFT 1
#define RIGHT 2

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)