#include "move.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int shp, shp_next;
static int dir;
static int paused = 0;
static int running = 0;
static int exit_game = 0;
static int muted = 0;  // 0 = 正常播放，1 = 静音


struct block *bk, *bk_next;
struct block *move_check(struct ls_all *head, int dir);

void *auto_down(void *arg);
void *time_out(void *arg);

// 模式选择函数
int choose_mode() {
    int x, y;
    int grade = -1;
    bmp_show_mix(0, 0, 800, 480, "./tetris_pic/start.bmp");

    while (grade == -1) {
        get_xy(&x, &y);
        if (x >= 80 && x <= 280 && y >= 300 && y <= 440) {
            bmp_show_mix(0, 0, 800, 480, "./tetris_pic/start-1.bmp");
            printf("jiandan moshi\n");
            grade = 0;
        } else if (x >= 300 * 1.25 && x <= 500 * 1.25 && y >= 300 * 1.25 && y <= 440 * 1.25) {
            bmp_show_mix(0, 0, 800, 480, "./tetris_pic/start-2.bmp");
            printf("putong moshi\n");
            grade = 1;
        } else if (x > 520 * 1.25 && x <= 720 * 1.25 && y >= 300 * 1.25 && y <= 440 * 1.25) {
            bmp_show_mix(0, 0, 800, 480, "./tetris_pic/start-3.bmp");
            printf("kunnan moshi\n");
            grade = 2;
        }

        if (grade != -1) {
            while (1) {
                get_xy(&x, &y);
                if (x > 340 * 1.25 && x <= 460 * 1.25 && y >= 80 * 1.25 && y <= 200 * 1.25) {
                    return grade;
                }
            }
        }
    }

    return grade;
}

int main(int argc, char *argv[]) {
    int x, y;
    pthread_t idt, idr;

    ts_open();
    lcd_open();

restart:
    paused = 0;
    running = 0;
    exit_game = 0;

    int grade = choose_mode();

    // 初始化速度
    if (grade == 0) speed = 0;
    else if (grade == 1) speed = 1;
    else speed = 2;

    // 初始化
    struct ls_all *head = ls_init();
    score = 0;

    bmp_show_mix(0, 0, 800, 480, "./tetris_pic/bck4.bmp");

    srand((unsigned int)time(NULL));
    shp = rand() % 7 + 1;
    shp_next = rand() % 7 + 1;
    bk = bk_init(shp);
    bk_next = bk_init(shp_next);

    the_show(bk);
    the_show_next(bk_next);
    score_show(0);

    pthread_create(&idt, NULL, auto_down, NULL);
    pthread_create(&idr, NULL, time_out, NULL);
    if (!muted) {
    system("madplay ./tetris_pic/bgm.mp3 -r &");
}


    while (1) {
label:
        if (running == 1) {
            pthread_cancel(idt);
            pthread_join(idt, NULL);
            pthread_cancel(idr);
            pthread_join(idr, NULL);

            bmp_show_mix(0, 0, 800, 480, "./tetris_pic/bck4.bmp");
            srand((unsigned int)time(NULL));
            shp = rand() % 7 + 1;
            shp_next = rand() % 7 + 1;
            bk = bk_init(shp);
            bk_next = bk_init(shp_next);
            head = ls_init();
            score = 0;

            the_show(bk);
            the_show_next(bk_next);
            score_show(0);
            pthread_create(&idt, NULL, auto_down, NULL);
            pthread_create(&idr, NULL, time_out, NULL);
            running = 0;
        }

        if (!paused) {
            dir = -2;
            while (dir == -2) usleep(1000);

            if (dir == -1) {
                change_type(bk);
                the_show_bck_type(bk);
            } else {
                change_dir(bk->p, dir);
                the_show_bck_dir(bk->p, dir);
            }

            bk = move_check(head, dir);
            if (bk == NULL) {
                running = 1;
                goto label;
            }

            the_show(bk);
        } else {
            while (1) {
                if (paused == 1) break;
            }
        }

        if (exit_game == 1) {
            pthread_cancel(idt);
            pthread_join(idt, NULL);
            pthread_cancel(idr);
            pthread_join(idr, NULL);
            exit_game = 0;
            printf("游戏已退出，返回初始界面\n");
            goto restart;
        }
    }

    ts_close();
    lcd_close();
    return 0;
}



