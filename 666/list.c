

#include "list.h"

//链表初始化
struct ls_all * ls_init(){
	
	struct ls_all *head;
	
	head = (struct ls_all*)malloc(sizeof(struct ls_all));
	
	head->next = head;
	head->pre = head;

	return head;
}




//尾插法加入链表当中
void ls_add(struct ls_all *head,int x0,int y0,int shape){
	
	struct ls_all *node;
	
	node = (struct ls_all*)malloc(sizeof(struct ls_all));
	
	node->next = head;
	node->pre = head->pre;
	head->pre->next = node;
	head->pre = node;
	
	node->x0 = x0;
	node->y0 = y0;
	node->shape = shape;
}

//删除结点--》用作消行
struct ls_all * ls_del(struct ls_all *node){
	
	struct ls_all *tmp;
	
	tmp = node->pre;
	tmp->next = node->next;
	node->next->pre = tmp;
	
	free(node);

	
	return tmp;
}
