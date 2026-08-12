#include "vex.h"

#ifndef VARIABLES_H
#define VARIABLES_H

using namespace vex;

using signature = vision::signature;

extern brain Brain;
extern competition Competition;

extern controller Master, Partner;

extern motor FrontLeft, BackLeft, FrontRight, BackRight, Lift1, Lift2, intake, spinneything;
extern motor_group lft, rgt, lift;
extern gyro Gyro1, Gyro2;
extern inertial Inertial1;
extern signature ORANGECUBE, GREENCUBE, PURPLECUBE, SIG_4, SIG_5, SIG_6, SIG_7;
extern vision Vision17;

extern bool BrainPress, screenPressed;

extern int driveFLCurrent, driveFRCurrent, xPos, yPos;
extern int auto_count, auto_select, currentPage, currentMenu;

extern double gyro1_value, gyro2_value, gyro_value;

extern void Autonomous();
extern void driverControl();

extern void lcdDraw(), lcdTouch();
extern void drive(int left, int right, double lit, int inte, int sleep);

/*MAIN CONTROLLER*/
#define joy_RX Master.Axis1.position()
#define joy_RY Master.Axis2.position()
#define joy_LY Master.Axis3.position()
#define joy_LX Master.Axis4.position()

#define master_a Master.ButtonA.pressing()
#define master_b Master.ButtonB.pressing()
#define master_x Master.ButtonX.pressing()
#define master_y Master.ButtonY.pressing()

#define master_r1 Master.ButtonR1.pressing()
#define master_r2 Master.ButtonR2.pressing()
#define master_l1 Master.ButtonL1.pressing()
#define master_l2 Master.ButtonL2.pressing()

#define master_up Master.ButtonUp.pressing()
#define master_down Master.ButtonDown.pressing()
#define master_left Master.ButtonLeft.pressing()
#define master_right Master.ButtonRight.pressing()

/*PARTNER CONTROLLER*/
// #define joy_p_RY Partner.Axis1.position()
// #define joy_p_RX Partner.Axis2.position()
// #define joy_p_LY Partner.Axis3.position()
// #define joy_p_LX Partner.Axis4.position()

#define partner_a Partner.ButtonA.pressing()
#define partner_b Partner.ButtonB.pressing()
#define partner_x Partner.ButtonX.pressing()
#define partner_y Partner.ButtonY.pressing()

#define partner_r1 Partner.ButtonR1.pressing()
#define partner_r2 Partner.ButtonR2.pressing()
#define partner_l1 Partner.ButtonL1.pressing()
#define partner_l2 Partner.ButtonL2.pressing()

#define partner_up Partner.ButtonUp.pressing()
#define partner_down Partner.ButtonDown.pressing()
#define partner_left Partner.ButtonLeft.pressing()
#define partner_right Partner.ButtonRight.pressing()

#endif