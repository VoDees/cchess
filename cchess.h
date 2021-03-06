/*
 * Author:	VoDees
 * File:	cchess.h
 * Use:
 *   "     a       b       c       d       e       f       g       h     "
 *   " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 *   " | #   # |''#####|   #   |'#'#'#'|   #   |'''#'''|  #####|'#'''#'| "
 *   " | ##### |'##''##| ##### |'#####'| ##### |'#####'| ##  ##|'#####'| "
 *   "8|  ###  |''''##'|  ###  |''###''|   #   |''###''|    ## |''###''|8"
 *   " |  ###  |'''###'|  ###  |'#####'| ##### |''###''|   ### |''###''| "
 *   " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 *   " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 *   " |'''#'''|   #   |'''#'''|   #   |'''#'''|   #   |'''#'''|   #   | "
 *   "7|'#####'| ##### |'#####'| ##### |'#####'| ##### |'#####'| ##### |7"
 *   " |''###''|  ###  |''###''|  ###  |''###''|  ###  |''###''|  ###  | "
 *   " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 *   " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 *   " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 *   "6|       |'''''''|       |'''''''|       |'''''''|       |'''''''|6"
 *   " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 *   " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 *   " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 *   " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 *   "5|'''''''|       |'''''''|       |'''''''|       |'''''''|       |5"
 *   " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 *   " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 *   " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 *   " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 *   "4|       |'''''''|       |'''''''|       |'''''''|       |'''''''|4"
 *   " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 *   " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 *   " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 *   " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 *   "3|'''''''|       |'''''''|       |'''''''|       |'''''''|       |3"
 *   " |'''''''|       |'''''''|       |'''''''|       |'''''''|       | "
 *   " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 *   " |       |'''''''|       |'''''''|       |'''''''|       |'''''''| "
 *   " |   O   |'''O'''|   O   |'''O'''|   O   |'''O'''|   O   |'''O'''| "
 *   "2| OOOOO |'OOOOO'| OOOOO |'OOOOO'| OOOOO |'OOOOO'| OOOOO |'OOOOO'|2"
 *   " |  OOO  |''OOO''|  OOO  |''OOO''|  OOO  |''OOO''|  OOO  |''OOO''| "
 *   " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 *   " |'O'''O'|  OOOOO|'''O'''| O O O |'''O'''|   O   |''OOOOO| O O O | "
 *   " |'OOOOO'| OO  OO|'OOOOO'| OOOOO |'OOOOO'| OOOOO |'OO''OO| OOOOO | "
 *   "1|''OOO''|    OO |''OOO''|  OOO  |'''O'''|  OOO  |''''OO'|  OOO  |1"
 *   " |''OOO''|   OOO |''OOO''| OOOOO |'OOOOO'|  OOO  |'''OOO'|  OOO  | "
 *   " +-------+-------+-------+-------+-------+-------+-------+-------+ "
 *   "     a       b       c       d       e       f       g       h     "
 *
 */

#include <stdio.h>
#include <stdlib.h>
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
	char ap_index;
	bool iswhite;
};

extern struct cpiece chessboard[8][8];

/*	functions are implemented in modules cchess_XXX.c		*/

//////////////////////////////////////////////////////////////////////////
//	console functions 

void print_chessboard();

int parse_move(char *src, char *dst, int *y_src, int *x_src, int *y_dst,
							int *x_dst);

//////////////////////////////////////////////////////////////////////////
//	functions for using chessboard 

bool is_on_the_white_spot(int y, int x);

int move_cpiece(int y_src, int x_src, int y_dst, int x_dst, bool turn);

bool is_ally(int y0, int x0, int y1, int x1);

//////////////////////////////////////////////////////////////////////////
//	functions that define chess rules

bool pawn_is_cm(int y_src, int x_src, int y_dst, int x_dst);

bool rook_is_cm(int y_src, int x_src, int y_dst, int x_dst);

bool knight_is_cm(int y_src, int x_src, int y_dst, int x_dst);

bool bishop_is_cm(int y_src, int x_src, int y_dst, int x_dst);

bool queen_is_cm(int y_src, int x_src, int y_dst, int x_dst);

bool king_is_cm(int y_src, int x_src, int y_dst, int x_dst);

bool is_correct_move(int y_src, int x_src, int y_dst, int x_dst);

//////////////////////////////////////////////////////////////////////////
//	check functions

bool check(bool king_iswhite);

bool check_mate(bool king_iswhite);

void can_reach(int y, int x, bool (*can_be_reached)[8]);

bool check_prevented(int king_y, int king_x, bool king_iswhite);
