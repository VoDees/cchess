/*
 *	File:	cchess.c
 *	Author:	VoDees
 *	Use:	The main source file for Console chess ^ ^
 **/
#include "cchess.h"

int main()
{
	int sx, sy, dx, dy;
	char src[2] = {0};
	char dst[2] = {0};
	
	print_chessboard();
	while (true) {
		scanf("%2s", src);
		scanf("%2s", dst);
		if (parse_move(src, dst, &sx, &sy, &dx, &dy)) {
			fprintf(stderr, "\nSpatnej format sefe!"
				"dej si repete..\n");
			continue;		
		}
		if (move_cpiece(sx, sy, dx, dy)) {
			fprintf(stderr, "\nZapsal si to nahovno!"
				" Zkus to znova a dej do toho srdicko :)\n");
			continue;
		}
		print_chessboard();
	}

	return 0;
}
