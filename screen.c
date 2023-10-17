#include <stdio.h>
#include <string.h>

unsigned char buffer[128][8];


int get_y8(int y64){
	return y64 / 8;
}

int get_b8(int y64){
	return y64 % 8;
}

int get_bit(unsigned char data,int bit){
	data = data >> bit;
	return data % 2;
}

void print_buffer(void){
        for (int y = 0; y < 8; y++){
                for (int b = 0; b < 8; b++){
                        for(int x = 0; x < 128; x++){
                                printf("%d", get_bit(buffer[x][y], b));
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

void draw_h_line(int x1, int x2, int y){
	//need to add fix if x2 < x1
	for(int i = x1;
}

void draw_rect(int x1, int y1, int x2, int y2){
	//add code to drawing 4 lines here
}

void main(void){
	//unsigned char buffer[128][8];
	memset(&buffer, 0, sizeof(buffer));
	draw_dot(127, 63);
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
