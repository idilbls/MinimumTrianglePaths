//Minimum Triangle Path
#include <bits/stdc++.h>

using namespace std; 
  
// To find the minimum sum
int minTriPath(vector<vector<int> >& Tri) 
{ 
    int result[Tri.size()]; //The result is stored in a bi-dimensional array.
    int n = Tri.size() - 1; 
  
    for (int i = 0; i < Tri[n].size(); i++)  // For the bottom row 
        result[i] = Tri[n][i];     
  
	//Bottom up rows are calculated.
    for (int i = Tri.size() - 2; i >= 0; i--)  
        for (int j = 0; j < Tri[i].size(); j++)  
            result[j] = Tri[i][j] + min(result[j], 
                                    result[j + 1]); 
  
    // return the top element. 
    return result[0]; 
} 
