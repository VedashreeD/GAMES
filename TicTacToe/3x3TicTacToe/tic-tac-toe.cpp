#include <iostream> 
#include<vector>
  
//Function to draw the  board 
void drawBoard(std::vector<std::vector<char>> board) 
{ 
    std::cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<std::endl;
    std::cout<<"----------"<<std::endl;
    std::cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<std::endl;
    std::cout<<"----------"<<std::endl;
    std::cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<std::endl;
} 

//Function to check if the player won
bool check(std::vector<std::vector<char>> board, char player) 
{ 
   
    for (int i = 0; i < 3; i++) 
    { 
        //check all rows for a win
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) 
            return true; 
        //check all cols for a win
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) 
            return true; 
    }
    //check the diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) 
        return true; 
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) 
        return true; 
    //if the player didn't win, return false
    return false; 
} 
  
int main() 
{ 
    // Initialize the board and players 
    std::vector<std::vector<char>> board = { 
                         {'1', '2', '3'}, 
                         {'4', '5', '6'}, 
                         {'7', '8', '9'} }; 
    char player = 'X'; 
    int row = 0, col = 0;
  
    std::cout << "Let's play!"<<std::endl; 
  
    //for each turn from 0-9 i.e., there are 9 slots to be filled, so we take 9 turns
    for (int turn = 1; turn <= 9; turn++) 
    { 
        // Draw the board before each turn 
        drawBoard(board); 

        //if the turn is valid and above 0, get the user input
        while(1) 
        { 
            int num = 0;
            std::cout << "Player " << player << ", Enter a number from 1-9 : ";
            std::cin>>num; 
            switch(num)
            {
                case 1 :row = 0, col = 0;
                        break;
                case 2 :row = 0, col = 1;
                        break;
                case 3 :row = 0, col = 2;
                        break;
                case 4 :row = 1, col = 0;
                        break;
                case 5 :row = 1, col = 1;
                        break;
                case 6 :row = 1, col = 2;
                        break;
                case 7 :row = 2, col = 0;
                        break;
                case 8 :row = 2, col = 1;
                        break;
                case 9 :row = 2, col = 2;
                        break;
                default :std::cout<<"Invalid character, "<<std::endl;
                        break;
            } 
            //if position is filled, retry
            if (board[row][col] == 'X' || board[row][col] == 'O')
            { 
                std::cout << "This poistion is already filled, "; 
            } 
            //valid number entered
            else { 
                break; 
            } 
        } 

        //assign position to player
        board[row][col] = player; 
        //if the player won, exit the game
        if (check(board, player)) 
        { 
            drawBoard(board); 
            std::cout << "Player " << player << " wins, Congratulations!"<<std::endl; 
            break;
        }

        // Switch to the other player 
        player = (player == 'X') ? 'O' : 'X'; 
    }   
    // Check for a draw 
    if (!check(board, 'X') && !check(board, 'O')) { 
        std::cout << "It's a draw!"<<std::endl; 
    } 
  
    return 0; 
}
