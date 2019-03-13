/*
 *	File:	cchess_check.c
 *	Author:	VoDees
 **/

#include "cchess.h"

void can_reach(int y, int x, bool (*can_be_reached)[8])
{
	bool (*is_correct_move)(int, int, int, int);
	fprintf(stderr, "%d %d ER-fuckin'-ROR!\n", y, x);

	switch(chessboard[y][x].type) {
		case KING:
			is_correct_move = king_is_cm;
			break;
		case QUEEN:
			is_correct_move = queen_is_cm;
			break;
		case BISHOP:
			is_correct_move = bishop_is_cm;
			break;
		case KNIGHT:
			is_correct_move = knight_is_cm;
			break;
		case ROOK:
			is_correct_move = rook_is_cm;
			break;
		case PAWN:
			is_correct_move = pawn_is_cm;
			break;
		default:
			fprintf(stderr, "ER-fuckin'-ROR!\n");
			return;
	}

	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			if (is_correct_move(y, x, i, j))
				can_be_reached[i][j] = true;
}

void find_king(int *king_y, int *king_x, bool king_iswhite)
{
	for(int i = 0; i < 8; i++) {		//finding king
		for(int j = 0; j < 8; j++) {
			if (chessboard[i][j].type == KING &&
			    chessboard[i][j].iswhite == king_iswhite) {
				*king_x = j;
				*king_y = i;	
			}
		}
	}

	if (*king_y == -1 || *king_x == -1) {
		fprintf(stderr, "No king over there :shrug:\n");
		*king_x = 0;
		*king_y = 0;	
		return;	
	}
}

bool check(bool king_iswhite)
{
	bool	king_cannot_be_here[8][8] = {0};
	int	king_y = -1;
	int	king_x = -1;

	find_king(&king_y, &king_x, king_iswhite);

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if (chessboard[i][j].iswhite != king_iswhite &&
			    chessboard[i][j].type != VOID)
				// king cannot be where enemy can reach
				can_reach(i, j, king_cannot_be_here);
		}
	}

	return king_cannot_be_here[king_x][king_y];
}

bool check_prevented(int king_y, int king_x, bool king_iswhite)
{
	bool king_cannot_be_here[8][8] = {0};
	struct cpiece ctrl_board[8][8];
	int lking_y = -1;
	int lking_x = -1;

	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			ctrl_board[i][j] = chessboard[i][j];

	find_king(&lking_y, &lking_x, king_iswhite);

	ctrl_board[lking_y][lking_x].type = VOID;
	ctrl_board[lking_y][lking_x].iswhite = false;

	ctrl_board[king_y][king_x].type = KING;
	ctrl_board[king_y][king_x].iswhite = king_iswhite;

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if (ctrl_board[i][j].iswhite != king_iswhite &&
			    ctrl_board[i][j].type != VOID)
				// king cannot be where enemy can reach
				can_reach(i, j, king_cannot_be_here);
		}
	}

	return !king_cannot_be_here[king_x][king_y];
}


bool check_mate(bool king_iswhite)
{
	bool	king_cannot_go_there[8][8] = {0};
	bool	king_can_reach[8][8] = {0};
	int	king_x = -1;
	int	king_y = -1;

	find_king(&king_y, &king_x, king_iswhite);

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if (chessboard[i][j].iswhite == king_iswhite)
				// king cannot step on his allys	
				king_cannot_go_there[i][j] = true;
			if (chessboard[i][j].iswhite != king_iswhite &&
			    chessboard[i][j].type != VOID)
				// king cannot go to where enemy can reach
				can_reach(i, j, king_cannot_go_there);
		}
	}

	/* find a place where the king can go */
	can_reach(king_x, king_y, king_can_reach);
	
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			if (king_can_reach[i][j] &&
			    !king_cannot_go_there[i][j])
				return false;

	return true;
}
