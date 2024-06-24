//
//  OptionS.h
//  StableMarriageProblem
//
//  Created by Ryan Ong on 6/24/24.
//

#ifndef OptionS_h
#define OptionS_h

#include "NumberOfSMFunctions.h"
#include "MatrixManipFunctions.h"

int matching[n];

bool isStableMatching(){
    for (int i = 1; i < n; i ++){
        for (int j = 0; j < i; j ++){
            if (matrix[i][matching[j]].m < matrix[i][matching[i]].m &&
                matrix[i][matching[j]].w < matrix[j][matching[j]].w) {
                return false;
            }else if (matrix[j][matching[i]].m < matrix[j][matching[j]].m &&
                      matrix[j][matching[i]].w < matrix[i][matching[i]].w){
                return false;
            }
        }
    }
    return true;
}

void optionS() {
    int num;
    cout << "Enter matchings in order:\n";
    for (int i = 0; i < n; i ++){
        cout << "Man " << i + 1 << "'s pair: ";
        cin >> num;
        matching[i] = num - 1;
    }
    for (int i = 0; i < n; i ++){
        cout << matching[i] << " ";
    }
    cout << '\n';
    cout << (isStableMatching() ? "The given matching is stable\n" : "The given matching is unmatching\n");
    cout << '\n' << '\n';
}

#endif /* OptionS_h */
