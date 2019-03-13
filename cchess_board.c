/*
 *	File:	cchess_board.c
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

bool is_on_the_white_spot(int y, int x)
{
	return (y + x) % 2 == 0;
}

bool is_ally(int y0, int x0, int y1, int x1)
{
	return chessboard[y0][x0].iswhite == chessboard[y1][x1].iswhite;
}

int move_cpiece(int y_src, int x_src, int y_dst, int x_dst, bool turn)
{
	if( !is_correct_move(y_src, x_src, y_dst, x_dst))
		return 1;

	printf("%X", turn);
//	if (check(turn) && !check_prevented(y_dst, x_dst, turn))
//		return 2;

//	if (wrong_players_turn(y_src, x_src))
//		return 3;	

	chessboard[y_dst][x_dst] = chessboard[y_src][x_src];
	
	chessboard[y_src][x_src].type = VOID;
	chessboard[y_src][x_src].iswhite = 0;

	if (is_on_the_white_spot(y_src, x_src) && 
	    !is_on_the_white_spot(y_dst, x_dst) ) {

		chessboard[y_dst][x_dst].ap_index += 1; 
		chessboard[y_src][x_src].ap_index = 0;

	} else if (!is_on_the_white_spot(y_src, x_src) && 
	    	   is_on_the_white_spot(y_dst, x_dst) ) {

		chessboard[y_dst][x_dst].ap_index -= 1; 
		chessboard[y_src][x_src].ap_index = 1;

	} else if (!is_on_the_white_spot(y_src, x_src) && 
	    	   !is_on_the_white_spot(y_dst, x_dst) ) {

		chessboard[y_src][x_src].ap_index = 1;

	} else if (is_on_the_white_spot(y_src, x_src) && 
	    	   is_on_the_white_spot(y_dst, x_dst) ) {

		chessboard[y_src][x_src].ap_index = 0;
	}

//	if (pawn_can_transform())
//		transform_pawn();

	return 0;
}
