#include "move.h"

/*以下7个函数为7种形状显示的坐标初始化函数
  返回的是一个整形的数组指针，用malloc申请的堆内存，
  总共40个元素，分为5组，每组8个元素。
  第一组是此形状掉落时的初始化坐标（每种形状都有4个小方块）
  后面4组是变形时相对于之前的偏移量，加上这个偏移量就可以变形
*/
 int score; 
 int speed;

int * arry_init_O(){
	
	int *a;
	
	a = (int * )malloc(sizeof(int)*4*5*2);
	
	a[0]=140;  a[1]=20;
	a[2]=120;  a[3]=20;
	a[4]=120;   a[5]=40;
	a[6]=140;   a[7]=40;
	
	a[8]=0;  a[9]=0;
	a[10]=0;  a[11]=0;
	a[12]=0;   a[13]=0;
	a[14]=0;   a[15]=0;

	a[16]=0;  a[17]=0;
	a[18]=0;  a[19]=0;
	a[20]=0;   a[21]=0;
	a[22]=0;   a[23]=0;

	a[24]=0;  a[25]=0;
	a[26]=0;  a[27]=0;
	a[28]=0;   a[29]=0;
	a[30]=0;   a[31]=0;

	a[32]=0;  a[33]=0;
	a[34]=0;  a[35]=0;
	a[36]=0;   a[37]=0;
	a[38]=0;   a[39]=0;	
	
	
	return a;
}

int * arry_init_I(){
	
	int *a;
	
	a = (int * )malloc(sizeof(int)*4*5*2);
	
	a[0]=180;  a[1]=20;
	a[2]=160;  a[3]=20;
	a[4]=140;   a[5]=20;
	a[6]=120;   a[7]=20;
	
	a[8]=-20;  a[9]=-20;
	a[10]=0;  a[11]=0;
	a[12]=20;   a[13]=20;
	a[14]=40;   a[15]=40;

	a[16]=20;  a[17]=20;
	a[18]=0;  a[19]=0;
	a[20]=-20;   a[21]=-20;
	a[22]=-40;   a[23]=-40;

	a[24]=-20;  a[25]=-20;
	a[26]=0;  a[27]=0;
	a[28]=20;   a[29]=20;
	a[30]=40;   a[31]=40;

	a[32]=20;  a[33]=20;
	a[34]=0;  a[35]=0;
	a[36]=-20;   a[37]=-20;
	a[38]=-40;   a[39]=-40;	
	
	
	return a;
}

int * arry_init_S(){
	
	int *a;
	
	a = (int * )malloc(sizeof(int)*4*5*2);
	
	a[0]=160;  a[1]=20;
	a[2]=140;  a[3]=20;
	a[4]=140;   a[5]=40;
	a[6]=120;   a[7]=40;
	
	a[8]=-20;  a[9]=-20;
	a[10]=0;  a[11]=0;
	a[12]=20;   a[13]=-20;
	a[14]=40;   a[15]=0;

	a[16]=20;  a[17]=20;
	a[18]=0;  a[19]=0;
	a[20]=-20;   a[21]=20;
	a[22]=-40;   a[23]=0;

	a[24]=-20;  a[25]=-20;
	a[26]=0;  a[27]=0;
	a[28]=20;   a[29]=-20;
	a[30]=40;   a[31]=0;

	a[32]=20;  a[33]=20;
	a[34]=0;  a[35]=0;
	a[36]=-20;   a[37]=20;
	a[38]=-40;   a[39]=0;	
	
	
	return a;
}

int * arry_init_Z(){
	
	int *a;
	
	a = (int * )malloc(sizeof(int)*4*5*2);
	
	a[0]=120;  a[1]=20;
	a[2]=140;  a[3]=20;
	a[4]=140;   a[5]=40;
	a[6]=160;   a[7]=40;
	
	a[8]=20;  a[9]=20;
	a[10]=0;  a[11]=0;
	a[12]=20;   a[13]=-20;
	a[14]=0;   a[15]=-40;

	a[16]=-20;  a[17]=-20;
	a[18]=0;  a[19]=0;
	a[20]=-20;   a[21]=20;
	a[22]=0;   a[23]=40;

	a[24]=20;  a[25]=20;
	a[26]=0;  a[27]=0;
	a[28]=20;   a[29]=-20;
	a[30]=0;   a[31]=-40;

	a[32]=-20;  a[33]=-20;
	a[34]=0;  a[35]=0;
	a[36]=-20;   a[37]=20;
	a[38]=0;   a[39]=40;	
	
	
	return a;
}

