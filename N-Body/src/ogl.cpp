#include "ogl.hpp"

Star *galaxy;
int nbStars, nbIterations;
int i = 0;
FILE *f;

void drawGalaxy() {

  float x,y;
  int j, offset = i * nbStars;

  for(j = 0; j < nbStars; j++) {
    x = (galaxy[offset + j].x / (CLIP_PLANE_X/2)) - 1 + OFFSET_X;
    y = (galaxy[offset + j].y / (CLIP_PLANE_Y/2)) - 1 + OFFSET_Y;

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(x,y);
    glVertex2f(x,y + PIXELSIZE);
    glVertex2f(x + PIXELSIZE,y);
    glVertex2f(x,y);
    glEnd();
  }

}

void display();
void callDisplay(int value) { display(); }

void display() {
  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  drawGalaxy();
  i++;
  i%=nbIterations;

  glFlush();
  glutTimerFunc(FRAME_DELAY,callDisplay,0);
}

int openGLMode(int c, char **v) {

  galaxy = loadGalaxy(v[1],&nbStars,&nbIterations);

  f = fopen("debug.txt","w+");

  glutInit(&c,v);                 // Initialize GLUT
  glutInitWindowSize(WIDTH, HEIGHT);   // Set the window's initial width & height
  glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
  glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
  glutDisplayFunc(display); // Register display callback handler for window re-paint
  glutMainLoop();           // Enter the infinitely event-processing loop

  return EXIT_SUCCESS;

}
