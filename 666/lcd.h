#ifndef __LCD_H
#define __LCD_H

#include <stdio.h>
//open函数的头文件
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//close函数的头文件
#include <unistd.h>
//mmap函数的头文件
#include <sys/mman.h>
//memset函数的头文件
#include <string.h>
//malloc函数的头文件
#include <stdlib.h>



//函数声明
//打开lcd屏幕函数
int lcd_open(void);
//关闭lcd屏幕函数
int lcd_close(void);
//清空lcd屏幕函数
int lcd_clear(void);
//显示bmp图片函数
int lcd_draw_bmp(int x_s, int y_s, char *bmppath);

//变量外部调用声明
extern int lcd_fd;
extern int *lcd_buf;

#endif
