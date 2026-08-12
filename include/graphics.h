#include "vex.h"
#include "variables.h"

using namespace vex;

using color = vex::color;

typedef struct {
  int id;
  int parentPageNumber;
  int buttonOnePageNumber;
  int buttonTwoPageNumber;
  int buttonThreePageNumber;
  int buttonFourPageNumber;
  int pageType;
  color pageColor;
  const char *name;
  const char *description;
} Page;

// Page pages[] = {
// //       ID PP B1 B2 B3 B4  TYPE    COLOR   NAME          DESC.
// /* 0 */ { 0, 0, 1, 2, 3, 4, folder, NULL,   ""                                                   },
// /* 1 */ { 1, 0, 0, 0, 0, 0, auton,  red,    "Red",       "Scores 3 points."                      },
// /* 2 */ { 2, 0, 0, 0, 0, 0, auton,  blue,   "Blue",      "Scores 3 points"                       },
// /* 3 */ { 3, 0, 0, 0, 0, 0, auton,  yellow, "Skills",    "4 points."                             },
// /* 4 */ { 4, 0, 5, 6, 0, 0, folder, green,  "Other"                                              },
// /* 5 */ { 5, 4, 0, 0, 0, 0, auton,  green,  "Testing",   "Strictly for testing auton stuff."     },
// /* 6 */ { 6, 4, 6, 7, 0, 0, folder, green,  "Sensors"                                            },
// /* 7 */ { 7, 0, 0, 0, 0, 0, auton,  green,  "Floppy Gyro", "Words and stuff."                    },
// /* 8 */ { 8, 0, 0, 0, 0, 0, auton,  green,  "Stable Gyro", "Different words and stuff."          }
// };

Page pages[] = {
//       ID PP B1 B2 B3 B4  TYPE     COLOR   NAME                 DESC.
/* 0 */ { 0, 0, 1, 2, 3, 4, folder,  NULL,   ""                                                              },
/* 1 */ { 1, 0, 2, 3, 0, 0, folder,  red,    "Red"                                                           }, // !!
/* 2 */ { 2, 1, 0, 0, 0, 0, auton,   red,    "Protected Zone",   "Scores 3 points in red protected zone."    },
/* 3 */ { 3, 1, 0, 0, 0, 0, auton,   red,    "UnProtected Zone", "Scores 3 points in red unprotected zone."  },
/* 4 */ { 4, 0, 5, 6, 0, 0, folder,  blue,   "Blue"                                                          }, // !!
/* 5 */ { 5, 4, 0, 0, 0, 0, auton,   blue,   "Protected Zone",   "Scores 3 points in blue protected zone."   },
/* 6 */ { 6, 4, 0, 0, 0, 0, auton,   blue,   "UnProtected Zone", "Scores 3 points in blue unprotected zone." },
/* 7 */ { 7, 0, 0, 0, 0, 0, auton,   yellow, "Skills",           "4 points."                                 }, // !!
/* 8 */ { 8, 0, 9, 0, 0, 0, folder,  green,  "Other"                                                         },
/* 9 */ { 9, 8, 0, 0, 0, 0, auton,   green,  "Testing",          "Strictly for testing auton stuff."         }
};