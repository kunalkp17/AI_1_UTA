#include<stdio.h>
#include <stdlib.h> 
#include<string>
#include<conio.h>
#include<iostream>
#include<fstream>
#include <time.h>

using namespace std;



int checkBoardPlayable(int board[6][7])
{
	int flagPlayable = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == 0)
			{
				flagPlayable = 1;
			}
		}
	}

	return flagPlayable;

}

void printBoard(int board[6][7])
{
	for (int i = 0; i < 6; i++)
	{

		for (int j = 0; j < 7; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}

}
int scoreOfGame(int board[6][7], int player)
{
	int score = 0;
	//vertical check

	for (int i = 0; i < 7; i++)
	{

		for (int j = 0; j<3; j++)
		{
			if (board[j][i] == player && board[j + 1][i] == player && board[j + 2][i] == player && board[j + 3][i] == player)
			{
				score++;
			}
		}
	}


	//horizontal check

	for (int i = 0; i < 6; i++)
	{

		for (int j = 0; j<4; j++)
		{
			if (board[i][j] == player &&board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player)
			{
				score++;
			}
		}
	}

	

	//diagonal check
	if (board[2][0] == player && board[3][1] == player
		&& board[4][2] == player && board[5][3] == player)
	{
		score++;
	}
	if (board[1][0] == player &&  board[2][1] == player
		&& board[3][2] == player && board[4][3] == player)
	{
		 score++;
	}
	if (board[2][1] == player && board[3][2] == player
		&& board[4][3] == player && board[5][4] == player)
	{
		score++;
	}
	if ( board[0][0] == player &&  board[1][1] == player
		&&  board[2][2] == player &&  board[3][3] == player)
	{
		 score++;
	}
	if ( board[1][1] == player &&  board[2][2] == player
		&&  board[3][3] == player &&  board[4][4] == player)
	{
		 score++;
	}
	if ( board[2][2] == player &&  board[3][3] == player
		&&  board[4][4] == player &&  board[5][5] == player)
	{
		 score++;
	}
	if ( board[0][1] == player &&  board[1][2] == player
		&&  board[2][3] == player &&  board[3][4] == player)
	{
		 score++;
	}
	if ( board[1][2] == player &&  board[2][3] == player
		&&  board[3][4] == player &&  board[4][5] == player)
	{
		 score++;
	}
	if ( board[2][3] == player &&  board[3][4] == player
		&&  board[4][5] == player &&  board[5][6] == player)
	{
		 score++;
	}
	if ( board[0][2] == player &&  board[1][3] == player
		&&  board[2][4] == player &&  board[3][5] == player)
	{
		 score++;
	}
	if ( board[1][3] == player &&  board[2][4] == player
		&&  board[3][5] == player &&  board[4][6] == player)
	{
		 score++;
	}
	if ( board[0][3] == player &&  board[1][4] == 1
		&&  board[2][5] == player &&  board[3][6] == player)
	{
		 score++;
	}

	if ( board[0][3] == player &&  board[1][2] == player
		&&  board[2][1] == player &&  board[3][0] == player)
	{
		 score++;
	}
	if ( board[0][4] == player &&  board[1][3] == player
		&&  board[2][2] == player &&  board[3][1] == player)
	{
		 score++;
	}
	if ( board[1][3] == player &&  board[2][2] == player
		&&  board[3][1] == player &&  board[4][0] == player)
	{
		 score++;
	}
	if ( board[0][5] == player &&  board[1][4] == player
		&&  board[2][3] == player &&  board[3][2] == player)
	{
		 score++;
	}
	if ( board[1][4] == player &&  board[2][3] == player
		&&  board[3][2] == player &&  board[4][1] == player)
	{
		 score++;
	}
	if ( board[2][3] == player &&  board[3][2] == player
		&&  board[4][1] == player &&  board[5][0] == player)
	{
		 score++;
	}
	if ( board[0][6] == player &&  board[1][5] == player
		&&  board[2][4] == player &&  board[3][3] == player)
	{
		 score++;
	}
	if ( board[1][5] == player &&  board[2][4] == player
		&&  board[3][3] == player &&  board[4][2] == player)
	{
		 score++;
	}
	if ( board[2][4] == player &&  board[3][3] == player
		&&  board[4][2] == player &&  board[5][1] == player)
	{
		 score++;
	}
	if ( board[1][6] == player &&  board[2][5] == player
		&&  board[3][4] == player &&  board[4][3] == player)
	{
		 score++;
	}
	if ( board[2][5] == player &&  board[3][4] == player
		&&  board[4][3] == player &&  board[5][2] == player)
	{
		 score++;
	}
	if (board[2][6] == player && board[3][5] == player
		&& board[4][4] == player &&  board[5][3] == player)
	{
		score++;
	}






	//inverse diagonal check


	return score;
}
int maxDepthOfTree;


int row_max; int col_max;
int minmax(int board[6][7], int depth, int flagMaxplayer, int alpha, int beta, int player)
{
	int row = 0; int col = 0; 
	
	if ((depth == maxDepthOfTree))//||(board[5][0] != board[5][1] != board[5][2] != board[5][3] != board[5][4] != board[5][5] != board[5][6] != 0))
	{
		
		return scoreOfGame(board, player);
	}
	  if (flagMaxplayer == 1) 
	 {
		  
		int moveslist[7][2]; int moves = 0;
		int bestVal = -999999;
		for (int col = 0; col < 7; col++)
		{
			for (int row = 5; row >=0; row--)
			{
				
				if (board[row][col] == 0 )
				{
					if (row == 5 || board[row + 1][col] != 0)
					{

						moveslist[moves][0] = row;
						moveslist[moves][1] = col;
						moves++;
						break;
					}
				}

			}
		}
		for (int i = 0; i < moves; i++)
		{
			row = moveslist[i][0];
			col = moveslist[i][1];
			
			board[row][col] = player;
			player = (player == 1 )? 2 : 1;
			
			
			int value = minmax(board, depth + 1, 0, alpha, beta, player);
			board[row][col] = 0;


			if (bestVal < value)
			{
				
				bestVal = value;

				row_max = row;
				col_max = col;


			}
			
			alpha = alpha>bestVal ? alpha : bestVal;
			if (beta <= alpha)
			{

				break;
			}
		}
		return bestVal;
	 }


			
			
	else
	{

		int moveslist[7][2]; int moves = 0;
		int bestVal = 999999;
		for (int col = 0; col < 7; col++)
		{
			for (int row = 5; row >= 0; row--)
			{
				
					
				if (board[row][col] == 0)
				{
					if (row==5 || board[row+1][col]!=0) 
					{

					moveslist[moves][0] = row;
					moveslist[moves][1] = col;
					moves++;
					row = -1;
					}
					}

				}
			}

			for (int i = 0; i < moves; i++)
			{
				row = moveslist[i][0];
				col = moveslist[i][1];
			board[row][col] = player;
			player = (player == 1) ? 2 : 1;

			int value = minmax(board, depth + 1, 1, alpha, beta, player);
			board[row][col] = 0;
			

			if (bestVal > value)
			{
				bestVal = value;
				
			}

			beta = beta > bestVal ? bestVal : beta;
			if (beta <= alpha)
			{		

				break;
			}
		}
		return bestVal;


		

	}
}






int maxconnect4(string mode, string inputFile, string opFileOrPlayerMove, int depthOfTree)
{
	maxDepthOfTree = depthOfTree;
	int board[6][7];
	int nextPlayer;
	int score1;
	int score2;
	fstream input(inputFile, std::ios::in);
	int line; int count = 0;
	while (input >> line)
	{
		if (count < 6)
		{

			for (int j = 6; j >= 0; j--)
			{
				int temp = line % 10;
				board[count][j] = temp;
				line = line / 10;
			}

		}
		if (count == 6)
		{
			nextPlayer = line;
		}



		count++;
	}

	input.close();



	if (mode == "one-move")
	{

		//Read the input file and initialize the board state and current score, as in interactive mode. already done above as is common
		score1 = scoreOfGame(board, 1);
		score2 = scoreOfGame(board, 2);

		//Print the current board state and score.If the board is full, exit
		printBoard(board);
		cout << "Score for Player 1 :" << score1 << "\n";
		cout << "Score for Player 2 :" << score2 << "\n";

		
		if (checkBoardPlayable(board) == 1)
		{

			//find minmax
			
			int bestValue =	minmax(board,0,1,-99999,99999,nextPlayer);
			cout << row_max << endl << col_max << endl<<bestValue<<endl;

			board[row_max][col_max] = nextPlayer;

			//Print the current board state and score.
			printBoard(board);
			score1 = scoreOfGame(board, 1);
			score2 = scoreOfGame(board, 2);

			cout << "Score for Player 1 :" << score1 << "\n";
			cout << "Score for Player 2 :" << score2 << "\n";

			//Save the current board state to the output file IN EXACTLY THE SAME FORMAT THAT IS USED FOR INPUT FILES.

			fstream output(opFileOrPlayerMove.c_str(), std::ios::out);

			for (int row = 0; row < 6; row++)
			{
				for (int col = 0; col < 7; col++)
				{
					output << board[row][col];
				}
				output << endl;

			}
			int newNextPlayer = nextPlayer == 1 ? 2 : 1;
			output << newNextPlayer;
			output.close();
			//Exit
		}


	}
	if (mode == "interactive")
	{

		while (true)
		{//1  If computer-next, goto 2, else goto 5.
			if (nextPlayer == 2)
			{
				//2  Print the current board state and score. If the board is full, exit.
				score1 = scoreOfGame(board, 1);
				score2 = scoreOfGame(board, 2);
				printBoard(board);
				cout << "Score for Player 1 :" << score1 << "\n";
				cout << "Score for Player 2 :" << score2 << "\n";

				if (checkBoardPlayable(board) == 0)
				{
					return 1;
				}

				// 3  Choose and make the next move.
				///////////////////////////////////
				minmax(board, depthOfTree, 1, -999999, 99999, 2);
				board[row_max][col_max];


				//4  Save the current board state in a file called computer.txt (in same format as input file).
				string inputFileName = "computer.txt";
				fstream output(inputFileName.c_str(), std::ios::out);

				for (int row = 0; row < 6; row++)
				{
					for (int col = 0; col < 7; col++)
					{
						output << board[row][col];
					}
					output << endl;

				}
				int newNextPlayer = nextPlayer == 1 ? 2 : 1;
				output << newNextPlayer;
				output.close();

			}

			else
			{
				//5  Print the current board state and score. If the board is full, exit.
				score1 = scoreOfGame(board, 1);
				score2 = scoreOfGame(board, 2);
				printBoard(board);
				cout << "Score for Player 1 :" << score1 << "\n";
				cout << "Score for Player 2 :" << score2 << "\n";

				if (checkBoardPlayable(board) == 0)
				{
					return 1;
				}
				//6  Ask the human user to make a move (make sure that the move is valid, otherwise repeat request to the user).
				while (true)
				{
					int row; int col;
					cout << "Please enter next location to enter coin/dot\n";
					cout << "Columns are numbered from left to right, with numbers 1, 2, ..., 7. \n Rows are numbered from bottom to top, with numbers 1, 2, ..., 6. \n";
					cout << "Enter Row first then column";
					cin >> row;
					cin >> col;
					row = 6 - row;
					col = col - 1;
					if (row < 6 && col < 7 && col >= 0 && row >= 0)
					{
						if (board[row][col] == 0 && board[row - 1][col] != 0)
						{
							board[row][col] = 1;
							break;
						}
						cout << "Invalid position for the coin/dot. \n Please try again\n";

					}
					cout << "Invalid  location for the coin/dot\n";

				}
				//7  Save the current board state in a file called human.txt (in same format as input file).
				string outputFileName = "human.txt";
				fstream output(outputFileName.c_str(), std::ios::out);

				for (int row = 0; row < 6; row++)
				{
					for (int col = 0; col < 7; col++)
					{
						output << board[row][col];
					}
					output << endl;

				}
				int newNextPlayer = nextPlayer == 1 ? 2 : 1;
				output << newNextPlayer;
				output.close();

			}


			//end of while 
		}


		//end of "mode" if 
	}



	return 1;
}
int main()
{
	
	maxconnect4("one-move", "input1.txt", 
		"op.txt",20);
	
	return 1;
}
