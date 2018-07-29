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

int parse_move(char *src, char *dst, int *sx, int *sy, int *dx, int *dy)
{
	if ( !(( 'a'	<= src[0] || src[0] <=	'h') ||
	       ( 'a'	<= dst[0] || dst[0] <=	'h') ||
	       (  1	<= src[1] || src[1] <=	 8 ) ||
	       (  1	<= dst[1] || dst[1] <=	 8 )) ) {
		return 1;
	}
	(*sy) = (int)(src[0] - 'a');
	(*sx) = 8 - (int)(src[1] - '0');
	(*dy) = (int)(dst[0] - 'a');
	(*dx) = 8 - (int)(dst[1] - '0');

	printf("%d %d || %d %d\n", *sx, *sy, *dx, *dy);

	return 0;
}
