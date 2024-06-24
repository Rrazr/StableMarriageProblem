//
//  OptionI.h
//  StableMarriageProblem
//
//  Created by Ryan Ong on 6/24/24.
//

#ifndef OptionI_h
#define OptionI_h

#include "NumberOfSMFunctions.h"
#include "MatrixManipFunctions.h"

void optionI() {
    int m, w;
    for (int i = 0; i < n; i ++){
        cout << "Enter Row " << i + 1 << ": ";
        for (int j = 0; j < n; j ++){
            cin >> m >> w;
//                    mp[i][j] = m - 1;
//                    wp[j][i] = w - 1;
            matrix[i][j].m = m - 1;
            matrix[i][j].w = w - 1;
        }
        cout << '\n';
    }
    cout << "This is the given matrix:\n";
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cout << matrix[i][j].m + 1 << ',' << matrix[i][j].w + 1 << "  ";
        }
        cout << '\n';
    }
    numberOfStableMatchings();
}

#endif /* OptionI_h */
