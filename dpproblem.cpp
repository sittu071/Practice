#include <bits/stdc++.h>
using namespace std;

// unordered_map<int, int> memo;

// int solve(vector<int>& memo, int n)
// {
//     if(n == 0) return 0;
//     if(n == 1) return 1;
//     if(memo[n] != -1) return memo[n];
    
//     memo[n] = solve(memo, n-1) + solve(memo, n-2);
//     return memo[n];

// }

void generate(int numRows) {
        for(int i = 1; i<numRows; i++)
        {
            for(int j = i; j>0; j--)
            {
                cout<<j<<"  ";
            }
            cout<<endl;
        }
}

int main()
{
    generate(2);
    return 0;
}