int * arry_init_L(){
	
	int *a;
	
	a = (int * )malloc(sizeof(int)*4*5*2);
	
	a[0]=160;  a[1]=20;
	a[2]=140;  a[3]=20;
	a[4]=120;   a[5]=20;
	a[6]=120;   a[7]=40;
	
	a[8]=-20;  a[9]=-20;
	a[10]=0;  a[11]=0;
	a[12]=20;   a[13]=20;
	a[14]=40;   a[15]=0;

	a[16]=-20;  a[17]=20;
	a[18]=0;  a[19]=0;
	a[20]=20;   a[21]=-20;
	a[22]=0;   a[23]=-40;

	a[24]=20;  a[25]=20;
	a[26]=0;  a[27]=0;
	a[28]=-20;   a[29]=-20;
	a[30]=-40;   a[31]=0;

	a[32]=20;  a[33]=-20;
	a[34]=0;  a[35]=0;
	a[36]=-20;   a[37]=20;
	a[38]=0;   a[39]=40;	
	
	
	return a;
}

int * arry_init_J(){
	
	int *a;
	
	a = (int * )malloc(sizeof(int)*4*5*2);
	
	a[0]=120;  a[1]=20;
	a[2]=140;  a[3]=20;
	a[4]=160;   a[5]=20;
	a[6]=160;   a[7]=40;
	
	a[8]=20;  a[9]=20;
	a[10]=0;  a[11]=0;
	a[12]=-20;   a[13]=-20;
	a[14]=0;   a[15]=-40;

	a[16]=20;  a[17]=-20;
	a[18]=0;  a[19]=0;
	a[20]=-20;   a[21]=20;
	a[22]=-40;   a[23]=0;

	a[24]=-20;  a[25]=-20;
	a[26]=0;  a[27]=0;
	a[28]=20;   a[29]=20;
	a[30]=0;   a[31]=40;

	a[32]=-20;  a[33]=20;
	a[34]=0;  a[35]=0;
	a[36]=20;   a[37]=-20;
	a[38]=40;   a[39]=0;	
	
	
	return a;
}
int * arry_init_T(){
	
	int *a;
	
	a = (int * )malloc(sizeof(int)*4*5*2);
	
	a[0]=120;  a[1]=20;
	a[2]=140;  a[3]=20;
	a[4]=160;   a[5]=20;
	a[6]=140;   a[7]=40;
	
	a[8]=20;  a[9]=20;
	a[10]=0;  a[11]=0;
	a[12]=-20;   a[13]=-20;
	a[14]=20;   a[15]=-20;

	a[16]=20;  a[17]=-20;
	a[18]=0;  a[19]=0;
	a[20]=-20;   a[21]=20;
	a[22]=-20;   a[23]=-20;

	a[24]=-20;  a[25]=-20;
	a[26]=0;  a[27]=0;
	a[28]=20;   a[29]=20;
	a[30]=-20;   a[31]=20;

	a[32]=-20;  a[33]=20;
	a[34]=0;  a[35]=0;
	a[36]=20;   a[37]=-20;
	a[38]=20;   a[39]=20;	
	
	
	return a;
}


//检查方块左右下移动时有无越界
int bound_check(int *p){
	
	int i;

	for(i=0;i<4;i++){
		
		if(p[i*2+1]>460){

			return 0; //down out
		}
		
		if(p[i*2]>300){

			return -2; //right out
		}
		else if(p[i*2]<0){
		
			return -1; //left out
		}

	}
	
	return 1;
}

//移动方块，仅限三种方向
void change_dir(int *p,int dir){ //dir: 0-down  1-left  2-right
	
	int i=0;
	for(;i<4;i++){
		if(dir==0){
			p[i*2+1]+=20;
		}
		else if(dir==1){
			p[i*2]-=20;
		}
		else if(dir==2){
			p[i*2]+=20;
		}
		
	}
	
}

//移动越界 需要恢复回原来的坐标
void change_dir_off(int *p,int dir){ //dir: 0-down  1-left  2-right
	
	int i=0;
	
	// if(dir == 0){
		// printf("change_dir_off error\n");
		// exit(-1);
	// }
	
	for(;i<4;i++){

		if(dir==1){
			p[i*2]+=20;
		}
		else if(dir==2){
			p[i*2]-=20;
		}
		else if(dir == 0){
			p[i*2+1]-=20;
		}
		
	}
	
}

