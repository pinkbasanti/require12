

#include<iostream>
#include<vector>
using namespace std;


//function to print the solution
void printSolution(vector<vector<int>> &board)
{
    // static int k = 1;
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

//function to check if a queen can be placed on board[row][col]
//Note that this function is called when "col" queens are already placed in columns from 0 to col -1
//So we need to check only left side for attacking queens
bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int i, j;

    //check this row on left side
    for(i=0;i<col;i++)
        if(board[row][i])
            return false;

    //check upper diagonal on left side
    for(i=row, j=col;i>=0 && j>=0;i--, j--)
        if(board[i][j])
            return false;

    //check lower diagonal on left side
    for(i=row, j=col;i<board.size() && j>=0;i++, j--)
        if(board[i][j])
            return false;

    return true;
}

//function to solve N Queen problem
bool solveNQueen(vector<vector<int>> &board, int col)
{
    //if all queens are placed then return true
    if(col >= board.size())
        return true;

    //consider this column and try placing this queen in all rows one by one
    for(int i=0;i<board.size();i++)
    {
        //check if the queen can be placed on board[i][col]
        if(isSafe(board, i, col))
        {
            //place this queen in board[i][col]
            board[i][col] = 1;

            //recur to place rest of the queens
            if(solveNQueen(board, col+1))
                return true;

            //if placing queen in board[i][col] doesn't lead to a solution then remove queen from board[i][col]
            board[i][col] = 0; //backtrack
        }
    }

    //if the queen can not be placed in any row in this column col then return false
    return false;
}



// driver program to test above function 
int main() 
{ 
    int n;
    cout<<"Enter the number of queens: ";
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if(solveNQueen(board, 0) == false)
    {
        cout<<"Solution does not exist";
        return 0;
    }
    else{
        cout<<"Solution for "<<n <<" queen is : \n";
        printSolution(board);
    }

    return 0; 
}