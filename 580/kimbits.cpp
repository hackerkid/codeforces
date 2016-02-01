/*
    ID: bornawe1
    LANG: C++
    TASK: spin
*/
#include <stdio.h>
#include <assert.h>
#include <string.h>

int speed[5];      /* speed of each wheel */
int wedgest[5][5]; /* start of each wedge (-1 == no wedge) */
int wedglen[5][5]; /* length of each wedge */

int pos[5];        /* angular position of each wheel */
int t;             /* time (in seconds) since start */

/* (light[deg] >> wid) & 0x1 is true if and only if there
   is a wedge in wheel wid that a light can shine through at
   angle deg */
int light[360];    
 
/* mark all the degrees we can see through wheel w */
void mark_light(int w)
 {
  int lv, lv2; /* loop variables */
  int wpos; /* wedge position */

  for (lv = 0; lv < 5; lv++)
   {
    if (wedglen[w][lv] < 0) /* no more wedges for this wheel */
      break;

    /* start of wedge */
    wpos = (pos[w] + wedgest[w][lv]) % 360;

    for (lv2 = 0; lv2 <= wedglen[w][lv]; lv2++)
     { /* throughout extent of wedge */
      light[wpos] |= (1 << w); /* mark as hole in wheel */
      wpos = (wpos + 1) % 360; /* go to the next degree */
     }
   }
 }

int main(int argc, char **argv)
 {
  FILE *fp;
  FILE *fout;
  int w, f;
  int lv, lv2;

  fp = fopen("spin.in", "r");
  fout = fopen("spin.out", "w");
  assert(fp);
  assert(fout);
  
  /* read in the data */
  for (lv = 0; lv < 5; lv++)
   {
    fscanf (fp, "%d %d", &speed[lv], &w);
    for (lv2 = 0; lv2 < w; lv2++)
      fscanf (fp, "%d %d", &wedgest[lv][lv2], &wedglen[lv][lv2]);

    /* mark the rest of the wedges as not existing for this wheel */
    for (; lv2 < 5; lv2++)
      wedglen[lv][lv2] = -1;
   }

  f = 0;
  while (t < 360) /* for each time step */
   {
    memset(light, 0, sizeof(light));

    /* mark the degrees we can see through each wheel */
    for (lv = 0; lv < 5; lv++)
      mark_light(lv);

    for (lv = 0; lv < 360; lv++)
      if (light[lv] == 31) /* we can shine a light through all five wheels */
        f = 1;

    if (f) break; /* we found a match! */

    /* make a time step */
    t++;
    for (lv = 0; lv < 5; lv++)
      pos[lv] = (pos[lv] + speed[lv]) % 360;
   }

  /* after 360 time steps, all the wheels have returned to their
     original location */
  if (t >= 360) fprintf (fout, "none\n");
  else fprintf (fout, "%i\n", t);

  return 0;
 }