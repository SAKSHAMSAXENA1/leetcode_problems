class Solution {
public:
bool isSubboxValid(int i,int j,vector<vector<char>> &board)
{
    int freq[9]={0};
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(board[i+row][j+col]=='.') continue;
            freq[board[i+row][j+col]-'1']++;
            if(freq[board[i+row][j+col]-'1'] > 1) return false;
        }
    }

    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(auto row:board)
        {
            int freq[9]={0};
            for(auto c: row)
            {
                if(c=='.') continue;
                freq[c-'1']++;
                if(freq[c-'1'] > 1) return false; 
            }
        }

        for(int col=0;col<9;col++)
        {
            int freq[9]={0};
            for(int row=0;row<9;row++)
            {
                if(board[row][col]=='.') continue;
                freq[board[row][col]-'1']++;
                if(freq[board[row][col]-'1'] > 1) return false;
            }
        }

        for(int row=0;row<9;row+=3)
        {
            for(int col=0;col<9;col+=3)
            {
                if(!isSubboxValid(row,col,board)) return false;
            }
        }

        return true;
    }
};