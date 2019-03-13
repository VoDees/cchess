/*
 *	File:	cchess.c
 *	Author:	VoDees
 *	Use:	The main source file for Console chess ^ ^
 **/
#include "cchess.h"

int main()
{
	int y_src, x_src, y_dst, x_dst;
	char src[4] = {0};
	char dst[4] = {0};
	bool turn = true;
	
	while (true) {
		if (check_mate(turn)) {
			printf("MAT\n");
			return 0;
		}
	turn = !turn;
		
		system("clear");
		
		print_chessboard();
		
		printf("Pohyb figurkou z: ");
		scanf("%4s", src);
		printf("\nNa: ");
		scanf("%4s", dst);
		if (parse_move(src, dst, &y_src, &x_src, &y_dst, &x_dst)) {
			fprintf(stderr, "\nSpatnej format sefe!"
				"dej si repete..\n");
			continue;	
		}
		
		if (move_cpiece(y_src, x_src, y_dst, x_dst, turn)) {
			fprintf(stderr, "\nZapsal si to nahovno!"
				" Zkus to znova a dej do toho srdicko :)\n");
			continue;
		}
	}

	return 0;
}
