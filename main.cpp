#include "variables.h"

using namespace vex;

void competition_initialize() {
  lcdDraw();
  Brain.Screen.render();
  while (1) {
    lcdTouch();
  }
}

void initialize() {
  lft.resetRotation();
  rgt.resetRotation();
  lift.resetRotation();
  intake.resetRotation();
  Gyro1.calibrate();
  Gyro2.calibrate();
  Inertial1.calibrate();

  competition_initialize();
}

void Autonomous() {
  if (auto_select == 2 || auto_select == 6) {        // RED  | Un-Blue
    lft.spin(fwd, -200, rpm);
    rgt.spin(fwd, -200, rpm);
    lift.rotateFor(75, deg);
    task::sleep(500);
    intake.spin(fwd, 150, rpm);
    lift.rotateFor(-60, deg);
    lft.spin(fwd, 0, rpm);
    rgt.spin(fwd, 0, rpm);  
    task::sleep(1000);
    lift.rotateFor(80, deg);
    lft.spin(fwd, 50, rpm);
    rgt.spin(fwd,-50, rpm);
    task::sleep(2000);
    intake.spin(fwd, 0, rpm);
    lft.spin(fwd, 0, rpm);
    rgt.spin(fwd, 0, rpm);  
    task::sleep(10);
    lift.rotateFor(-10, deg); 
    lft.spin(fwd, 0, rpm);
    rgt.spin(fwd, 0, rpm);
    task::sleep(700);
    lft.spin(fwd, -125, rpm);
    rgt.spin(fwd, -125, rpm); // Drive to cube
    task::sleep(700);
    lift.rotateFor(-25,deg);
    intake.spin(fwd, 80, rpm);
    task::sleep(500);
    lft.spin(fwd, -25, rpm);
    rgt.spin(fwd, -25, rpm);
    task::sleep(800); 
    lft.spin(fwd,-125, rpm);
    rgt.spin(fwd,-125, rpm);
    intake.spin(fwd, 0, rpm); // Move forward towards goal
    task::sleep(700);
    lft.spin(fwd, 0, rpm);
    rgt.spin(fwd, 0, rpm); 
    task::sleep(100);  
    intake.spin(fwd,-40,rpm);
    task::sleep(600);
    intake.spin(fwd, -40, rpm);
    lift.rotateFor(240, deg, 10, rpm);
    task::sleep (400);
    intake.spin(fwd,0, rpm);
    task::sleep(100);
    lft.spin(fwd, 200, rpm);
    rgt.spin(fwd, 200, rpm);  
    task::sleep(1000);
    lft.spin(fwd, 0, rpm);
    rgt.spin(fwd, 0, rpm);
  } else if (auto_select == 3 || auto_select == 5) { // BLUE | Un-Red
    lft.spin(fwd, -200, rpm);
    rgt.spin(fwd, -200, rpm);
    lift.rotateFor(75, deg);
    task::sleep(500);
    intake.spin(fwd, 150, rpm);
    lift.rotateFor(-60, deg);
    lft.spin(fwd, 0, rpm);
    rgt.spin(fwd, 0, rpm);  
    task::sleep(1000);
    lift.rotateFor(80, deg);
    lft.spin(fwd,-50, rpm);
    rgt.spin(fwd, 50, rpm);
    task::sleep(2000);
    intake.spin(fwd, 0, rpm);
    lft.spin(fwd, 0, rpm);
    rgt.spin(fwd, 0, rpm);  
    task::sleep(10);
    lift.rotateFor(-10, deg); 
    lft.spin(fwd, 0, rpm);
    rgt.spin(fwd, 0, rpm);
    task::sleep(700);
    lft.spin(fwd, -125, rpm);
    rgt.spin(fwd, -125, rpm); // Drive to cube
    task::sleep(700);
    lift.rotateFor(-25,deg);
    intake.spin(fwd, 80, rpm);
    task::sleep(500);
    lft.spin(fwd, -25, rpm);
    rgt.spin(fwd, -25, rpm);
    task::sleep(800); 
    lft.spin(fwd,-125, rpm);
    rgt.spin(fwd,-125, rpm);
    intake.spin(fwd, 0, rpm); // Move forward towards goal
    task::sleep(700);
    lft.spin(fwd, 0, rpm);
    rgt.spin(fwd, 0, rpm); 
    task::sleep(100);  
    intake.spin(fwd,-40,rpm);
    task::sleep(600);
    intake.spin(fwd, -40, rpm);
    lift.rotateFor(240, deg, 10, rpm);
    task::sleep (400);
    intake.spin(fwd,0, rpm);
    task::sleep(100);
    lft.spin(fwd, 200, rpm);
    rgt.spin(fwd, 200, rpm);  
    task::sleep(1000);
    lft.spin(fwd, 0, rpm);
    rgt.spin(fwd, 0, rpm);
  } else if (auto_select == 7) {                     // SKILLS
    task::sleep     (200);
    lft.spin        (fwd, -20, rpm);
    rgt.spin        (fwd, -20, rpm);  
    lift.rotateFor  (80, deg);
    intake.spin     (fwd, 50, rpm);
    task::sleep     (500);
    lift.rotateFor  (-30, deg);
    intake.spin     (fwd, 80, rpm);
    lft.spin        (fwd, -60, rpm);
    rgt.spin        (fwd,-150, rpm);
    task::sleep     (1000);
    lift.rotateFor  (-10, deg, 80, rpm);
    intake.spin     (fwd, 100, rpm);
    lft.spin        (fwd, 0, rpm);
    rgt.spin        (fwd, 0, rpm);
    task::sleep     (700);
    lift.rotateFor  (45, deg); 
    task::sleep     (500);
    intake.spin     (fwd, 100, rpm);
    rgt.spin        (fwd,-170, rpm);
    lft.spin        (fwd, -30, rpm);
    task::sleep     (1200);
    intake.spin     (fwd, 80, rpm);
    lft.spin        (fwd, 0, rpm);
    rgt.spin        (fwd, 0, rpm);
    task::sleep     (500);
    intake.spin     (fwd, 80, rpm);
    lft.spin        (fwd,-110, rpm);
    rgt.spin        (fwd,-100, rpm);
    task::sleep     (200);
    lift.rotateFor  (-10, deg);
    intake.spin     (fwd, 80, rpm);
    lft.spin        (fwd,-110, rpm);
    rgt.spin        (fwd,-100, rpm);
    task::sleep     (900);
    intake.spin     (fwd, 0, rpm);
    lft.spin        (fwd,-20, rpm);
    rgt.spin        (fwd,-20, rpm);
    task::sleep     (500);
    lft.spin        (fwd, 0, rpm);
    rgt.spin        (fwd, 0, rpm);
    intake.spin     (fwd,-40,rpm);
    task::sleep     (600);
    intake.spin     (fwd, -40, rpm);
    lift.rotateFor  (240, deg, 10, rpm);
    task::sleep     (400);
    intake.spin     (fwd,0, rpm);
    task::sleep     (100);
    lft.spin        (fwd, 200, rpm);
    rgt.spin        (fwd, 200, rpm);  
    task::sleep     (600);
    intake.spin     (fwd, 100, rpm);
    lft.spin        (fwd, 0, rpm);
    rgt.spin        (fwd, 0, rpm);
    task::sleep     (100);
    lift.rotateFor  (50, deg, 20, rpm);
    intake.spin     (fwd, 0, rpm);
    task::sleep     (100);
    rgt.spin        (fwd, 50, rpm);
    lft.spin        (fwd,-50, rpm);
    task::sleep     (3200);
    rgt.spin        (fwd, -50, rpm);
    lft.spin        (fwd, -50, rpm);
    intake.spin     (fwd, 80, rpm);
    task::sleep     (1000);   
    rgt.spin        (fwd, 0, rpm);
    lft.spin        (fwd, 0, rpm); 
    lift.rotateFor  (-240, deg, 20, rpm);
  } else if (auto_select == 9) {                     // TESTING
    //     LFT   RGT   LIF  ITK  SLEP
    // drive( -20,  -20,  80,  50,  500); // 1 
    // drive( -60, -150, -30, 100, 1100); // 2
    // drive(   0,    0,   0, 100,  700); // 3
    // drive(   0,    0, -20,   0,  500); // 4
    // drive( -30, -170,   0,  80, 1400); // 5
    // drive(   0,    0,   0,  80,  500); // 6
    // drive(-110, -100,   0, 100,  200); // 7
    // drive(-110, -110, -10, 100,  900); // 8
    // drive( -20,  -20,   0,   0, 1400); // 9
    // drive(   0,    0,   0, -40,  400); // 10
    // drive(   0,    0, 240, -40,  400); // 11**
    // drive(   0,    0,   0,   0,  100); // 12
    // drive(  200,  200,  0,   0,  500); // 13
    // drive(    0,    0,  0,   0,  100); // 14
    // drive(  -50,   50,  0,   0, 3000); // 15
    // drive(    0,    0,  0,   0,    0); // 16 
    lft.spin        (fwd, -100, rpm);
    rgt.spin        (fwd, -100, rpm);
    lift.rotateFor  (270, deg);
    task::sleep     (310);
    intake.spin     (fwd,-50, rpm);
    rgt.spin        (fwd,  0, rpm);
    lft.spin        (fwd,  0, rpm);
    lift.rotateFor  (50, deg);
    task::sleep     (1000);
    rgt.spin        (fwd, 50, rpm);
    lft.spin        (fwd, 50, rpm);
    task::sleep     (500);
    rgt.spin        (fwd,-50, rpm);
    lft.spin        (fwd, 50, rpm);
    task::sleep     (1500);
    rgt.spin        (fwd, -40, rpm);
    lft.spin        (fwd, -50, rpm);
    intake.spin     (fwd, 80, rpm);
    task::sleep     (1000);  
    rgt.spin        (fwd, -130, rpm);
    lft.spin        (fwd, -80, rpm);
    intake.spin     (fwd, 200, rpm);
    task::sleep     (1900); 
    rgt.spin        (fwd, 0, rpm);
    lft.spin        (fwd, 0, rpm); 
    lift.rotateFor  (-300, deg, 20, rpm);
    task::sleep(1000);
    rgt.spin        (fwd, -50, rpm);
    lft.spin        (fwd,  50, rpm);
    task::sleep     (1800);
    rgt.spin        (fwd, 0, rpm);
    lft.spin        (fwd, 0, rpm);
    lift.rotateFor  (80, deg);
    rgt.spin        (fwd, -100, rpm);
    lft.spin        (fwd, -100, rpm);
    task::sleep     (2700);
    rgt.spin        (fwd, -10, rpm);
    lft.spin        (fwd, -10, rpm);
    task::sleep     (1000);
    rgt.spin        (fwd, 0, rpm);
    lft.spin        (fwd, 0, rpm);  
    intake.spin     (fwd,-40,rpm);
    task::sleep     (600);
    intake.spin     (fwd, -40, rpm);
    lift.rotateFor  (240, deg, 10, rpm);
    task::sleep     (400);
    intake.spin     (fwd,0, rpm);

  }
}

