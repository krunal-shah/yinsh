#include "Solver.h"
#include "Util.h"

Solver::Solver(int player_id, int board_size, int time_limit)
{
    current_board = new Board();
    turns = 1;
}

Solver::Solver(Solver* base_solver)
{
    turns = base_solver->turns;
    Board* new_board = new Board(base_solver->current_board);
    current_board = new_board;
}


// Add constructor to copy a board : Krunal(Done)
// Given a position and a direction, return possible end positions: Aakash
// Basic 5 window return moves and scores : Krunal


string Solver::move()
{
	if(current_board->no_my_rings() < 5)
	{
		int a = turns, b = 0;
		turns++;
		int polarity = 1;
		Ring* new_ring = new Ring(a, b, polarity);

		// current_board->filled_pos[100*a + b] = 1;
		current_board->add_ring(new_ring);
		
		string move_str = "P " + to_string(a) + " " + to_string(b) + " \n";
		return move_str;
	}
	else
	{

	}

	// Block opp move in 1 move: Aakash
	return "P 10 10\n";
}

void Solver::make_opp_move(string move_str)
{
	vector< pair< string, pair< int, int> > > moves;
	moves = fill_moves(move_str);
	for(auto move:moves)
	{	
		int a = move.second.first;
		int b = move.second.second;
		string mtype = move.first;
		if(mtype == 'P')
		{
			int polarity = 0;
			Ring* new_ring = new Ring(a, b, polarity);

			// filled_pos[100*a + b] = 0;
			current_board->add_ring(new_ring);
		}
		else if(move[0] == 'S')
		{
			int polarity = 0;
			Ring* new_ring = new Ring(a, b, polarity);

			// filled_pos[100*a + b] = 0;
			current_board->add_ring(new_ring);
		}
	}
}