//变形
void change_type(struct block *bk){
	
	int i;

	
	if(bk->shape==1){
		return;
	}

	for(i=0;i<4;i++){

		bk->p[i*2]+=bk->p[i*2+bk->type*8];
		bk->p[i*2+1]+=bk->p[i*2+bk->type*8+1];
		// printf("%d\t%d\t",bk->p[i*2+bk->type*8],bk->p[i*2+bk->type*8+1]);
	
	}
	
	bk->type++;

	if(bk->type>=5){
		bk->type =1;
	}
	
	
	return;
}

//LCD显示移动的方块
void the_show(struct block *bk){
	
	int i;
	int *p = bk->p;
	int shp = bk->shape;
	
	char s[50];
	
	switch(shp){
		
		case 1:
			strcpy(s,"./tetris_pic/O.bmp");
			break;
		case 2:
			strcpy(s,"./tetris_pic/I.bmp");
			break;
		case 3:
			strcpy(s,"./tetris_pic/S.bmp");
			break;
		case 4:
			strcpy(s,"./tetris_pic/Z.bmp");
			break;
		case 5:
			strcpy(s,"./tetris_pic/L.bmp");
			break;
		case 6:
			strcpy(s,"./tetris_pic/J.bmp");
			break;
		case 7:
			strcpy(s,"./tetris_pic/T.bmp");
			break;			
		
	}
	
	
	
	for(i=0;i<4;i++){
		bmp_show_mix(p[i*2],p[i*2+1],20,20,s);
	}
	
}

//显示提示的下一个方块
void the_show_next(struct block *bk_next){
	
	int i;
	int *p = bk_next->p;
	int shp = bk_next->shape;
	
	char s[50];
	
	switch(shp){
		
		case 1:
			strcpy(s,"./tetris_pic/O.bmp");
			break;
		case 2:
			strcpy(s,"./tetris_pic/I.bmp");
			break;
		case 3:
			strcpy(s,"./tetris_pic/S.bmp");
			break;
		case 4:
			strcpy(s,"./tetris_pic/Z.bmp");
			break;
		case 5:
			strcpy(s,"./tetris_pic/L.bmp");
			break;
		case 6:
			strcpy(s,"./tetris_pic/J.bmp");
			break;
		case 7:
			strcpy(s,"./tetris_pic/T.bmp");
			break;			
		
	}
	
	
	
	for(i=0;i<4;i++){
		bmp_show_mix(p[i*2]+340,p[i*2+1]+20,20,20,s);
	}
	
}

//方块移动后需要把原来的方块--》消失--》显示背景色
void the_show_bck_dir(int *p,int dir){  //dir: 0-down  1-left  2-right
	
	int i;
	
	
	for(i=0;i<4;i++){
		if(dir==0){
			bmp_show_self(p[i*2],p[i*2+1]-20,20,20,"./tetris_pic/bck4.bmp");
		}
		else if(dir==1){
			bmp_show_self(p[i*2]+20,p[i*2+1],20,20,"./tetris_pic/bck4.bmp");
		}
		else if(dir==2){
			bmp_show_self(p[i*2]-20,p[i*2+1],20,20,"./tetris_pic/bck4.bmp");
		}
		
	}
	
}

//提示的下一个方块--》改变后，让之前的--》消失--》显示背景色
void the_show_bck_next(int *p){
	
	int i;
	
	for(i=0;i<4;i++){
	
		bmp_show_self(p[i*2]+340,p[i*2+1]+20,20,20,"./tetris_pic/bck4.bmp");
		
	}
	
	
}


//方块变形后让之前的--》消失--》显示背景色
void the_show_bck_type(struct block *bk){
	
	int i;
	if(bk->type==1)bk->type=5;
	
	for(i=0;i<4;i++){

		bmp_show_self(bk->p[i*2]-bk->p[i*2+(bk->type-1)*8] , bk->p[i*2+1]-bk->p[i*2+(bk->type-1)*8+1] , 20,20,"./tetris_pic/bck.bmp");
	
	}
	if(bk->type==5)bk->type=1;
}


//方块掉落后 得到一个新形状的方块 初始化函数--》得出初始化结构体
struct block * bk_init(int i){
	
