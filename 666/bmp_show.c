#include"bmp_show.h"


//指定位置显示 指定大小图片
int bmp_show_mix(int x0,int y0,int width,int height,char *name){
	
	
	int fd_bmp = open(name,O_RDONLY);
	if(fd_bmp == -1){
		printf("can not open %s\n",name);
		return -1;
	}
	
	struct stat pst;
	
	fstat(fd_bmp,&pst);
	// printf("bmp size:%d\n",pst.st_size);
	
	
	char *buf;
	buf = (char *)malloc(pst.st_size);
	
	
	
	lseek(fd_bmp,54,SEEK_SET);
	read(fd_bmp,buf,pst.st_size-54);
	
	int fd_lcd = open("/dev/fb0",O_RDWR);
	if(fd_bmp == -1){
		printf("can not open lcd\n");
		close(fd_bmp);
		free(buf);
		return -1;
	}
	
	
	char *p;
	p = (char *)mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,fd_lcd,0);
	
	// return 0;
	
	int i,j;
	int lcd_offset,bmp_offset;
	
	for(j=0;j<480-y0&&j<height;j++){
		for(i=0;i<800-x0&&i<width;i++){
			
			lcd_offset = ((j+y0)*800+i+x0)*4;
			
			bmp_offset = ((height-1-j)*width+i)*3;
			
			memcpy(p+lcd_offset,buf+bmp_offset,3);
			
		}
	}
	
	
	close(fd_lcd);
	close(fd_bmp);
	free(buf);
	munmap(p,800*480*4);
	
	return 0;
}


//显示背景图片的指定区域
int bmp_show_self(int x0,int y0,int width,int height,char *name){
	
	
	int fd_bmp = open(name,O_RDONLY);
	if(fd_bmp == -1){
		printf("can not open %s\n",name);
		return -1;
	}
	
	struct stat pst;
	
	fstat(fd_bmp,&pst);
	// printf("bmp size:%d\n",pst.st_size);
	
	
	char *buf;
	buf = (char *)malloc(pst.st_size);
	
	
	
	lseek(fd_bmp,54,SEEK_SET);
	read(fd_bmp,buf,pst.st_size-54);
	
	int fd_lcd = open("/dev/fb0",O_RDWR);
	if(fd_bmp == -1){
		printf("can not open lcd\n");
		close(fd_bmp);
		free(buf);
		return -1;
	}
	
	
	char *p;
	p = (char *)mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,fd_lcd,0);
	
	// return 0;
	
	int i,j;
	int lcd_offset,bmp_offset;
	
	for(j=0;j<480-y0&&j<height;j++){
		for(i=0;i<800-x0&&i<width;i++){
			
			lcd_offset = ((j+y0)*800+i+x0)*4;
			
			bmp_offset = ((479-y0-j)*800+i+x0)*3;
			
			memcpy(p+lcd_offset,buf+bmp_offset,3);
			
		}
	}
	
	
	close(fd_lcd);
	close(fd_bmp);
	free(buf);
	munmap(p,800*480*4);
	
	return 0;
}