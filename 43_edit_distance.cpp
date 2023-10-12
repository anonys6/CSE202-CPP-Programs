#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minStepsUsingMemoHelper(int n, int memo[]) 
{ 
    if(n == 1) {
        return 0;
    }
    
    if(n == 2 || n == 3) {
        return 1;
    }
    
    if(memo[n] != -1) {
        
        return memo[n];
    }
    
    int minusOne = 10000, divideByTwo = 10000, divideByThree = 10000;
    
    minusOne = minStepsUsingMemoHelper(n - 1, memo);
    
    if(n % 2 == 0) {
        divideByTwo =  minStepsUsingMemoHelper(n / 2, memo);
    }
    
    if(n % 3 == 0) {
        divideByThree =  minStepsUsingMemoHelper(n / 3, memo);
    }
    
    memo[n] =  1 + min(minusOne, min(divideByTwo, divideByThree));
    
    return memo[n];
    
    
} 

int minStepsUsingMemo(int n) {
    
    int memo[n + 1];
    
    for(int i = 0;  i <= n ; i++) {
        memo[i] = -1;
    }
    
    return minStepsUsingMemoHelper(n, memo);
    
}


int minStepsUsingDp(int n) {
    
    if(n == 1) {
        return 0;
    }
    
    if(n == 2 || n == 3) {
        return 1;
    }
    
    
    int dp[n + 1];
    
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i = 4; i <= n; i++) {
        
        int minStep = dp[i - 1];
        
        if(i % 2 == 0) {
            minStep = min(minStep, dp[i/2]);
        }
        
        if(i % 3 == 0) {
            minStep = min(minStep, dp[i/3]);
        }
        
        dp[i] = 1 + minStep;
        
    }
    
    return dp[n];
    

}


int minSteps(int n) 
{
    return minStepsUsingDp(n);
}

int minStepNumSquaresRecursive(int n) {
        
        if(n == 0) {
            return 0;
        }
        
        int minSteps = 10000;
        
        for(int i = 1; i * i <= n; i++) {
            minSteps = min(minSteps, 1 + minStepNumSquaresRecursive(n - i * i));
        }
        
        return minSteps;
}

int minPathSum (vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    int dp[m][n];
    
    dp[0][0] = grid[0][0];
    
    for(int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    
    for(int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            
        }
    }
    
    return dp[m - 1][n - 1];
}

    

// Edit Distance leetcode

int memo[501][501];
    
int minDistanceUsingMemoHelper(string s1, string s2,int m,int n) {
    
    if(m == 0) {
        return n;
    }
    
    if(n == 0) {
        return m;
    }
    
    if(memo[m][n] != -1) {
        return memo[m][n];
    }
    
    if(s1[m-1] == s2[n-1]) {
        memo[m][n] = minDistanceUsingMemoHelper(s1, s2, m-1, n-1);
    }else {
        int insert = minDistanceUsingMemoHelper(s1, s2, m, n-1);
        int remove = minDistanceUsingMemoHelper(s1, s2, m - 1, n);
        int replace = minDistanceUsingMemoHelper(s1, s2, m - 1, n - 1);
        
        memo[m][n] = 1 + min(insert, min(remove, replace));
    }
    
    return memo[m][n];
    
    
}


int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0;j <=n; j++) {
            memo[i][j] = -1;
        }
    } 
    
    return minDistanceUsingMemoHelper(word1, word2,word1.length(), word2.length());
    
}

int minDistanceUsingDp(string word1, string word2, int m, int n) {
    if(m == 0) {
        return n;
    }
    
    if(n == 0) {
        return m;
    }

    int dp[m+1][n+1];
    
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    
    return dp[m][n];
}

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    return minDistanceUsingDp(word1, word2, m, n);
}




/*
anonys6: solve the problem solved in memo usign dp, problem is already solve using memo, give solution in dp. Approach for dp is given for another problem, use that to implement dp.

problem solution using memo:
int memo[501][501];
    
int minDistanceUsingMemoHelper(string s1, string s2,int m,int n) {
    
    if(m == 0) {
        return n;
    }
    
    if(n == 0) {
        return m;
    }
    
    if(memo[m][n] != -1) {
        return memo[m][n];
    }
    
    if(s1[m-1] == s2[n-1]) {
        memo[m][n] = minDistanceUsingMemoHelper(s1, s2, m-1, n-1);
    }else {
        int insert = minDistanceUsingMemoHelper(s1, s2, m, n-1);
        int remove = minDistanceUsingMemoHelper(s1, s2, m - 1, n);
        int replace = minDistanceUsingMemoHelper(s1, s2, m - 1, n - 1);
        
        memo[m][n] = 1 + min(insert, min(remove, replace));
    }
    
    return memo[m][n];
    
    
}


int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0;j <=n; j++) {
            memo[i][j] = -1;
        }
    } 
    
    return minDistanceUsingMemoHelper(word1, word2,word1.length(), word2.length());
    
}


reference code to implement dp:
int minStepsUsingDp(int n) {
    
    if(n == 1) {
        return 0;
    }
    
    if(n == 2 || n == 3) {
        return 1;
    }
    
    
    int dp[n + 1];
    
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i = 4; i <= n; i++) {
        
        int minStep = dp[i - 1];
        
        if(i % 2 == 0) {
            minStep = min(minStep, dp[i/2]);
        }
        
        if(i % 3 == 0) {
            minStep = min(minStep, dp[i/3]);
        }
        
        dp[i] = 1 + minStep;
        
    }
    
    return dp[n];
    
    
}


int minSteps(int n) 
{
    return minStepsUsingDp(n);
}


problem statement:
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/