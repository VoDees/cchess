/*
 * Author:	VoDees
 * File:	chess.c
 * Use:
 * "     a       b       c       d       e       f       g       h     "
 * " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 * " | #   # |''#####|   #   |'#'#'#'|   #   |'''#'''|  #####|'#'''#'| "
 * " | ##### |'##''##| ##### |'#####'| ##### |'#####'| ##  ##|'#####'| "
 * "8|  ###  |''''##'|  ###  |''###''|   #   |''###''|    ## |''###''|8"
 * " |  ###  |'''###'|  ###  |'#####'| ##### |''###''|   ### |''###''| "
 * " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 * " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 * " |'''#'''|   #   |'''#'''|   #   |'''#'''|   #   |'''#'''|   #   | "
 * "7|'#####'| ##### |'#####'| ##### |'#####'| ##### |'#####'| ##### |7"
 * " |''###''|  ###  |''###''|  ###  |''###''|  ###  |''###''|  ###  | "
 * " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 * " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 * " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 * "6|       |'''''''|       |'''''''|       |'''''''|       |'''''''|6"
 * " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 * " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 * " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 * " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 * "5|'''''''|       |'''''''|       |'''''''|       |'''''''|       |5"
 * " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 * " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 * " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 * " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 * "4|       |'''''''|       |'''''''|       |'''''''|       |'''''''|4"
 * " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 * " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 * " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 * " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 * "3|'''''''|       |'''''''|       |'''''''|       |'''''''|       |3"
 * " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 * " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 * " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 * " |   O   |'''O'''|   O   |'''O'''|   O   |'''O'''|   O   |'''O'''| "
 * "2| OOOOO |'OOOOO'| OOOOO |'OOOOO'| OOOOO |'OOOOO'| OOOOO |'OOOOO'|2"
 * " |  OOO  |''OOO''|  OOO  |''OOO''|  OOO  |''OOO''|  OOO  |''OOO''| "
 * " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 * " |'O'''O'|  OOOOO|'''O'''| O O O |'''O'''|   O   |''OOOOO| O O O | "
 * " |'OOOOO'| OO  OO|'OOOOO'| OOOOO |'OOOOO'| OOOOO |'OO''OO| OOOOO | "
 * "1|''OOO''|    OO |''OOO''|  OOO  |'''O'''|  OOO  |''''OO'|  OOO  |1"
 * " |''OOO''|   OOO |''OOO''| OOOOO |'OOOOO'|  OOO  |'''OOO'|  OOO  | "
 * " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 * "     a       b       c       d       e       f       g       h     "
 */
#include <stdio.h>
#include <stdbool.h>

typedef enum {
	VOID,
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING
} ctype_t;

struct cpiece {
	ctype_t type;
	char *ap[4];
	bool iswhite;
};


void print_chessboard (struct cpiece chessboard[8][8])
{
	printf("     a       b       c       d       e       f       g       h     \n");
	printf(" +-------+-------+-------+-------+-------+-------+-------+-------+\n");
	for (int k = 0; k < 8; k++) {
		for (int i = 0; i < 4; i++) {
			if (i == 2)
				printf("%d", 8 - k);
			else
				printf(" ");
			for (int j = 0; j < 8; j++) {
				printf("|%s", chessboard[k][j].ap[i]);
				if (j == 7)
					printf("|");
			}
			if (i == 2)
				printf("%d", 8 - k);
			else
				printf(" ");
			printf("\n");	
		}
		printf(" +-------+-------+-------+-------+-------+-------+-------+-------+\n");
	}
	printf("     a       b       c       d       e       f       g       h     \n");
}



