#include "variables.h"

using namespace vex;

using signature = vision::signature;

brain Brain;
competition Competition;

controller Master  = controller(primary);
controller Partner = controller(partner);

motor FrontLeft    = motor(PORT8, ratio18_1, true); // Strength motor; not reversed; left drive
motor BackLeft     = motor(PORT1, ratio18_1, true); // Strength motor; not reversed; left drive
motor_group lft    = motor_group(FrontLeft, BackLeft);
motor FrontRight   = motor(PORT19, ratio18_1, false); // Strength motor; reversed; right drive
motor BackRight    = motor(PORT11, ratio18_1, false); // Strength motor; reversed; right drive
motor_group rgt    = motor_group(FrontRight, BackRight);
motor Lift1        = motor(PORT17, ratio36_1, false); // High-strength motor; not reversed; left lift
motor Lift2        = motor(PORT9, ratio36_1, true);   // High-strength motor; reversed; right lift
motor_group lift   = motor_group(Lift1, Lift2);
motor intake       = motor(PORT10, ratio18_1, false); // Strength motor; not reversed; intake
motor spinneything = motor(PORT7, ratio18_1, true); // Strength motor; reversed; spinny thing
gyro Gyro1         = gyro(Brain.ThreeWirePort.A); // Floppy gyro
gyro Gyro2         = gyro(Brain.ThreeWirePort.B); // Stable gyro
inertial Inertial1 = inertial(PORT20);

signature ORANGECUBE = signature (1, 7591, 9295, 8443, -4291, -2917, -3604, 3.1, 0);
signature GREENCUBE  = signature (2, -7661, -5887, -6774, -4959, -2979, -3969, 3.2, 0);
signature PURPLECUBE = signature (3, -423, 835, 206, 9279, 12541, 10910, 2.8, 0);
signature SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0 );
signature SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0 );
signature SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0 );
signature SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0 );
vision Vision17 = vision (PORT17, 50, ORANGECUBE, GREENCUBE, PURPLECUBE, SIG_4, SIG_5, SIG_6, SIG_7);

int driveFLCurrent = FrontLeft.position(deg), driveFRCurrent = FrontRight.position(deg);

bool screenPressed = false;
bool BrainPress = Brain.Screen.pressing();
int xPos = Brain.Screen.xPosition();
int yPos = Brain.Screen.yPosition();

int auto_count  = 0, auto_select = 0;
int currentPage = 0, currentMenu = 0;

double inertia_accel = Inertial1.acceleration(axisType::yaxis);
double inertia_gyro = Inertial1.heading();
double gyro1_value = Gyro1.heading();
double gyro2_value = Gyro2.heading();
double gyro_value  = (gyro1_value + gyro2_value + inertia_gyro) / 3; // Creates more accurate gyro value for auton.