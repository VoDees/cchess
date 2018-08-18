/*
 *	File:	cchess_rules.c
 *	Author:	VoDees
 */
#include "cchess.h"

bool pawn_is_cm(int y_src, int x_src, int y_dst, int x_dst)
{
	if (!chessboard[y_src][x_src].iswhite) {
		if (x_src == x_dst) {
			if ( y_dst == 3 &&
			     y_src == 1	&&
			     chessboard[y_src + 1][x_src].type == VOID &&
			     chessboard[y_src + 2][x_src].type == VOID )
		//first step by 2 boxes
				return true;	
			else if ( y_src - y_dst == -1 &&
			          chessboard[y_src + 1][x_src].type == VOID )
			// normal step
				return true;
		} else if (x_src - x_dst == 1 && 	// attack
			   y_src - y_dst == -1 &&
	   	   	   chessboard[y_dst][x_dst].type != VOID &&
			   !is_ally(y_src, x_src, y_dst, x_dst)) {
			return true;
		} else if (x_src - x_dst == -1 &&	// attack
			   y_src - y_dst == -1 &&
			   chessboard[y_dst][x_dst].type != VOID &&
	       		   !is_ally(y_src, x_src, y_dst, x_dst)) {
			return true;
		}
	} else {
		if (x_src == x_dst) {
			if ( y_dst == 4 &&
			     y_src == 6	&&
			     chessboard[y_src - 1][x_src].type == VOID &&
			     chessboard[y_src - 2][x_src].type == VOID )
			//first step by 2 boxes
				return true;	
			else if ( y_src - y_dst == 1 &&
			          chessboard[y_src - 1][x_src].type == VOID )
			// normal step
				return true;
		} else if (x_src - x_dst == 1 && 	// attack
			   y_src - y_dst == 1 &&
			   chessboard[y_dst][x_dst].type != VOID &&
	       		   !is_ally(y_src, x_src, y_dst, x_dst)) {
			return true;
		} else if (x_src - x_dst == -1 &&	// attack
			   y_src - y_dst == 1 &&
			   chessboard[y_dst][x_dst].type != VOID &&
	       		   !is_ally(y_src, x_src, y_dst, x_dst)) {
			return true;
		}
	}

	return false;
}

/* implemeted by KonDee */
bool rook_is_cm(int y_src, int x_src, int y_dst, int x_dst)
{
	if (y_src == y_dst) {		// moving to the left/right
		if (x_src < x_dst) {	// moving right
			for (int i = x_src + 1; i <= x_dst; i++) {
				if (chessboard[y_src][i].type == VOID)
				      continue;
				if (is_ally(y_src, x_src, y_src, i))
					return false;
				if (i != x_dst)		// u are facing an enemy, kill it!!
					return false;
			}
			return true;
		} else if (x_src > x_dst) {	// moving left
			for (int i = x_src - 1; i >= x_dst; i--) {
				if (chessboard[y_src][i].type == VOID)
				      continue;
				if (is_ally(y_src, x_src, y_src, i))
					return false;
				if (i != x_dst)		// u are facing an enemy, kill it!!
					return false;
			}
			return true;
		}
		return false;
	} else if (x_src == x_dst) { 	// moving up or down
		if (y_src < y_dst) {	// moving down
			for (int i = y_src + 1; i <= y_dst; i++) {
				if (chessboard[i][x_src].type == VOID)
				      continue;
				if (is_ally(y_src, x_src, i, x_src))
					return false;
				if (i != y_dst)		// u are facing an enemy, kill it!!
					return false;
			}
			return true;
		} else if (y_src > y_dst) { // moving up
			for (int i = y_src - 1; i >= y_dst; i--) {
				if (chessboard[i][x_src].type == VOID)
				      continue;
				if (is_ally(y_src, x_src, i, x_src))
					return false;
				if (i != y_dst)		// u are facing an enemy, kill it!!
					return false;
			}
			return true;
		}
		return false;
	}

	return false;
}

