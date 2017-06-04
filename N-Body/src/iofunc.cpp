#include "iofunc.hpp"

float parseFloat(FILE *f, int *invalid) {
  int i = 0;
  char c, str[20] = {'\0'};

  while((c = fgetc(f)) != EOF)
    switch(c) {
      case '-':
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '.':
        str[i++] = c;
        break;
      case ' ':
      case '\n':
      case 13: //CR
        if(i == 0) { *invalid = 1; return 0; }
        *invalid = 0;
        return atof(str);
      default:
        printf("Unsupported character : %c(%d)",c,c);
        exit(UNSUPPORTED);

    }

  *invalid = 1;
  return 0;

}

Star *loadGalaxy(char *file, int *nbStars, int* nbIterations) {

  FILE *f = fopen(file,"r");
  if(f == NULL) { printf("Failed to open input file.\n"); exit(FOPEN_FAIL); }

  int flag;
  *nbStars = (int)parseFloat(f, &flag);
  if(nbIterations != NULL)
    *nbIterations = parseFloat(f,&flag);

  Star *galaxy = (Star*)malloc(*nbStars * sizeof(Star) * (nbIterations == NULL ? 1 : *nbIterations));

  float tmp;
  int i;
  for(i = 0; i < *nbStars * (nbIterations == NULL ? 1 : *nbIterations); i++) {
    tmp = parseFloat(f,&flag);
    if(flag) {
      i--;
      continue;
    }

    galaxy[i].x = tmp;
    galaxy[i].y = parseFloat(f,&flag);
    galaxy[i].m = (int) parseFloat(f, &flag);
    galaxy[i].sx = galaxy[i].sy = 0;
  }

  fclose(f);
  return galaxy;
}

FILE *initStorage(char *file, int nbStars, int nbIterations) {
  FILE *f = fopen(file,"w+");
  if(f == NULL) { printf("Failed to open output file.\n"); exit(FOPEN_FAIL); }
  fprintf(f,"%d %d",nbStars, nbIterations);
  return f;
}

void storeGalaxy(FILE *f, Star *galaxy, int nbStars) {
  int i;
  fprintf(f,"\n");
  for(i = 0; i < nbStars; i++)
    fprintf(f,"%f %f %d ",galaxy[i].x,galaxy[i].y,galaxy[i].m);
}
