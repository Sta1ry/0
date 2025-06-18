/*为掉落的所有方块创建链表进行存贮*/

#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

//每个小方块为一个链表结点
struct ls_all{
	
	struct ls_all *next;
	struct ls_all *pre;
	
	int shape; //形状用来区分显示颜色
	
	int x0;
	int y0;
};

struct ls_all * ls_init();

void ls_add(struct ls_all *head,int x0,int y0,int shape);

struct ls_all * ls_del(struct ls_all *node);






#endif