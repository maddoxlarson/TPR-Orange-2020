#include "graphics.h"

void menuIcons(int iconX, int iconY, int iconType, color iconColor) { // Draws icons...
  Brain.Screen.setPenColor(iconOutlineColor);
  Brain.Screen.setPenWidth(0);
  if (iconType == folder) {       // File
    Brain.Screen.drawRectangle(4+iconX, 4+iconY, 32, 12, iconColor);
    Brain.Screen.setPenWidth(4);
    Brain.Screen.drawLine(0+iconX, 2+iconY, 18+iconX, 2+iconY);
    Brain.Screen.drawLine(17+iconX, 2+iconY, 21+iconX, 6+iconY);
    Brain.Screen.drawLine(19+iconX, 6+iconY, 39+iconX, 6+iconY);
    Brain.Screen.drawLine(38+iconX, 4+iconY, 38+iconX, 39+iconY);
    Brain.Screen.drawLine(0+iconX, 38+iconY, 39+iconX, 38+iconY);
    Brain.Screen.drawLine(2+iconX, 39+iconY, 2+iconX, 0+iconY);
    Brain.Screen.drawLine(0+iconX, 18+iconY, 17+iconX, 18+iconY);
    Brain.Screen.drawLine(16+iconX, 18+iconY, 20+iconX, 14+iconY);
    Brain.Screen.drawLine(19+iconX, 14+iconY, 39+iconX, 14+iconY);
  } else if (iconType == auton) { // Folder
    Brain.Screen.drawRectangle(7+iconX, 4+iconY, 15, 32, iconColor);
    Brain.Screen.drawRectangle(22+iconX, 15+iconY, 11, 21, iconColor);
    Brain.Screen.setPenWidth(4);
    Brain.Screen.drawLine(3+iconX, 2+iconY, 26+iconX, 2+iconY);
    Brain.Screen.drawLine(5+iconX, 0+iconY, 5+iconX, 39+iconY);
    Brain.Screen.drawLine(3+iconX, 38+iconY, 36+iconX, 38+iconY);
    Brain.Screen.drawLine(35+iconX, 10+iconY, 35+iconX, 39+iconY);
    Brain.Screen.drawLine(24+iconX, 1+iconY, 34+iconX, 11+iconY);
    Brain.Screen.drawLine(24+iconX, 2+iconY, 24+iconX, 14+iconY);
    Brain.Screen.drawLine(22+iconX, 13+iconY, 36+iconX, 13+iconY);
    Brain.Screen.drawLine(10+iconX, 11+iconY, 19+iconX, 11+iconY);
    Brain.Screen.drawLine(10+iconX, 20+iconY, 30+iconX, 20+iconY);
    Brain.Screen.drawLine(10+iconX, 29+iconY, 30+iconX, 29+iconY);
  } 
}

void menuNavBar(int pathPosition, bool iconClose) { // Draws buttons for and writes text for the navigation bars
  std::string pathText = "";
  if (pathPosition == 0) pathText = "/";
  else {
    while (pathPosition != 0) {
      pathText = "/" + std::string(pages[pathPosition].name) + pathText;
      pathPosition = pages[pathPosition].parentPageNumber;
    }
  }
  Brain.Screen.setPenWidth(0); // Remove outline
  Brain.Screen.drawRectangle(0, 0, 50, 32, buttonColor);   // Draw up button
  Brain.Screen.drawRectangle(430, 0, 50, 32, buttonColor); // Draw home button
  Brain.Screen.drawRectangle(60, 0, 360, 32, pathColor);   // Draw path button
  Brain.Screen.setPenColor(fontColor); // Set text color
  Brain.Screen.setFont(prop20);
  Brain.Screen.printAt(68, 22, false, pathText.c_str()); // Print path button text
  // if (iconClose) Brain.Screen.drawImageFromFile("iconClose.png", 9, 0);
  // else           Brain.Screen.drawImageFromFile("iconUp.png", 9, 0);
  // Brain.Screen.drawImageFromFile("iconHome.png", 439, 0);
}

void menuButton(int buttonNumber, int buttonPageNumber) { // Draws necessary buttons for the page...
 if (buttonPageNumber != 0) {
    Brain.Screen.setPenWidth(0); // Remove outline
    Brain.Screen.drawRectangle(60, 42+50*(buttonNumber-1), 411, 40, buttonColor); // Draw button
    
    menuIcons(10, 42+50*(buttonNumber-1), pages[buttonPageNumber].pageType, pages[buttonPageNumber].pageColor);

    Brain.Screen.setPenColor(fontColor); // Set text color
    Brain.Screen.setFont(prop30);
    Brain.Screen.printAt(68, 72 + 50 * (buttonNumber - 1), false, pages[buttonPageNumber].name);
  }
}

void menuFolder() { // Setup page if it's a folder...
  Brain.Screen.setPenWidth(0); // Remove outline
  Brain.Screen.drawRectangle(0, 0, 480, 240, backgroundColor); // Draw background
  menuNavBar(currentPage, false);
  menuButton(1, pages[currentPage].buttonOnePageNumber);   // Print button one
  menuButton(2, pages[currentPage].buttonTwoPageNumber);   // Print button two
  menuButton(3, pages[currentPage].buttonThreePageNumber); // Print button three
  menuButton(4, pages[currentPage].buttonFourPageNumber);  // Print button four
}

void menuAuton() { // Setup page if it's an autonomous routine...
  auto_select = pages[currentPage].id;
  menuButton(1, currentPage);
  Brain.Screen.setPenWidth(0); // Remove outline
  Brain.Screen.drawRectangle(10, 92, 460, 140, buttonColor);
  Brain.Screen.setFont(prop20);
  Brain.Screen.printAt(20, 115, false, pages[currentPage].description);
  menuNavBar(pages[currentPage].parentPageNumber, true);
}

void lcdDraw() { // Draw the current page...
  if      (pages[currentPage].pageType == auton)  menuAuton();
  else if (pages[currentPage].pageType == folder) menuFolder();
}

void lcdTouch() {
  if (Brain.Screen.pressing() && !screenPressed) {
    screenPressed = true;

    if (Brain.Screen.xPosition() < 47 && Brain.Screen.yPosition() < 32) {
      currentPage = pages[currentPage].parentPageNumber; // Up
    } else if (Brain.Screen.xPosition() > 433 && Brain.Screen.yPosition() < 32) {
      currentPage = 0; // Home
    }
    if (pages[currentPage].pageType == folder) {
      if (pages[currentPage].buttonOnePageNumber != 0 && Brain.Screen.yPosition() >  42 && Brain.Screen.yPosition() <  82) {
        currentPage = pages[currentPage].buttonOnePageNumber; // Button one
      } else if (pages[currentPage].buttonTwoPageNumber   != 0 && Brain.Screen.yPosition() >  92 && Brain.Screen.yPosition() < 132) {
        currentPage = pages[currentPage].buttonTwoPageNumber; // Button two
      } else if (pages[currentPage].buttonThreePageNumber != 0 && Brain.Screen.yPosition() > 142 && Brain.Screen.yPosition() < 182) {
        currentPage = pages[currentPage].buttonThreePageNumber; // Button three
      } else if (pages[currentPage].buttonFourPageNumber  != 0 && Brain.Screen.yPosition() > 192 && Brain.Screen.yPosition() < 232) {
        currentPage = pages[currentPage].buttonFourPageNumber; // Button four
      }
    }
    lcdDraw();
    Brain.Screen.render();
  } else if (!Brain.Screen.pressing() && screenPressed) {
    screenPressed = false;
  }
}