bool knight_is_cm(int y_src, int x_src, int y_dst, int x_dst)
{
	if ((abs(x_src - x_dst) == 2) && 
	    (abs(y_src - y_dst) == 1)) {
	// horizontal jumps: ,--	'-- 	--, 	--'
		if (chessboard[y_dst][x_dst].type == VOID)
			return true;
		if (is_ally(y_src, x_src, y_dst, x_dst))
			return false;
		else 
			return true;		
	} else if ((abs(x_src - x_dst) == 1) &&
	    	   (abs(y_src - y_dst) == 2)) {
	// vertical jumps: _| 		ˇ| 	|_ 	ˇ|
			if (chessboard[y_dst][x_dst].type == VOID)
				return true;
			if (is_ally(y_src, x_src, y_dst, x_dst))
				return false;
			else 
				return true;	
	} else 
		return false;
	
	
}
/* implemeted by KonDee */
bool bishop_is_cm(int y_src, int x_src, int y_dst, int x_dst)
{
	if ((x_dst - x_src) == (y_dst - y_src)) {
		if (x_dst > x_src) { // moving diagonally down-right
			for (int i = x_src + 1; i <= x_dst; i++) {
				if (chessboard[y_src + (i - x_src)][i].type == VOID)
					continue;
				if (is_ally(y_src, x_src, i, i))
					return false;
				if ((i != x_dst) && (i != y_dst))
					return false;
			} 
			return true;
		} else if (x_dst < x_src) { // moving diagonally up-left
			for (int i = x_src - 1; i >= x_dst; i--) {
				if (chessboard[y_src - (x_src - i)][i].type == VOID)
					continue;
				if (is_ally(y_src, x_src, i, i))
					return false;
				if ((i != x_dst) && (i != y_dst))
					return false;
			}
			return true;
		} 
		return false;
	} else if ((-1 * (x_dst - x_src)) == (y_dst - y_src)) { 
		if ((x_dst < x_src) && (y_dst > y_src)) { // moving diagonally down-left
			for (int i = x_src - 1; i >= x_dst; i--) {
				if (chessboard[y_src + (x_src - i)][i].type == VOID)
					continue;
				if (is_ally(y_src, x_src, y_src + (x_src -i), i))
					return false;
				if ((i != x_dst) && ((y_src + (x_src - i)) != y_dst))
					return false;
			} 
			return true;
		} else if ((x_dst > x_src) && (y_dst < y_src)) { // moving diagonally up-right
			for (int i = x_src + 1; i <= x_dst; i++) {
				if (chessboard[y_src - (i - x_src)][i].type == VOID)
					continue;
				if (is_ally(y_src, x_src, y_src - (i - x_src), i))
					return false;
				if ((i != x_dst) && ((y_src - (i - x_src)) != y_dst))
					return false;
			}
			return true;
		}
		return false;
	}

	return false;
}

bool queen_is_cm(int y_src, int x_src, int y_dst, int x_dst)
{
	return	rook_is_cm(y_src, x_src, y_dst, x_dst) ||
		bishop_is_cm(y_src, x_src, y_dst, x_dst);
}

bool king_is_cm(int y_src, int x_src, int y_dst, int x_dst)
{
	if ( (abs(y_src - y_dst) == 1 ||
	      abs(x_src - x_dst) == 1) &&
	     (!is_ally(y_src, x_src, y_dst, x_dst) || 
	      chessboard[y_dst][x_dst].type == VOID) )
		return true;

	// add castling

	return false;
}

bool is_correct_move(int y_src, int x_src, int y_dst, int x_dst)
{
	switch (chessboard[y_src][x_src].type) {
		case VOID:
			return false;
		case PAWN:
			return pawn_is_cm(y_src, x_src, y_dst, x_dst);
		case ROOK:
			return rook_is_cm(y_src, x_src, y_dst, x_dst);
		case KNIGHT:
			return knight_is_cm(y_src, x_src, y_dst, x_dst);
		case BISHOP:
			return bishop_is_cm(y_src, x_src, y_dst, x_dst);
		case QUEEN:
			return queen_is_cm(y_src, x_src, y_dst, x_dst);
		case KING:
			return king_is_cm(y_src, x_src, y_dst, x_dst);
		default:
			fprintf(stderr, "WHOOPSY.. something went wrong xd\n");
			return false;
	}

	return true;
}