void driverControl() {
  Gyro1.resetAngle();
  Gyro2.resetAngle();
  Inertial1.resetHeading();
  lft.setStopping(brake);
  rgt.setStopping(brake);
  while (true) {
    double driveSpeedMultiplier  = 0;
    double liftSpeedMultiplier   = 0;
    double intakeSpeedMultiplier = 0;

    if (master_r1) {        // Fast Button
      driveSpeedMultiplier = 2.5;
    } else if (master_r2) { // Slow Button
      driveSpeedMultiplier = 1;
    } else {
      driveSpeedMultiplier = 1.5;
    }
    lft.spin(directionType::undefined, ((joy_LX + joy_RY) * driveSpeedMultiplier), rpm);
    rgt.spin(directionType::undefined, ((joy_RY - joy_LX) * driveSpeedMultiplier), rpm);

    // Kane's Secret Speed Controls
    if (master_l1){        // Slow lift
      liftSpeedMultiplier = 0.5;
    } else if (master_l2){ // Slow intake
      intakeSpeedMultiplier = 0.5;
    } else {
      liftSpeedMultiplier = 1;
      intakeSpeedMultiplier = 1;
    }

    if (partner_r1) {        // Up
      lift.spin(forward, (60 * liftSpeedMultiplier), rpm);
    } else if (partner_b) {  // Slower up
      lift.spin(forward, 30, rpm);
    } else if (partner_r2) { // Down
      lift.spin(reverse, (50 * liftSpeedMultiplier), rpm);
    } else if (partner_x) {  // Slower down
      lift.spin(reverse, 25, rpm);
    } else {
      lift.stop(brakeType::hold);
    }

    if (partner_l1) {        // Intake
      intake.spin(forward, (145 * intakeSpeedMultiplier), rpm);
    } else if (partner_l2) { // Outake 
      intake.spin(reverse, (100 * intakeSpeedMultiplier), rpm);
    } else {
	    intake.stop();
    }

    if (partner_up) {          // Up Spinney Thing
      spinneything.spin(forward, 200, rpm);
    } else if (partner_down) { // Down Boy, Down!
      spinneything.spin(reverse, 200, rpm);
    } else {
      spinneything.stop(brakeType::coast);
    }
  }
  task::sleep(20);
}

int main() {
  Competition.autonomous(Autonomous);
  Competition.drivercontrol(driverControl);
  initialize();

  while (true){
    task::sleep(20);
  }
}