#include "lcd.h"

//lcd屏幕相关变量
int lcd_fd;
int *lcd_buf;

//打开lcd屏幕函数
int lcd_open(void)
{
	//1.打开lcd屏幕文件
	lcd_fd = open("/dev/fb0", O_RDWR);
	if(lcd_fd < 0)
	{
		perror("打开LCD失败");		
		return -1;
	}
	
	//2.映射lcd屏幕到内存中
	lcd_buf = mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
	if(lcd_buf == MAP_FAILED)
	{
		perror("映射LCD失败");		
		return -1;
	}
	return 0;
}

//关闭lcd屏幕函数
int lcd_close(void)
{
	//解除映射，关闭文件
	munmap(lcd_buf, 800*480*4);
	close(lcd_fd);
}

//清空lcd屏幕函数
int lcd_clear(void)
{
	//给lcd屏幕清空数据
	memset(lcd_buf, 0, 800*480*4);		//给lcd_buf中800*480*4个字节大小的空间写入0	
}

//显示bmp图片函数
int lcd_draw_bmp(int x_s, int y_s, char *bmppath)
{
	//3.打开bmp图片文件
	int bmp_fd = open(bmppath, O_RDWR);
	if(bmp_fd < 0)
	{
		perror("打开BMP失败");		
		return -1;
	}
	
	//4.先读取54个文件头数据
	unsigned char head_buf[54] ={0};
	read(bmp_fd, head_buf, sizeof(head_buf));
	
	//保存图片的宽和高
	unsigned int bmp_width = head_buf[18] | head_buf[19]<<8;
	unsigned int bmp_height = head_buf[22] | head_buf[23]<<8;
	printf("/root/2.bmp w:%d h:%d\n", bmp_width, bmp_height);
	
	//4.再读取bmp图片颜色值数据
	unsigned char *bmp_buf = (unsigned char *)malloc(bmp_width*bmp_height*3);		//malloc动态申请空间
	read(bmp_fd, bmp_buf, bmp_width*bmp_height*3);
	
	
	//5.给LCD中每一个像素点写入bmp图片的像素点数据
	int bmp_x, bmp_y, lcd_x, lcd_y, pixel;
	
	//总共要处理的像素点个数：bmp_width*bmp_height
	for(bmp_y=0, lcd_y=bmp_height-1+y_s; bmp_y<bmp_height; bmp_y++, lcd_y--)
	{
		for(bmp_x=0, lcd_x=0+x_s; bmp_x<bmp_width; bmp_x++, lcd_x++)
		{
			//找到要写入到lcd屏幕中的bmp像素点的位置（编号）
			pixel = bmp_x+bmp_y*bmp_width;
			//添加保护
			if(lcd_x >= 0 && lcd_x < 800 && lcd_y >= 0 && lcd_y <480)
			{
				//将24位--->32位，上下翻转
				lcd_buf[800*lcd_y+lcd_x] = 0x00<<24 | bmp_buf[3*pixel] | bmp_buf[3*pixel+1]<<8 | bmp_buf[3*pixel+2]<<16;
			}
		}
	}
	
	//释放空间
	free(bmp_buf);
	//关闭bmp文件
	close(bmp_fd);
}






