#ifndef INC_TYPES
#define INC_TYPES

#include <math.h>

//Parameters
#define WIDTH 1200
#define HEIGHT 900
#define CLIP_PLANE_X 1200
#define CLIP_PLANE_Y CLIP_PLANE_X/(WIDTH/HEIGHT)
#define PIXELSIZE 0.005f
#define OFFSET_X 0.8
#define OFFSET_Y 0.4
#define FRAME_DELAY 20

#define CST_G 6.674 * pow(10,-11) // 6.674 * 10^-11
#define DELTA_T 200

//Error codes
#define WRONG_USAGE -1
#define UNSUPPORTED -2
#define FOPEN_FAIL -3

//Types

typedef struct Star {
  int m;
  float x;
  float y;
  float sx;
  float sy;
} Star;

//Global variables

#endif
