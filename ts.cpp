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
    int vertices, count, arrows;
    infile >> vertices; 
    
    int dynamarray[vertices][vertices];
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
            infile >> dynamarray[i][j];
    }

    infile.close();
    
    int visited[vertices], check[vertices];
    for (int i = 0; i < vertices; i++){
        visited[i] = 0;
        check[i] = 0;
    }
    
    for (int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++)
            visited[i] = visited[i] + dynamarray[j][i];
    }
    
    cout<<"\nTopological Sort: ";
    arrows = 0;
    while (count < vertices){
        for(int k = 0; k < vertices; k++){
            if(visited[k] == 0 && check[k] == 0){
                cout<< k <<" ";
                check[k] = 1;
                if (arrows < (vertices - 1)){
                    cout << "--> ";
                    arrows++;
                }
            }
            
            for(int p = 0; p < vertices; p++){
                if(dynamarray[p][k] == 1)
                    visited[k]--;
            }
        }
        count++;
    }
    cout << endl;
    /*
    cout << "Matrix is: " << endl;
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++){
            cout << dynamarray[i][j] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}