/*
 *	File:	cchess_logic.c
 *	Author:	VoDees
 */
#include "cchess.h" 

struct cpiece chessboard [8][8] = {
{
	{ROOK,		32,  0},
	{KNIGHT,	49,  0},
	{BISHOP,	64,  0},
	{QUEEN,		81,  0},
	{KING,		96,  0},
	{BISHOP,	65,  0},
	{KNIGHT,	48,  0},
	{ROOK,		33,  0}
}, {
	{PAWN,		17,  0},
	{PAWN,		16,  0},
	{PAWN,		17,  0},
	{PAWN,		16,  0},
	{PAWN,		17,  0},
	{PAWN,		16,  0},
	{PAWN,		17,  0},
	{PAWN,		16,  0},
}, {
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
}, {                        
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
}, {                        
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
}, {                        
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
	{VOID,		1,   0},
	{VOID,		0,   0},
}, {
	{PAWN,		18,  1},
	{PAWN,		19,  1},
	{PAWN,		18,  1},
	{PAWN,		19,  1},
	{PAWN,		18,  1},
	{PAWN,		19,  1},
	{PAWN,		18,  1},
	{PAWN,		19,  1},
}, {
	{ROOK,		35,  1},
	{KNIGHT,	50,  1},
	{BISHOP,	67,  1},
	{QUEEN,		82,  1},
	{KING,		99 , 1},
	{BISHOP,	66,  1},
	{KNIGHT,	51,  1},
	{ROOK,		34,  1}	
}
};

bool is_on_the_white_spot(int x, int y)
{
	return (x + y) % 2 == 0;
}

int move_cpiece(int x_src, int y_src, int x_dst, int y_dst)
{
	if ( (0 > x_src || 7 < x_src) ||
	     (0 > x_dst || 7 < x_dst) ||
	     (0 > y_src || 7 < y_src) ||
	     (0 > y_dst || 7 < y_dst) ) 
		return 1;

	chessboard[x_dst][y_dst] = chessboard[x_src][y_src];

	chessboard[x_src][y_src].type = VOID;
	chessboard[x_src][y_src].iswhite = 0;

	if (is_on_the_white_spot(x_src, y_src) && 
	    !is_on_the_white_spot(x_dst, y_dst) ) {

		chessboard[x_dst][y_dst].ap_index += 1; 
		chessboard[x_src][y_src].ap_index = 0;

	} else if (!is_on_the_white_spot(x_src, y_src) && 
	    	   is_on_the_white_spot(x_dst, y_dst) ) {

		chessboard[x_dst][y_dst].ap_index -= 1; 
		chessboard[x_src][y_src].ap_index = 1;

	} else if (!is_on_the_white_spot(x_src, y_src) && 
	    	   !is_on_the_white_spot(x_dst, y_dst) ) {

		chessboard[x_src][y_src].ap_index = 1;

	} else if (is_on_the_white_spot(x_src, y_src) && 
	    	   is_on_the_white_spot(x_dst, y_dst) ) {

		chessboard[x_src][y_src].ap_index = 0;

	}
	return 0;
}
