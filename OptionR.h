//
//  OptionR.h
//  StableMarriageProblem
//
//  Created by Ryan Ong on 6/24/24.
//

#ifndef OptionR_h
#define OptionR_h

#include "NumberOfSMFunctions.h"
#include "MatrixManipFunctions.h"

void optionR() {
    auto start = high_resolution_clock::now();
    
    clearHistogram();
    for (int i = 0; i < 1000; i ++){
        // Generating random samples
        randomizer();
        
        numberOfStableMatchings();
    }
    cout << "Histogram 1:\n";
    printHistogram();
//            cout << '\n';
//            clearHistogram();
//            for (int i = 0; i < 200; i ++){
//                clearMatrix();
//                // Generating random samples
//                noSoulmatesRandomizer();
//
//                numberOfStableMatchings();
//            }
//            cout << "Histogram 2:\n";
//            printHistogram();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
     
    cout << "Time taken by function: "
    << duration.count() << " milliseconds" << endl << '\n';
    
    //cout << "\nMean number of stable matchings: " << mean / 1000.0 << '\n';
}

#endif /* OptionR_h */
