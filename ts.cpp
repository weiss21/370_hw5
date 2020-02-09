/*
 * Title: ts.cpp
 * Abstract:  implements the topological sorting algorithm based on the source-removal algorithm.
 * Author: Wais Robleh
 * ID: 1624
 * Date: 02/08/2020
 */

#include <bits/stdc++.h>

using namespace std;
int main () {
 
    string fileName;
    cout << "Enter filename: "; 
    cin >> fileName;
    
    ifstream infile(fileName.c_str());
    int num;
    infile >> num; 
    
    int dynamarray[num][num];
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
            infile >> dynamarray[i][j];
    }

    infile.close();
    
    cout << "Matrix is: " << endl;
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++){
            cout << dynamarray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}