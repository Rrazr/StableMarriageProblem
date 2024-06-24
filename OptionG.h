//
//  OptionG.h
//  StableMarriageProblem
//
//  Created by Ryan Ong on 6/24/24.
//

#ifndef OptionG_h
#define OptionG_h

#include "NumberOfSMFunctions.h"
#include "MatrixManipFunctions.h"

void optionG() {
    int nEntered = 0;
    cout << "Enter the n you would like to start with " << endl;
    cin >> nEntered;
    int high = 0;
    high = cnt;
    for(int i = 0; i < 1000; i++){
        increaseNByOne(nEntered);
        histogram[cnt]++;
        if(high < cnt){
            high = cnt;
        }
    }
    for(int j = 0; j < 75; j++){
        cout << histogram[j] << " matrices have " << j << " SMs";
        cout << endl;
    }
    cout <<"The high is " << high;
}

#endif /* OptionG_h */
