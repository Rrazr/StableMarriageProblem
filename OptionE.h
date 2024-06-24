//
//  OptionE.h
//  StableMarriageProblem
//
//  Created by Ryan Ong on 6/18/24.
//

#ifndef OptionE_h
#define OptionE_h

#include "NumberOfSMFunctions.h"
#include "MatrixManipFunctions.h"
#include <string>

void optionE(){
    string fileName, randStr;
    int SM, m, w, topSeed = 0;
    cout << "Enter seeds file: ";
    cin >> fileName;
    ifstream seedsFile;
    ofstream outputFile;
    seedsFile.open("/Users/ryan/Desktop/" + fileName);
    while (seedsFile >> randStr){
        for (int i = 0; i < 3; i ++){
            seedsFile >> randStr;
        }
        seedsFile >> SM;
        topSeed = SM > topSeed ? SM : topSeed;
        //cout << "SM: " << SM << '\n';
        //inputFile >> counter;
        for (int i = 0; i < n; i ++){
            //cout << "Enter Row " << i + 1 << ": ";
            for (int j = 0; j < n; j ++){
                seedsFile >> m >> w;
            }
        }
    }
    cout << "Top Seed: " << topSeed << '\n';
    seedsFile.close();
    seedsFile.open("/Users/ryan/Desktop/" + fileName);
    string name = "/Users/ryan/Desktop/16CrossTo15TopSeeds" + to_string(topSeed) + ".txt";
    outputFile.open(name, ios::app);
    while (seedsFile >> randStr){
        for (int i = 0; i < 3; i ++){
            seedsFile >> randStr;
        }
        seedsFile >> SM;
        //inputFile >> counter;
        if (SM == topSeed){
            outputFile << "Number of SM is " << topSeed << '\n';
        }
        for (int i = 0; i < n; i ++){
            //cout << "Enter Row " << i + 1 << ": ";
            for (int j = 0; j < n; j ++){
                seedsFile >> m >> w;
                if (SM == topSeed){
                    outputFile << m << " " << w << "  ";
                }
            }
            if (SM == topSeed){
                outputFile << '\n';
            }
        }
        if (SM == topSeed){
            outputFile << '\n';
        }
        cout << "SM: " << SM << '\n';
    }
    seedsFile.close();
    outputFile.close();
}

#endif /* OptionE_h */
