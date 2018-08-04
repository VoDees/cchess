/*
 *	File:	cchess.c
 *	Author:	VoDees
 *	Use:	The main source file for Console chess ^ ^
 **/
#include "cchess.h"

int main()
{
	int y_src, x_src, y_dst, x_dst;
	char src[2] = {0};
	char dst[2] = {0};
	
	print_chessboard();
	while (true) {
		scanf("%2s", src);
		scanf("%2s", dst);
		if (parse_move(src, dst, &y_src, &x_src, &y_dst, &x_dst)) {
			fprintf(stderr, "\nSpatnej format sefe!"
				"dej si repete..\n");
			continue;		
		}
		if (move_cpiece(y_src, x_src, y_dst, x_dst)) {
			fprintf(stderr, "\nZapsal si to nahovno!"
				" Zkus to znova a dej do toho srdicko :)\n");
			continue;
		}
		print_chessboard();
	}

	return 0;
}
