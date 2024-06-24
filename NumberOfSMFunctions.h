//
//  NumberOfSMFunctions.h
//  StableMarriageProblem
//
//  Created by Ryan Ong on 6/4/24.
//

#ifndef NumberOfSMFunctions_h
#define NumberOfSMFunctions_h

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

// Number of pairs
// Change based on matrix size
const int n = 7;
const int MAX_SM = 1231;

//for displaying
int displayArr[n+1][n+1];

int startNArray[n+1][n+1];

struct PAIR{
    int m, w;
};
PAIR matrix[n][n];

// Number of stable marriages
int cnt;

int largest = 0;
PAIR largestMatrix[n][n];

int fattest = 0;
PAIR fattestMatrix[n][n];

const int histogramSize = 100000;
int histogram[histogramSize];

bool iterationKiller;

// Mean number of stable marriages
double mean = 0.0;

vector<int> mRank;
vector<int> wRank;

bool ok2(int q[], int col)                  //col =new man, q[col]= new woman
{
    int i;
    for(i=0; i<col;i++){                    // this will check if the new woman is already                                                assigned or not
        if(q[col]==q[i])
            return false;
    }//   First Step ends--for Loop

    for(i=0; i<col; i++)                      //matter of higher preference
    {
        if( ( matrix[col][q[i]].m<matrix[col][q[col]].m )&& ( matrix[col][q[i]].w<matrix[i][q[i]].w ) )
            return false;
        if( ( matrix[i][q[col]].w<matrix[col][q[col]].w )&& ( matrix[i][q[col]].m<matrix[i][q[i]].m) )
            return false;
    }// Second Step ends-for Loop

    return true;

}//boolean function ends here

void backtrack(int &col)
{
    col--;
    if(col==-1){
        cout << "Number of Stable Marriages: " << cnt << '\n';
        mean += cnt;
        histogram[cnt] ++;
        if (cnt > largest){
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j ++){
                    largestMatrix[i][j].m = matrix[i][j].m;
                    largestMatrix[i][j].w = matrix[i][j].w;
                }
            }
        }
        largest = cnt > largest ? cnt : largest;
        iterationKiller = false;

        
    }
    
}//backtrack function ends here

void print(int q[])
{
    int i;
    cout<<"Man"<<"  "<<"Woman"<<endl;
    for( i=0;i<n;i++)
    {
        cout<<" "<<i + 1<<"     "<<q[i] + 1<<endl;
    }

}// Print function ends here

void numberOfStableMatchings() {
    iterationKiller = true;
    
    // Keeps track of the number of stable matchings
    cnt = 0;
    
    // Permutation holder initialization
    int q[n];
    q[0]=0;
    int c=1;
    
    // from_backtrack keeps track if we need to reset the row to the
    // top of the current colum or not.
    bool from_backtrack=false;
    // The outer loop keep looking for solutions
    // The program terminates from function backtrack
    // when we are forced to backtack into column -1
    while(iterationKiller){
        while(c<n){ //this loop goes across columns
            // if we just returned from backtrack, use current value of row
            // otherwise get ready to start at the top of this column
            
            if(!from_backtrack)// we did not just return from backtrack
                q[c]=-1;   //check here
            
            from_backtrack=false;
            while(q[c]<n){ // place queen in this column
                q[c]++;
                // if row=8, there is no valid square in this column
                // so backtrack and continue the loop in the previous column
                
                
                while(q[c]==n)                //need to correct backtrack
                {
                    backtrack(c);
                    if (!iterationKiller){
                        break;
                    }
                    q[c]++;
                }
                if (!iterationKiller){
                    break;
                }
                
                //if this position is ok, place the queen
                // and move on (break) to the next column,
                // otherwise keep looking in this column
                
                if(ok2(q, c))
                    break;
                
            }// while q[c]<3
            if (!iterationKiller){
                break;
            }
            c++; // placed ok, move to the next column
        }//while(c<3)
        if (!iterationKiller){
            break;
        }
        
        // one complete solution found, print it.
        //print(q); // board completed, print it out
        cnt ++;
        //system("pause");
        backtrack(c);
        from_backtrack=true;
    }//while(1)
}

void readAndWriteFromFile(){
    //more than 50 SM
    bool alreadyExists = true;
    if(cnt > 50){
        int num;
        //string for reading
        string str;
        ifstream specialMatrixFile;
        specialMatrixFile.open("/Users/ryan/Desktop/Matrices.txt");
        while(!specialMatrixFile.eof()){
            alreadyExists = true;
            for (int i = 0; i < 5; i ++){
                specialMatrixFile >> str;
            }
            //getline(specialMatrixFile, str);
            //cout << str << '\n';
            //checks a matrix in file against current matrix
            cout << "Matrix:\n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    specialMatrixFile >> num;
                    cout << num << "  ";
                    if(num != matrix[i][j].m + 1){
                        //cout << "man is  " << matrix[i][j].m << endl;
                        alreadyExists = false;
                    }
                    specialMatrixFile >> num;
                    cout << num << "  ";
                    if(num != matrix[i][j].w + 1){
                        //cout << "woman is  " << matrix[i][j].w << endl;
                        alreadyExists = false;
                    }
                    
                }
                cout << '\n';
            }
            if (alreadyExists){
                break;
            }
        }
        specialMatrixFile.close();
        
        
        //for writing
        //openFile for matrices > 50 for writng
        if(!alreadyExists){
            ofstream specialMatrixFile("/Users/ryan/Desktop/Matrices.txt", ios::app);
            specialMatrixFile <<"Number of Stable Marriages: " << cnt << '\n';
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j ++){
                    specialMatrixFile << matrix[i][j].m + 1 << ' ' << matrix[i][j].w + 1 << "  ";
                }
                specialMatrixFile << '\n';
            }
            specialMatrixFile.close();
        }
    }
}

#endif /* NumberOfSMFunctions_h */
