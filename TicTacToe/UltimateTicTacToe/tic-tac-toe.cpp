#include <iostream> 
#include <vector>

// Function to draw the Tic-Tac-Toe board 
void drawBoard(std::vector<std::vector<std::string>> board) 
{ 
    std::cout <<"----------------------------------"<<std::endl; 
    for (int i = 0; i < board.size(); i++) 
    { 
        std::cout << "| "; 
        for (int j = 0; j < board[0].size(); j++) 
        { 
            std::cout << board[i][j] << " | "; 
        } 
        std::cout << "\n--------------------------------------"<<std::endl; 
    } 
} 


bool checkDraw(std::vector<std::vector<std::string>> board, int row = 0, int col = 0)
{
    while(row%3 != 0)
    {
        row--;
    }
    int startRow = row;
    
    while(col%3 != 0)
    {
        col--;
    }
    int startCol = col;
    int count = 0;

    return (count == 8 || count == 9);
}

//check for a win or draw
bool checkWin(std::vector<std::vector<std::string>> board, std::string player, int row = 0, int col = 0) 
{ 
    while(row%3 != 0)
    {
        row--;
    }
    int startRow = row;
    
    while(col%3 != 0)
    {
        col--;
    }
    int startCol = col;
    std::cout<<startRow<<" "<<startCol<<std::endl;
    for(int i = startRow; i < startRow+3; i++)
    {
        //check all the rows
        if(board[i][startCol] == player && board[i][startCol+1] == player && board[i][startCol+2] == player)
        {
            return true;
        }
    }
    for(int i = startCol; i < startCol+3; i++)
    {
        //check all the cols
        if(board[startRow][i] == player && board[startRow+1][i] == player && board[startRow+2][i] == player)
        {
            return true;
        }
    }
    //check all the diagonals for a win
    if(board[startRow][startCol] == player && board[startRow+1][startCol+1] == player && board[startRow+2][startCol+2] == player)
    {
        return true;
    }
    if(board[startRow][startCol+2] == player && board[startRow+1][startCol+1] == player && board[startRow+2][startCol] == player)
    {
        return true;
    }
    //check for a draw
    int count = 0;
    for(int i = startRow; i < startRow+3; i++)
    {
        for(int j = startCol; j < startCol+3; j++)
        {
            if(board[i][j] == " X " || board[i][j] == " O " || board[i][j] == "XO ")
            {
                count++;
            }
        }
    }
    return (count == 9);

} 
  
int main() 
{ 
    // Initialize the board
    std::vector<std::vector<std::string>> board = { 
                         { "001", "011", "021", "032", "042", "052", "063", "073", "083"}, 
                         { "101", "111", "121", "132", "142", "152", "163", "173", "183"}, 
                         { "201", "211", "221", "232", "242", "252", "263", "273", "283"},
                         { "304", "314", "324", "335", "345", "355", "366", "376", "386"}, 
                         { "404", "414", "424", "435", "445", "455", "466", "476", "486"}, 
                         { "504", "514", "524", "535", "545", "555", "566", "576", "586"},
                         { "607", "617", "627", "638", "648", "658", "669", "679", "689"}, 
                         { "707", "717", "727", "738", "748", "758", "769", "779", "789"}, 
                         { "807", "817", "827", "838", "848", "858", "869", "879", "889"}}; 
    std::vector<std::vector<std::string>> final_board = { 
                         { "   ", "   ", "   "}, 
                         { "   ", "   ", "   "}, 
                         { "   ", "   ", "   "} }; 
    //start with player X
    std::string player = " X "; 
    //row and col inside the final board
    int row = 0, col = 0; 
    //contains the matrix number in the board
    int matrix = 0;
    //row and col inside the board
    int r = 0, c = 0;
  
    std::cout<<"Let's play!"<<std::endl; 
  
    //for each turn from 0-9 i.e., there are 9 slots to be filled, so we take 9 turns
    for (int turn = 0; turn < 81; turn++) 
    { 
        drawBoard(board); 
        drawBoard(final_board);

        //if the turn is valid and above 0, get the user input
        while(true) 
        {
            int num = 0;
            std::cout << "Player " << player << ", Enter the index number and the matrix number from 1-9: ";
            std::cin>>num;
            matrix = num%10;
            num = num/10;
            c = num%10;
            num = num/10;
            r = num%10;
            //for matrix, gives the index in the final matrix
            switch(matrix)
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
                default :std::cout<<"Invalid number, "<<std::endl;
                        break;
            }             
            if(final_board[row][col] == " X " || final_board[row][col] == " O " || final_board[row][col] == "XO ")
            {
                std::cout<<"the matrix "<<matrix<<" is complete, try again!"<<std::endl;
                continue;
            }

            //if position is filled, retry
            if (board[r][c] == " X " || board[r][c] == " O ")
            { 
                std::cout<<"This position is filled, "; 
            } 
            else 
            { 
                break; 
            } 
        }

        //assign position to player
        board[r][c] = player; 
        //if the player won, check if player won the final game
        //if not, check if final game is a draw
        if(checkWin(board, player, r, c))
        {
            final_board[row][col] = player;
            if(checkWin(final_board, player))
            {
                drawBoard(board); 
                std::cout << "Player " << player << " wins, Congratulations!"<<std::endl; 
                return 0;
            }
            else
            {
                if(checkDraw(final_board))
                {
                    drawBoard(board);
                    std::cout<<"Its a draw!!!"<<std::endl;
                    return 0;
                }
            }
        }
        else
        {
            //checks if board is a draw
            if(checkDraw(board, r, c))
            {
                //update final board and check if final board is also a draw then exit the loop
                final_board[row][col] = "XO ";
                if(checkDraw(final_board))
                {
                    drawBoard(board);
                    std::cout<<"Its a draw!!!"<<std::endl;
                    return 0;
                }
            }
        }
  
        // Switch to the other player 
        player = (player == " X ") ? " O " : " X "; 
    } 
    return 0; 
}
