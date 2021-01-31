#include "Game.h"
#include <iostream>
#include <list>
#include <vector>


//This method controls player turns and adds the "X" or "O" to each of the numbered tiles.
void Game::PlayerInput()
{
	int size = 0;
	for (int i = 0; i < board.size(); i++)
		size += board[i].size();
	if (playerOneTurn) //if it is palyer one's turn
	{
		std::cout << std::endl;
		std::cout << "Player 1's Turn! " << std::endl;
		std::cout << std::endl;
		std::cout << "Type in a number or -1 to undo: ";
		std::cin >> num;
	}
	else //if it is player two's turn
	{
		std::cout << std::endl;
		std::cout << "Player 2's Turn! " << std::endl;
		std::cout << std::endl;
		std::cout << "Type in a number or -1 to undo: ";
		std::cin >> num;
	}
	
	if (num == -1) //if the player pressed -1 to undo
	{
		Undo();
		putDown = true;
	}
	if (moveCount == 1)
	{
		//if this is the first time playing the game, push the board to board moves.
		boardMoves.push_back(board);
		
		
	}
	if (std::cin.fail() || num > size || num == 0 || num < -1) //if the user inputed an invalid option
	{

	std::cout << std::endl;
		std::cout << "Invalid input!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		InitBoard(boardMoves.back());
		std::cout << std::endl;
	}
	else
	{
		for (int i = 0; i < boardMoves.back().size(); i++)
		{
			for (int j = 0; j < boardMoves.back()[0].size(); j++)
			{
				if (num == ((int)(boardMoves.back()[i][j]) - 48))
				{
					if (playerOneTurn)
					{
						//Places the player One "X" in the spot they chose
						std::vector<std::vector<char>> newBoard = boardMoves.back();
						newBoard[i][j] = 'X';
						boardMoves.push_back(newBoard);
						playerOneTurn = false;
						
						putDown = true;
						InitBoard(boardMoves.back());
						moveCount++;
						break;
					}
					else
					{
						//Places the player Two "O" in the spot they chose
						std::vector<std::vector<char>> newBoard = boardMoves.back();
						newBoard[i][j] = 'O';
						boardMoves.push_back(newBoard);
						playerOneTurn = true;
					
						putDown = true;
						
						InitBoard(boardMoves.back());
						moveCount++;
						break;
					}
				}

			}
		}
		//checks to see if the player is trying to put something that is already in a spot
		if (!putDown)
		{
		std::cout << std::endl;
			std::cout << "Spot already filled! " << std::endl;
			std::cout << std::endl;
			InitBoard(boardMoves.back());
			//PlayerInput();
			std::cout << std::endl;
		
			
		}
		putDown = false;
		
	}
	
	
}

//Initialize the board
void Game::InitBoard(std::vector<std::vector<char>> arr)
{
	std::cout << "  PLAYER 1 - [X]   PLAYER 2 - [O]        \n" << std::endl;
	std::cout << std::endl;
	int count = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[0].size(); j++)
		{
			
			std::cout << "     " <<  arr[i][j];

		}
		std::cout << std::endl;
	}
}


/*This was an older method that is no longer used for drawing boards that look like a Tic Tac Toe board. For the mnk version I decided
* not to use this method, but it is here for reference.*/
void Game::DrawBoard(std::vector<std::vector<char>> arr)
{
	int count = 0;
	int size = 0;
	for (int i = 0; i < board.size(); i++)
		size += board[i].size();

	int square = sqrt(size);

	std::cout << "  PLAYER 1 - [X]   PLAYER 2 - [O]        \n" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < arr[0].size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			
			if (i == 0 && j == 0)
			{
				std::cout << "          |     |     " << std::endl;
				std::cout << "       " << arr[i][j] << "  |  " << arr[i][j + 1] << "  |  " << arr[i][j + 2] << std::endl;
			}
			else if (i == 1 && j == 0)
			{
				std::cout << "     _____|_____|_____" << std::endl;
				std::cout << "          |     |     " << std::endl;
				std::cout << "       " << arr[i][j] << "  |  " << arr[i][j + 1] << "  |  " << arr[i][j + 2] << std::endl;
			}
			else if ((i == arr[0].size() - 1) && j == 0)
			{
				std::cout << "     _____|_____|_____" << std::endl;
				std::cout << "          |     |     " << std::endl;
				std::cout << "       " << arr[i][j] << "  |  " << arr[i][j + 1] << "  |  " << arr[i][j + 2] << std::endl;
				std::cout << "          |     |     " << std::endl << std::endl << std::endl;
			}
			
			
			
		}
	}

}


