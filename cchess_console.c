/*
 *	File:	cchess_console.c
 *	Author:	VoDees
 **/

#include "cchess.h"




void print_chessboard()
{
	//	array for chessboard appearance
	static const char ap_arr[112][8] = {	//void
		// 0	      1          2	    3
		  "       ", "'''''''", "       ", "'''''''",
		  "       ", "'''''''", "       ", "'''''''",
		  "       ", "'''''''", "       ", "'''''''",
		  "       ", "'''''''", "       ", "'''''''",
		       	//pawn
		// 16	      17	 18	    19
  	  	  "       ", "'''''''", "       ", "'''''''",
 	 	  "   #   ", "'''#'''", "   O   ", "'''O'''",
                  " ##### ", "'#####'", " OOOOO ", "'OOOOO'",
                  "  ###  ", "''###''", "  OOO  ", "''OOO''",
 	 	      	//rook
		// 32	      33	 34	    35
		  " #   # ", "'#'''#'", " O   O ", "'O'''O'",
                  " ##### ", "'#####'", " OOOOO ", "'OOOOO'",
                  "  ###  ", "''###''", "  OOO  ", "''OOO''",
                  "  ###  ", "''###''", "  OOO  ", "''OOO''",
		  	//knight
                // 48	      49	 50	    51
		  "  #####", "''#####", "  OOOOO", "''OOOOO",
   	   	  " ##  ##", "'##''##", " OO  OO", "'OO''OO",
  	  	  "    ## ", "''''##'", "    OO ", "''''OO'",
                  "   ### ", "'''###'", "   OOO ", "'''OOO'",
                   	//bishop
  	  	// 64	     65		 66	    67
		  "   #   ", "'''#'''", "   O   ", "'''O'''",
 	 	  " ##### ", "'#####'", " OOOOO ", "'OOOOO'",
                  "  ###  ", "''###''", "  OOO  ", "''OOO''",
                  "  ###  ", "''###''", "  OOO  ", "''OOO''",
		   	//queen
                // 80	      81	 82	    83
		  " # # # ", "'#'#'#'", " O O O ", "'O'O'O'",
                  " ##### ", "'#####'", " OOOOO ", "'OOOOO'",
                  "  ###  ", "''###''", "  OOO  ", "''OOO''",
                  " ##### ", "'#####'", " OOOOO ", "'OOOOO'",
		   	//king
		// 96 	      97	 98	    99
		  "   #   ", "'''#'''", "   O   ", "'''O'''",
		  " ##### ", "'#####'", " OOOOO ", "'OOOOO'",
		  "   #   ", "'''#'''", "   O   ", "'''O'''",
		  " ##### ", "'#####'", " OOOOO ", "'OOOOO'"
	};

	printf("     a       b       c       d    "
	       "   e       f       g       h     \n"
	       " +-------+-------+-------+-------+"
	       "-------+-------+-------+-------+\n");
	for (int k = 0; k < 8; k++) {
		for (int i = 0; i < 4; i++) {
			if (i == 2)
				printf("%d", 8 - k);
			else
				printf(" ");
			for (int j = 0; j < 8; j++) {
				printf("|%s",
					ap_arr[chessboard[k][j].ap_index + 4 * i]);
				if (j == 7)
					printf("|");
			}
			if (i == 2)
				printf("%d", 8 - k);
			else
				printf(" ");
			printf("\n");	
		}
		printf(" +-------+-------+-------+-------+"
			 "-------+-------+-------+-------+\n");
	}
	printf("     a       b       c       d"
	       "       e       f       g       h     \n");
}

int parse_move(char *src, char *dst, int *y_src, int *x_src, int *y_dst, int *x_dst)
{
	if ('a' > src[0] || src[0] > 'h' ||
	    'a' > dst[0] || dst[0] > 'h' ||
	    '1' > src[1] || src[1] > '8' ||
	    '1' > dst[1] || dst[1] > '8' )
		return 1;

	(*x_src) = (int)(src[0] - 'a');
	(*y_src) = 8 - (int)(src[1] - '0');
	(*x_dst) = (int)(dst[0] - 'a');
	(*y_dst) = 8 - (int)(dst[1] - '0');

	return 0;
}