int main()
{
	char ap_arr[112][8] = { 	//void
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
	struct cpiece chessboard [8][8] = {
 		{
 			{ROOK,		{ap_arr[32], ap_arr[36],  ap_arr[40],  ap_arr[44]},  0},
 			{KNIGHT,	{ap_arr[49], ap_arr[53],  ap_arr[57],  ap_arr[61]},  0},
 			{BISHOP,	{ap_arr[64], ap_arr[68],  ap_arr[72],  ap_arr[76]},  0},
 			{QUEEN,		{ap_arr[81], ap_arr[85],  ap_arr[89],  ap_arr[93]},  0},
			{KING,		{ap_arr[96], ap_arr[100], ap_arr[104], ap_arr[108]}, 0},
 			{BISHOP,	{ap_arr[65], ap_arr[69],  ap_arr[73],  ap_arr[77]},  0},
 			{KNIGHT,	{ap_arr[48], ap_arr[52],  ap_arr[56],  ap_arr[60]},  0},
 			{ROOK,		{ap_arr[33], ap_arr[37],  ap_arr[41],  ap_arr[45]},  0}
 		}, {
 			{PAWN,		{ap_arr[17], ap_arr[21],  ap_arr[25],  ap_arr[29]},  0},
 			{PAWN,		{ap_arr[16], ap_arr[20],  ap_arr[24],  ap_arr[28]},  0},
 			{PAWN,		{ap_arr[17], ap_arr[21],  ap_arr[25],  ap_arr[29]},  0},
 			{PAWN,		{ap_arr[16], ap_arr[20],  ap_arr[24],  ap_arr[28]},  0},
			{PAWN,		{ap_arr[17], ap_arr[21],  ap_arr[25],  ap_arr[29]},  0},
 			{PAWN,		{ap_arr[16], ap_arr[20],  ap_arr[24],  ap_arr[28]},  0},
 			{PAWN,		{ap_arr[17], ap_arr[21],  ap_arr[25],  ap_arr[29]},  0},
 			{PAWN,		{ap_arr[16], ap_arr[20],  ap_arr[24],  ap_arr[28]},  0},
 		}, {
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
		}, {
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
		}, {
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
		}, {
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
			{VOID,		{ap_arr[1],  ap_arr[5],   ap_arr[9],   ap_arr[13]},  0},
			{VOID,		{ap_arr[0],  ap_arr[4],   ap_arr[8],   ap_arr[12]},  0},
		}, {
 			{PAWN,		{ap_arr[18], ap_arr[22],  ap_arr[26],  ap_arr[30]},  1},
 			{PAWN,		{ap_arr[19], ap_arr[23],  ap_arr[27],  ap_arr[31]},  1},
 			{PAWN,		{ap_arr[18], ap_arr[22],  ap_arr[26],  ap_arr[30]},  1},
 			{PAWN,		{ap_arr[19], ap_arr[23],  ap_arr[27],  ap_arr[31]},  1},
 			{PAWN,		{ap_arr[18], ap_arr[22],  ap_arr[26],  ap_arr[30]},  1},
 			{PAWN,		{ap_arr[19], ap_arr[23],  ap_arr[27],  ap_arr[31]},  1},
 			{PAWN,		{ap_arr[18], ap_arr[22],  ap_arr[26],  ap_arr[30]},  1},
 			{PAWN,		{ap_arr[19], ap_arr[23],  ap_arr[27],  ap_arr[31]},  1},
		}, {
 			{ROOK,		{ap_arr[35], ap_arr[39],  ap_arr[43],  ap_arr[47]},  1},
 			{KNIGHT,	{ap_arr[50], ap_arr[54],  ap_arr[58],  ap_arr[62]},  1},
 			{BISHOP,	{ap_arr[67], ap_arr[71],  ap_arr[75],  ap_arr[79]},  1},
 			{QUEEN,		{ap_arr[82], ap_arr[86],  ap_arr[90],  ap_arr[94]},  1},
			{KING,		{ap_arr[99], ap_arr[103], ap_arr[107], ap_arr[111]}, 1},
 			{BISHOP,	{ap_arr[66], ap_arr[70],  ap_arr[74],  ap_arr[78]},  1},
 			{KNIGHT,	{ap_arr[51], ap_arr[55],  ap_arr[59],  ap_arr[63]},  1},
 			{ROOK,		{ap_arr[34], ap_arr[38],  ap_arr[42],  ap_arr[46]},  1}	
		}
	};
	print_chessboard(chessboard);
	return 0;
}
