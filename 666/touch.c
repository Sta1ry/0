#include"touch.h"
//触摸屏相关变量
int ts_fd;

//打开触摸屏
int ts_open(void)
{
	//1.打开触摸屏
	ts_fd = open("/dev/input/event0", O_RDWR);
	//判断是否打开成功
	if(ts_fd < 0)
	{
		perror("打开触摸屏失败");		//perror专门用于打印错误信息
		return -1;
	}
}

//关闭触摸屏
int ts_close(void)
{
	//3.关闭文件
	close(ts_fd);
}
//获取点击坐标点--》获取一个触摸点后不等手指离开屏幕立即返回
int get_xy(int *x,int *y){
	
	int fd_touch = open("/dev/input/event0",O_RDONLY);
	if(fd_touch == -1){
		printf("open touch dev fail\n");
		return -1;
	}
	
	struct input_event ts;
	
	int i=0;
	while(1){
		
		read(fd_touch,&ts,sizeof(ts));
		
		// printf("type:%d  code:%d   value:%d\n",ts.type,ts.code,ts.value);
		
		if(ts.type == 3){
			if(ts.code == 0){
				*x = ts.value;
				i++;
			}
			else if(ts.code == 1){
				*y = ts.value;
				i++;
			}
		}

		if(i>=2){
			break;
		}
		printf("(%d , %d)\n",*x,*y);
	}
	
	close(fd_touch);
	
}