//移动检查是否越界及掉落到底部
struct block * move_check(struct ls_all *head,int dir){
	
	int rt;
	
	//1.检查是否掉落底部
	if(ls_check(head,bk->p) == -1){
		
		//1.1 变形越界则恢复原来（再变4次）
		if(dir == -1){
			
			change_type(bk);
			change_type(bk);
			change_type(bk);
			
			//the_show(bk);
		}
		else{
			//1.2 移动越界 则恢复原来
			change_dir_off(bk->p,dir);
			
			if(dir == 0){ //1.2.1 向下移动越界则已经到底把它加入到链表
				the_show(bk);
				if(ls_updata(head,bk) == -1){ //加入链表，包括重新显示整个链表
					return NULL; //game over
				}
				shp_next = ((unsigned int)rand())%7+1;
				bk = bk_next; //有新的方块产生
				the_show_bck_next(bk_next->p);
				bk_next = bk_init(shp_next);//有新的下一个方块产生
				the_show_next(bk_next);

			}
			//1.2.2 左右移动越界 正常显示原来的
			else if(dir == 1||dir ==2){
				//the_show(bk);
			}

		}
		
		return bk;
	}
	
	
	
	//2. 越界检查
	rt = bound_check(bk->p);

	//2.1 掉落底部
	if(rt==0){
		change_dir_off(bk->p,0);
		the_show(bk);
		ls_updata(head,bk);
		shp_next = ((unsigned int)rand())%7+1;
		bk = bk_next;
		the_show_bck_next(bk_next->p);
		bk_next = bk_init(shp_next);
		the_show_next(bk_next);

	}
	
	//2.2 左右移动越界
	else if(rt == -1){
		while(bound_check(bk->p)== -1){
			change_dir_off(bk->p,1);
		}
	}
	else if(rt == -2){
		while(bound_check(bk->p)== -2){
			change_dir_off(bk->p,2);
		}
	}	
	
	return bk;
	
}
void  *auto_down(void *arg){
	
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);

	int x,y;

	
	while(1){
		
		get_xy(&x,&y);
		
		if(x>422&&x<558&&y>383&&y<480){
			
			dir =1;

		}
		else if(x>536&&x<636&&y>448&&y<595){
			dir = 0;

		}

		else if(x>652&&x<798&&y>383&&y<480){
			dir = 2;

		}

		else if(x>536&&x<636&&y>218&&y<365){
			dir = -1;
		}

		else if(x>0 && x<110 * 1.25 && y>0 &&y<60 * 1.25){
            paused = !paused;
		}
        else if(x>166 * 1.25&&x<260 *1.25&&y>0&&y<60 * 1.25){
            running = 1;
        }
        else if(x>0 && x<110 * 1.25 && y>60*1.25 &&y<120 * 1.25){
            exit_game = 1;
        }
        // 静音/恢复 按钮区域：右下角 680~780 x 400~460
        else if (x > 680 * 1.25 && x < 780 * 1.25 && y > 400 * 1.25 && y < 460 * 1.25) {
            if (!muted) {
                system("killall madplay");
                muted = 1;
                printf("已静音\n");
            } else {
                system("madplay ./tetris_pic/bgm.mp3 -r &");
                muted = 0;
                printf("已恢复播放\n");
            }
        }
    }
}



void *time_out(void *arg){
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
    
    // 定义三个等级的基础延迟时间（毫秒），增加差异
    const int base_delays[3] = {1000, 500, 200}; // 简单,普通,困难
    
    while(1){
        // 确保speed在有效范围内
        if(speed < 0 || speed > 2) speed = 0;
        
        // 根据等级获取基础延迟
        int delay = base_delays[speed];
        
        // 每得5分加速10%（最多加速50%）
        int acceleration = score / 5; 
        if(acceleration > 5) acceleration = 5; // 最大加速50%
        
        delay = delay * (10 - acceleration) / 10;
        
        // 确保最小延迟（防止过快）
        if(delay < 50) delay = 50;
        
        usleep(delay * 1000); // 转换为微秒
        dir = 0;
    }
}










