class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // return LCSBottomUp(text1, text2);
        return LCSBottomUpOptimizedSpace(text1, text2);
    }
    
    int LCSBottomUpOptimizedSpace(string text1, string text2){
        // make sure minimum is at text1
        if(text1.length() > text2.length()){
            string temp = text2;
            text2 = text1;
            text1 = temp;
        }        
        int len1 = text1.length();
        int len2 = text2.length();

        int nCols = len1 + 1;
        int nRows = len2 + 1;

        int prevRow[nCols];
        int currentRow[nCols];
        
        // initially, set first row as zeros
        for(int col=0; col<nCols; col++){
            prevRow[col] = 0;
        }
        // first col is zero
        currentRow[0] = 0;
        
        for(int row=1; row<nRows; row++){
            for(int col=1; col<nCols; col++){
                if(text1[col - 1] == text2[row - 1]){
                    currentRow[col] = prevRow[col - 1] + 1;
                }else{
                    currentRow[col] = max(
                        prevRow[col],
                        currentRow[col - 1]
                    );
                }
            }
            // change.
            // prevRow = currentRow;
            for(int col=1; col<nCols; col++){
                prevRow[col] = currentRow[col];
            }
            
            currentRow[0] = 0;
        }
        
        return currentRow[nCols - 1];
    }
    
    
    int LCSBottomUp(string text1, string text2){
        int len1 = text1.length();
        int len2 = text2.length();
        
        
        int dp[len1 + 1][len2 + 1];
        
        // empty -> 0
        int nRows = len1 + 1;
        int nCols = len2 + 1;
        
        // 1st column fillup -> using row traversal
        for(int row=0; row<nRows; row++){
            dp[row][0] = 0;
        }
        
        // 1st row fillup -> using col traversal
        for(int col=0; col<nCols; col++){
            dp[0][col] = 0;
        }
        
        
        // iteration
        for(int row=1; row<nRows; row++){
            // cout << "row = " << row << endl;
            for(int col=1; col<nCols; col++){
                // last char == ??
                if(text1[row - 1] == text2[col - 1]){
                    // last chars are equal, 
                    dp[row][col] = 1 + dp[row - 1][col - 1];
                }else{
                    dp[row][col] = max(
                        dp[row - 1][col], // from top
                        dp[row][col - 1] // from left
                    );
                }
            }
            
            // debugging
            // printArray(dp, nRows, nCols);
            // for(int i=0; i<nRows; i++){
            //     for(int j=0; j<nCols; j++){
            //         cout << dp[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << "-----------------\n";
            
        }
        
        
        return dp[nRows-1][nCols-1];
    }
    
};