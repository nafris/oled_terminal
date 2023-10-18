#include <stdio.h>
#include <string.h>
#include "font.h"

#define GET_Y8(y) (y / 8)
#define GET_B8(y) (y % 8)
#define GET_BIT(data, b) ((data >> b) % 2)

unsigned char buffer[128][8];
int cursorX = 0;
int cursorY = 0;

void print_buffer(void){
        for (int y = 0; y < 8; y++){
                for (int b = 0; b < 8; b++){
                        for(int x = 0; x < 128; x++){
                                //printf("%d", get_bit(buffer[x][y], b));
				printf("%c", GET_BIT(buffer[x][y], b) ? '%' :  ' ');
                        }
                        printf("\n");
                }
        }
}

void draw_dot(int x128, int y64){
	int y8 = GET_Y8(y64);
	int b8 = GET_B8(y64);
	buffer[x128][y8] |= 1 << b8;
}

void draw_h_line(int x1, int x2, int y64){
	//need to add fix if x2 < x1
	int y8 = GET_Y8(y64);
	int b8 = GET_B8(y64);
	for(int i = x1; i <= x2; i++){
		buffer[i][y8] |= 1 << b8;
	}
}

void draw_v_line(int y1, int y2, int x128){
	//need to add fix if y2 < y1
	int y8;
	int b8;
	for (int i = y1; i <= y2; i++){
		y8 = GET_Y8(i);
		b8 = GET_B8(i);
		buffer[x128][y8] |= 1 << b8;
	}
}

void draw_rect(int x1, int y1, int x2, int y2){
	draw_h_line(x1, x2, y1);
	draw_h_line(x1, x2, y2);
	draw_v_line(y1, y2, x1);
	draw_v_line(y1, y2, x2);
}

void draw_line(int x1, int y1, int x2, int y2){
	int k; int y8; int b8; int y;
	k = 1024 * (y2 - y1) / (x2 - x1);
	for (int i = x1; i <= x2; i++){
		y = (i - x1) * k / 1024 + y1;
		y8 = GET_Y8(y);
		b8 = GET_B8(y);
		buffer[i][y8] |= 1 << b8;
	}
}

void draw_letter(char letter[8]){
	for (int i = 0; i < 8; i++){
		buffer[cursorX * 8 + i][cursorY] = letter[i];
	}
	cursorX++;
}

void write_text(char text[16]){
	for (int i = 0; i < strlen(text); i++){
		draw_letter(font[text[i]]);
	}
}

void clear_buffer(void){
	memset(&buffer, 0, sizeof(buffer));
}

void main(void){
	//draw_dot(127, 63);
	//draw_h_line(10, 20, 5);
	//draw_v_line(40,60,20);
	//draw_rect(10,10,20,20);

	//char letter[8];
	//memcpy(&letter, font[100], sizeof(letter));
	//draw_letter(letter);
	//memcpy(&letter, font[105], sizeof(letter));
	//draw_letter(letter);
	//print_buffer();
	//write_text("Chemtrails");
	//cursorY++;
	//cursorX = 0;
	//write_text("  are");
	//cursorY++;
	//cursorX = 0;
	//write_text("text");
	draw_line(1, 1, 100, 10);
	print_buffer();
}
