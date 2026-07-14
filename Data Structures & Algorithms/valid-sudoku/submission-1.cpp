class Solution {
public:
bool checkRow(int row, vector<vector<char>>& board){
    set<char> st;

    for(int j=0;j<9;j++){
        if(board[row][j]=='.') continue;

        if(st.count(board[row][j]))
            return false;

        st.insert(board[row][j]);
    }

    return true;
}

bool checkCol(int col, vector<vector<char>>& board){
    set<char> st;

    for(int i=0;i<9;i++){
        if(board[i][col]=='.') continue;

        if(st.count(board[i][col]))
            return false;

        st.insert(board[i][col]);
    }

    return true;
}
bool check (int x1,int y1,int x2,int y2,vector<vector<char>>& board){
    set<char>myset;
for(int i=x1;i<=x2;i++){
    for(int j=y1;j<=y2;j++){
        if( board[i][j]!='.' && myset.find(board[i][j])!=myset.end()){
return true;
        }
        myset.insert({board[i][j]});
    }
}
return false;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        for(int i=0;i<n;i++){
            if(!checkRow(i,board))return false;
            if(!checkCol(i,board))return false;
        }
        for(int i=0;i<n;i+=3){
            for(int j=0;j<n;j+=3){
                if(check(i,j,i+2,j+2,board))return false;
            }
        }

return true;
    }
};
