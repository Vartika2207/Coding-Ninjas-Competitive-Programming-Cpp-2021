#include <bits/stdc++.h>
using namespace std;

int **makeMove(int **board, int x, int y, int player, int isCheck){
    int **newBoard;
    if(isCheck){
        newBoard = board;
    }
    else{
        newBoard = new int*[4];
        for(int i=0; i<4; i++){
            newBoard[i] = new int[4];
            for(int j=0; j<4; j++){
                newBoard[i][j] = board[i][j];
            }
        }
    }
    
    
    int dXdY[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    if(x < 0 || x >= 4 || y < 0 || y >= 4 || board[x][y] != 0)
        return nullptr;
    
    bool possibleMove = false;
    for(int i=0; i<8; i++){
        int stepX = dXdY[i][0];
        int stepY = dXdY[i][1];
        int newX = x + stepX;
        int newY = y + stepY;
        
        int count = 0;
        while(newX >= 0 && newX < 4 && newY >= 0 && newY < 4){
            if(newBoard[newX][newY] == 0)
                break;
            else if(newBoard[newX][newY] != player){
                newX += stepX;
                newY += stepY;
                count++;
            }
            else{
                if(count > 0){
                    possibleMove = true;
                    if(isCheck)
                      return newBoard;
                      
                    int convertX = newX - stepX;
                    int convertY = newY - stepY;
                    while(convertX != x || convertY != y){
                        newBoard[convertX][convertY] = player;
                        convertX = convertX - stepX;
                        convertY = convertY - stepY;
                    }
                    newBoard[x][y] = player;
                }
                break;
            }
        }
    }
    if(possibleMove)
       return newBoard;
       
    else 
       return nullptr;
    
}


vector<pair<int, int>*>* possibleMove(int **board, int player){
    vector<pair<int, int>*>* output = new vector<pair<int, int>*>();
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(board[i][j] == 0){
                if(makeMove(board, i, j, player, true)){
                    pair<int, int>* p = new pair<int, int>(i, j);
                    output->push_back(p);
                }
            }
        }
    }
    
    return output;
}


int evaluateBoard(int **board, bool &canPlay){
    //no moves left
    if(possibleMove(board, 1)->size() != 0 || possibleMove(board, 2)->size() != 0){
        canPlay = false;
        return 0;
    }
    
    canPlay = true;
    int count[3];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            count[board[i][j]]++;
        }
    }
    
    return abs(count[1] - count[2]);
}


int main() {
    int **board = new int*[4];
    for(int i=0; i<4; i++){
        board[i] = new int[4];
        for(int j=0; j<4; j++){
            board[i][j] = 0;
        }
    }
    
    board[1][1] = 2;
    board[1][2] = 1;
    board[2][1] = 1;
    board[2][2] = 2;
    
    bool check = false;
    
    cout << evaluateBoard(board, check) << endl;
    
    //print 
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}