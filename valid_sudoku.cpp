bool isValidRow(const vector<string> &A,int r){
    unordered_set<char> s;
    
    for(int i=0;i<9;i++){
        if(s.find(A[r][i])!=s.end()){
            return false;
        }
       if(A[r][i] != '.'){
              s.insert(A[r][i]);
        }
    }
  return true;
}
bool isValidCol(const vector<string> &A,int c){
    unordered_set<char> s;
    
    for(int i=0;i<9;i++)
    {
        if(s.find(A[i][c])!=s.end()){
            return false;
        }
        if(A[i][c] != '.'){
              s.insert(A[i][c]);
        }
    }
  return true;
}
bool Block(const vector<string> &A,int r,int c){
    unordered_set<char> s;
    
    for(int i=r;i<r+3;i++){
       for(int j=c;j<c+3;j++){
             if(s.find(A[i][j])!=s.end()){
                   return false;
             }
             if(A[i][j] != '.'){
                 s.insert(A[i][j]);
             }
         } 
    }
  return true;
}
int Solution::isValidSudoku(const vector<string> &A) {
     if(A.size()!=9 || A[0].size()!=9){
         return false;
     }
     for(int i=0;i<9;i++){
          if(!isValidRow(A,i)){ return false; }
          if(!isValidCol(A,i)){ return false; }
     }
    
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
               if(!Block(A,i,j)){
                   return false;
               }
        }
    }
  return true;
}
