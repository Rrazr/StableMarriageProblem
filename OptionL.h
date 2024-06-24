//
//  OptionL.h
//  StableMarriageProblem
//
//  Created by Ryan Ong on 6/5/24.
//

#ifndef OptionL_h
#define OptionL_h

#include "NumberOfSMFunctions.h"
#include "MatrixManipFunctions.h"

int latinMatrix[n][n];

void optionL(){
    string fileName;
    largest = 0;
    int Counter = 1, latinVal;
    
    //opening file
    cout << "Enter file name: ";
    cin >> fileName;
    ifstream inputFile;
    inputFile.open("/Users/ryan/Desktop/" + fileName);
    if (!inputFile) {
        cout << "Error opening file.txt" << endl;
        exit(1);
    }
    while (!inputFile.eof()){
        cout << '\n';
        for (int i = 0; i < n; i ++){
            for(int j = 0; j < n; j++){
                inputFile >> latinVal;
                cout << latinVal << " ";
//                        mp[i][j] = latinMatrix[i][j] - 1;
//                        wp[j][i] = n - latinMatrix[i][j];
                matrix[i][j].m = latinVal - 1;
                matrix[i][j].w = n - latinVal;
            }
            cout << '\n';
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j].m - 1 << ", ";
            }
            cout << endl;
        }
        auto start = high_resolution_clock::now();
        numberOfStableMatchings();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
         
        cout << "Time taken by profile " << Counter << ": "
        << duration.count() << " milliseconds" << endl << '\n';
        Counter++;
    }


    cout << "Most number of stable matchings: " << largest << '\n' << '\n';
    
    printHistogram();
    inputFile.close();
}


#endif /* OptionL_h */
