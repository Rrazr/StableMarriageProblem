//
//  OptionP.h
//  StableMarriageProblem
//
//  Created by Ryan Ong on 6/24/24.
//

#ifndef OptionP_h
#define OptionP_h

#include "NumberOfSMFunctions.h"
#include "MatrixManipFunctions.h"

void optionP() {
    int m, w;
    bool Psuedo = true;
    cout << "(A) Enter your own psuedo latin" << endl;
    cout << "(C) Generate all the SM's of n - 1" << endl;
    cout << "(D) Drop three" << endl;
    cout << "(E) Drop two" << endl;


    cout << "Enter choice: " << endl;
    cin >> ch;
    if(ch == 'a' || ch == 'A'){
        for (int i = 0; i < n; i ++){
           cout << "Enter Row " << i + 1 << ": ";
           for (int j = 0; j < n; j ++){
               cin >> m;
               matrix[i][j].m = m - 1;
               //matrix[i][j].w = 0;
               matrix[i][j].w =  n - matrix[i][j].m;
           }
           cout << '\n';
        }
        convertToGeneral();
        cout << "This is the given matrix";
        printMatrix();
        numberOfStableMatchings();
        cout << "The number of SM's is " << cnt<< endl;
    }
    //everything else starts here that ends choice a
    
    convertToGeneral();


    // cout << "count is " << count << endl;cout << "max is " << max << endl;
    //opens option c
    if(ch == 'c' || ch == 'c'){
        int startingN;
        cout << "Enter the n you would like to start with" << endl;
        cin >> startingN;
        cout << endl;
        dropToOneLessN(startingN);
    }else if(ch == 'd' || ch == 'D'){
        int startingN;
        cout << "Enter the n you would like to start with" << endl;
        cin >> startingN;
        cout << endl << "bean";
        cout << "recieved";
        dropToLessN(startingN);
    }else if(ch == 'e' || ch == 'e'){
        int startingN;
        cout << "Enter the n you would like to start with" << endl;
        cin >> startingN;
        dropTo2LessN(startingN);
    }
}

#endif /* OptionP_h */
