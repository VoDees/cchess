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

bool pawn_is_cm(int x_src, int y_src, int x_dst, int y_dst)
{
	if (chessboard[x_src][y_src].iswhite) {
		if (y_src > y_dst)
			// pawn has to go forward (ALWAYS)
			return false;

		if (x_src == x_dst) {
			if ( y_dst == 4 &&
			     y_src == 6	&&
			     chessboard[x_src][y_src - 1].type == VOID &&
			     chessboard[x_src][y_src - 2].type == VOID )
			//first step by 2 boxes
				return true;	
			else if ( y_src - y_dst == 1 &&
			          chessboard[x_src][y_src - 1].type == VOID )
			// normal step
				return true;
		} else if (x_src - x_dst == 1 && 	// attack
			   y_src - y_dst == 1 &&
	   	   	   chessboard[x_dst][y_dst].type != VOID) {
			return true;
		} else if (x_src - x_dst == -1 &&	// attack
			   y_src - y_dst == 1 &&
			   chessboard[x_dst][y_dst].type != VOID) {
			return true;
		}
	} else {
		if (y_src < y_dst)
			// pawn has to go forward (ALWAYS)
			return false;

		if (x_src == x_dst) {
			if ( y_dst == 1 &&
			     y_src == 3	&&
			     chessboard[x_src][y_src + 1].type == VOID &&
			     chessboard[x_src][y_src + 2].type == VOID )
			//first step by 2 boxes
				return true;	
			else if ( y_src - y_dst == -1 &&
			          chessboard[x_src][y_src + 1].type == VOID )
			// normal step
				return true;
		} else if (x_src - x_dst == 1 && 	// attack
			   y_src - y_dst == -1 &&
	   	   	   chessboard[x_dst][y_dst].type != VOID) {
			return true;
		} else if (x_src - x_dst == -1 &&	// attack
			   y_src - y_dst == -1 &&
			   chessboard[x_dst][y_dst].type != VOID) {
			return true;
		}
	}

	return false;
}

bool rook_is_cm(int x_src, int y_src, int x_dst, int y_dst)
{
	return ((x_src + y_src + x_dst + y_dst) << 31) >> 31;
}

bool knight_is_cm(int x_src, int y_src, int x_dst, int y_dst)
{
	return ((x_src + y_src + x_dst + y_dst) << 31) >> 31;
}

bool bishop_is_cm(int x_src, int y_src, int x_dst, int y_dst)
{
	return ((x_src + y_src + x_dst + y_dst) << 31) >> 31;
}

bool queen_is_cm(int x_src, int y_src, int x_dst, int y_dst)
{
	return ((x_src + y_src + x_dst + y_dst) << 31) >> 31;
}

bool king_is_cm(int x_src, int y_src, int x_dst, int y_dst)
{
	return ((x_src + y_src + x_dst + y_dst) << 31) >> 31;
}

bool is_correct_move(int x_src, int y_src, int x_dst, int y_dst)
{
	switch (chessboard[x_src][y_src].type) {
		case VOID:
			return false;
		case PAWN:
			return pawn_is_cm(x_src, y_src, x_dst, y_dst);
		case ROOK:
			return rook_is_cm(x_src, y_src, x_dst, y_dst);
		case KNIGHT:
			return knight_is_cm(x_src, y_src, x_dst, y_dst);
		case BISHOP:
			return bishop_is_cm(x_src, y_src, x_dst, y_dst);
		case QUEEN:
			return queen_is_cm(x_src, y_src, x_dst, y_dst);
		case KING:
			return king_is_cm(x_src, y_src, x_dst, y_dst);
		default:
			fprintf(stderr, "WHOOPSY.. something went wrong xd\n");
			return false;
	}

	return true;
}


int move_cpiece(int x_src, int y_src, int x_dst, int y_dst)
{

	if( !is_correct_move(x_src, y_src, x_dst, y_dst))
		return 2;

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
