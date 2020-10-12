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

int main() 
{ 	//The size of the triangle and variables for each element entered
	int num,size;
    vector<vector<int> > Tri(size);
    
    cout<<"Enter the size of tirangle:";
    cin>>size;
    
    //Numbers are taken from the user.
    for(int i=0;i<=size;i++)
    {
    	//A temporary variable is created to use numbers.
    	vector<int> temp;
    	for(int j=0; j<=i ; j++)
    	{
    		cin>>num;
    		temp.push_back(num);
		}
    	Tri.push_back(temp);
    	temp.clear();
	}	
	//A file is created for the numbers.
	std::ofstream outFile("triangle.txt");
	//The numbers received from the user are printed to the file.
    for (int i = 0; i < Tri.size(); i++) 
	{ 
        for (int j = 0; j < Tri[i].size(); j++) 
            outFile <<Tri[i][j] << " "; 
        outFile << endl; 
    } 
	
    cout <<"Minimal path is: "<< minTriPath(Tri); 
    return 0; 
} 