	struct block *bk;
	bk =(struct block *)malloc(sizeof(struct block));
	

	
	switch(i){
		case 1:
			bk->p = arry_init_O();
			bk->shape = 1;
			break;
		case 2:
			bk->p = arry_init_I();
			bk->shape = 2;
			break;
		case 3:
			bk->p = arry_init_S();
			bk->shape = 3;
			break;
		case 4:
			bk->p = arry_init_Z();
			bk->shape = 4;
			break;
		
		case 5:
			bk->p = arry_init_L();
			bk->shape = 5;
			break;
		case 6:
			bk->p = arry_init_J();
			bk->shape = 6;
			break;
		case 7:
			bk->p = arry_init_T();
			bk->shape = 7;
			break;
		default:
			break;
	}
	
	
	bk->type = 1;

	
	return bk;
	
}


//把掉落的方块加入到掉落方块的链表当中去
int ls_updata(struct ls_all *head,struct block *bk){
	
	int *p = bk->p;
	
	int  i;
	
	for(i=0;i<4;i++){
		
		ls_add(head,p[i*2],p[i*2+1],bk->shape);
	}
	
	free(bk->p);
	
	free(bk);
	
	score++;  // 每一个加1分
	score_show(score); // 更新分数显示
	
	if(ls_check_self(head) == -1){
		return -1;
	}
	
}


//方块移动后，检查是否掉落到底部
int ls_check(struct ls_all *head,int *p){
	
	struct ls_all * tmp;
	
	int i;
	
	
	
	for(i=0;i<4;i++){
		
		tmp = head;
		
		tmp = tmp->next;

		while(tmp != head){
			
			if(tmp->x0 == p[i*2] && tmp->y0 == p[i*2+1]){
	
				return -1;
			}
			
			tmp = tmp->next;
			
		}	
		
		
	}
	
	return 0;
}


//检查整个链表有无消行-->把整个屏幕行扫描式检测
int ls_check_self(struct ls_all *head){
	
	struct ls_all * tmp;
	int i=460;
	int n =0;
	tmp = head;
	tmp = tmp->next;
	while(i>=40){
		
		n=0;
		tmp = head;
		tmp = tmp->next;
		while(tmp != head){
			if(tmp->y0 == i){
				
				n++;
				if(i < 80){
					printf("game over\n");
					return -1;
				}
			}
			// printf("%d  %d\n",i,tmp->y0);
			
			tmp = tmp->next;	
		}
		
		if(n == 16){
			
			score++;
			printf("%d line\n",score);
			score_show(score);
			
			speed = score/5;
			
			bmp_show_self(0,0,320,480,"./tetris_pic/bck4.bmp");
			tmp = head;
			tmp = tmp->next;
			while(tmp != head){
				if(tmp->y0 == i){
				
					tmp = ls_del(tmp);
					
				}
				// printf("%d  %d\n",i,tmp->y0);
				else if(tmp->y0 <i){
					
					tmp->y0+=20;
				}
				
				tmp = tmp->next;	
			}
			ls_all_show(head);
			i+=20;
			
		}		
		
		i-=20;
	}
	
	

	
}


//显示成绩
void score_show(int n){
	
	int a1,a2,a3;
	char s[3][50];
	char st[3][50];
	int i;
	
	a1 = n/100;
	a2 = n/10%10;
	a3 = n%10;
	
	for(i=0;i<3;i++){
		
		bzero(s[i],50);
	}
	
	s[0][0] = a1+48;
	s[1][0] = a2+48;
	s[2][0] = a3+48;
	
	for(i=0;i<3;i++){
		
		strcat(s[i],".bmp\0");
		strcpy(st[i],"./tetris_pic/");
		strcat(st[i],s[i]);
		bmp_show_mix(670+20*i,40,20,20,st[i]);
		// printf("%s\n",st[i]);
	}
	
	
}

//显示整个掉落的方块链表
void ls_all_show(struct ls_all *head){
	
	char s[50];

	struct ls_all * tmp;
	tmp = head;
	tmp = tmp->next;
	
	while(tmp != head){
		
		switch(tmp->shape){
		
			case 1:
				strcpy(s,"./tetris_pic/O.bmp");
				break;
			case 2:
				strcpy(s,"./tetris_pic/I.bmp");
				break;
			case 3:
				strcpy(s,"./tetris_pic/S.bmp");
				break;
			case 4:
				strcpy(s,"./tetris_pic/Z.bmp");
				break;
			case 5:
				strcpy(s,"./tetris_pic/L.bmp");
				break;
			case 6:
				strcpy(s,"./tetris_pic/J.bmp");
				break;
			case 7:
				strcpy(s,"./tetris_pic/T.bmp");
				break;			
		
		}

		bmp_show_mix(tmp->x0,tmp->y0,20,20,s);
		
		tmp = tmp->next;	
	}	
	
}