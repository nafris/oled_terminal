#include <stdio.h>
#include <string.h>

unsigned char buffer[128][8];

int get_y8(int y64){
	return y64 / 8;
}

int get_b8(int y64){
	return y64 % 8;
}

int get_bit(unsigned char data, int bit){
	data = data >> bit;
	return data % 2;
}

void print_buffer(void){
        for (int y = 0; y < 8; y++){
                for (int b = 0; b < 8; b++){
                        for(int x = 0; x < 128; x++){
                                //printf("%d", get_bit(buffer[x][y], b));
				if(get_bit(buffer[x][y], b)){
					 printf("*");
				}else{
					printf(" ");
				}
                        }
                        printf("\n");
                }
        }
}

void draw_dot(int x128, int y64){
	int y8 = get_y8(y64);
	int b8 = get_b8(y64);
	buffer[x128][y8] |= 1 << b8;
}

void draw_h_line(int x1, int x2, int y64){
	//need to add fix if x2 < x1
	int y8 = get_y8(y64);
	int b8 = get_b8(y64);
	for(int i = x1; i <= x2; i++){
		buffer[i][y8] |= 1 << b8;
	}
}

void draw_v_line(int y1, int y2, int x128){
	//need to add fix if y2 < y1
	int y8;
	int b8;
	for (int i = y1; i <= y2; i++){
		y8 = get_y8(i);
		b8 = get_b8(i);
		buffer[x128][y8] |= 1 << b8;
	}
}

void draw_rect(int x1, int y1, int x2, int y2){
	draw_h_line(x1, x2, y1);
	draw_h_line(x1, x2, y2);
	draw_v_line(y1, y2, x1);
	draw_v_line(y1, y2, x2);
}

void main(void){
	//unsigned char buffer[128][8];
	memset(&buffer, 0, sizeof(buffer));
	draw_dot(127, 63);
	//draw_h_line(10, 20, 5);
	//draw_v_line(40,60,20);
	draw_rect(10,10,20,20);	
	print_buffer();
	//for (int y = 0; y < 8; y++){
	//	for (int b = 0; b < 8; b++){
//			for(int x = 0; x < 128; x++){
//				printf("%d", get_bit(buffer[x][y], b));
//			}
//			printf("\n");
//		}
//	}
}
