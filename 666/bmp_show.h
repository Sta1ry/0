#ifndef __BMP_SHOW_H
#define __BMP_SHOW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <sys/mman.h>

int bmp_show_mix(int x0,int y0,int width,int height,char *name);
int bmp_show_self(int x0,int y0,int width,int height,char *name);


#endif