//Resets the game
void Game::Reset()
{
	int count = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!boardMoves.empty())
			{
				board[i][j] = static_cast<char>(count + 48);

				count++;
		}
			
		}
	}

	moveCount = 1;
	boardMoves.clear();
}
//Undoes the method
void Game::Undo()
{
	if (moveCount == 1)
	{
	//Checks if the game is already at the beginning
		std::cout << "Invalid undo!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		Reset();
		InitBoard(board);
		
		
	}
	else
	{
		if (playerOneTurn)
		{
			playerOneTurn = false;
		}
		else
		{
			playerOneTurn = true;
		}
		
		moveCount--;
		
		boardMoves.pop_back();
		InitBoard(boardMoves.back());
		std::cin.clear();
		putDown = false;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//PlayerInput();
	}
}

//Test cases to see if the tic tac toe board has reached a game over state.
bool Game::GameOver()
{
	if (!boardMoves.empty())
	{
		if (RowSame(boardMoves.back(), 'X'))
		{
			std::cout << "Player 1 has won the game!" << std::endl;
			return true;
		}
		if (RowSame(boardMoves.back(), 'O'))
		{
			std::cout << "Player 2 has won the game! " << std::endl;
			return true;
		}
		if (ColumnSame(boardMoves.back(), 'X'))
		{
			std::cout << "Player 1 has won the game!" << std::endl;
			return true;
		}
		if (ColumnSame(boardMoves.back(), 'O'))
		{
			std::cout << "Player 2 has won the game! " << std::endl;
			return true;
		}
		if (DiagonalsSame(boardMoves.back(), 'X'))
		{
			std::cout << "Player 1 has won the game!" << std::endl;
			return true;
		}
		if (DiagonalsSame(boardMoves.back(), 'O'))
		{
			std::cout << "Player 2 has won the game! " << std::endl;
			return true;
		}
		for (int i = 0; i < boardMoves.back().size(); i++)
		{
			for (int j = 0; j < boardMoves.back()[0].size(); j++)
			{
				if (boardMoves.back()[i][j] != 'X' && boardMoves.back()[i][j] != 'O')
				{
					return false;
				}
			}
		}
		std::cout << std::endl;
		std::cout << "This game is a draw.";
		return true;
}
	return false;
}

//Checks if the row has the same character "X" or "O"
bool Game::RowSame(std::vector<std::vector<char>> arr, char x)
{ 
	int count;
	int rowNum = arr.size();
	int colNum = arr[0].size();
	if (rowNum < colNum || rowNum == colNum)
	{
		for (int i = 0; i < rowNum; i++)
		{
			count = 0;
			for (int j = 0; j < colNum; j++)
			{

				if (arr[i][j] == x)
				{
					count++;
				}
				if (count == colNum)
				{
					return true;
				}

			}

		}
		return false;
	}
	if (rowNum > colNum)
	{
		for (int i = 0; i < rowNum; i++)
		{
			count = 0;
			for (int j = 0; j < colNum; j++)
			{

				if (arr[i][j] == x)
				{
					count++;
				}
				if (count == colNum)
				{
					return true;
				}

			}

		}
		return false;
	}

}
//Checks if the column has the same character "X" or "O"
bool Game::ColumnSame(std::vector<std::vector<char>> arr, char x)
{
	int count;
	int rowNum = arr.size();
	int colNum = arr[0].size();
	if (rowNum < colNum || rowNum == colNum)
	{
		for (int j = 0; j < colNum; j++)
		{
			count = 0;
			for (int i = 0; i < rowNum; i++)
			{
				
				if (arr[i][j] == x)
				{
					count++;
				}
				if (count == rowNum)
				{
					return true;
				}
				
			}
			
		}
		return false;
	}
	if (rowNum > colNum)
	{
		for (int j = 0; j < colNum; j++)
		{
			count = 0;
			for (int i = 0; i < rowNum; i++)
			{
				
				if (arr[i][j] == x)
				{
					count++;
				}
				if (count == rowNum)
				{
					return true;
				}
				
			}
			
		}
		return false;
		}
		

}
//Checks if the diagonals has the same character "X" or "O"
bool Game::DiagonalsSame(std::vector<std::vector<char>> arr, char x)
{
	int val = 0;
	int count = 0;
	int rowNum = arr.size();
	int colNum = arr[0].size();
	if (rowNum > colNum || rowNum == colNum || colNum > rowNum)
	{
		for (int i = 0; i < rowNum; i++)
		{
			//count = 0;
			if (val < colNum)
			{
				if (arr[i][val] == x)
				{
					count++;
				}
				if (count == colNum)
				{
					return true;
				}
				val++;
			}
			
		}

		val = arr[0].size() - 1;
		count = 0;
		for (int i = 0; i < rowNum; i++)
		{
			if (val >= 0)
			{
				if (arr[i][val] == x)
				{
					count++;
				}
				if (count == colNum)
				{
					return true;
				}
				val--;
			}
			
		}
		return false;
	}
	
}

