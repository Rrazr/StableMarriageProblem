//
//  OptionH.h
//  StableMarriageProblem
//
//  Created by Ryan Ong on 6/5/24.
//

#ifndef OptionH_h
#define OptionH_h

#include "NumberOfSMFunctions.h"
#include "MatrixManipFunctions.h"

void optionH(){
    bool notFromFile = false;
    cout << '\n';
    cout << "(A) Randomized matrix\n";
    cout << "(B) Input normal matrix\n";
    cout << "(C) Input Latin matrix\n";
    cout << "(D) Input File\n";
    cout << "(E) Misc.\n\n";
    cout << "Enter choice: ";
    cin >> ch;
    if (ch == 'A' || ch == 'a'){
        randomizer();
        notFromFile = true;
    }else if (ch == 'B' || ch == 'b'){
        int m, w;
        for (int i = 0; i < n; i ++){
            cout << "Enter Row " << i + 1 << ": ";
            for (int j = 0; j < n; j ++){
                cin >> m >> w;
                matrix[i][j].m = m - 1;
                matrix[i][j].w = w - 1;
            }
        }
        cout << "This is the given matrix:\n";
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++){
                cout << matrix[i][j].m + 1 << ',' << matrix[i][j].w + 1 << "  ";
            }
            cout << '\n';
        }
        notFromFile = true;
    }else if (ch == 'C' || ch == 'c'){
        int num;
        for (int i = 0; i < n; i ++){
            cout << "Enter Row " << i + 1 << ": ";
            for(int j = 0; j < n; j++){
                cin >> num;
                matrix[i][j].m = num - 1;
                matrix[i][j].w = n - num;
            }
        }
        cout << "This is the given matrix:\n";
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++){
                cout << matrix[i][j].m + 1 << ',' << matrix[i][j].w + 1 << "  ";
            }
            cout << '\n';
        }
        notFromFile = true;
    }else if (ch == 'E' || ch =='e'){
        bool have16 = false;
        
        double avg = 0;
        
        int i;
        for (i = 0; i < 1000; i ++){
            randomizer();
            
            largest = 0;
            
            numberOfStableMatchings();
            
            fattest = largest;
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j ++){
                    fattestMatrix[i][j].m = largestMatrix[i][j].m;
                    fattestMatrix[i][j].w = largestMatrix[i][j].w;
                }
                //cout << '\n';
            }
            
            while (1) {
                largest = 0;
                for (int i = 0; i < n; i ++){
                    for (int j = 0; j < n - 1; j ++){
                        for (int k = j + 1; k < n; k ++){
                            swapMen(i, j, k);
                            //                            cout << "Before:\n";
                            //                            printMatrix(matrix);
                            numberOfStableMatchings();
                            //readAndWriteFromFile();
                            
                            swapMen(i, j, k);
                            //                            cout << "After:\n";
                            //                            printMatrix(matrix);
                        }
                    }
                }
                for (int i = 0; i < n; i ++){
                    for (int j = 0; j < n - 1; j ++){
                        for (int k = j + 1; k < n; k ++){
                            swapWomen(i, j, k);
                            //                            cout << "Before:\n";
                            //                            printMatrix(matrix);
                            numberOfStableMatchings();
                            //readAndWriteFromFile();
                            swapWomen(i, j, k);
                            //                            cout << "After:\n";
                            //                            printMatrix(matrix);
                        }
                    }
                }
                if (largest <= fattest){
                    cout << 1 << '\n';
                    break;
                }else{
                    cout << "Largest: " << largest << '\n';
                    fattest = largest;
                    for (int i = 0; i < n; i ++){
                        for (int j = 0; j < n; j ++){
                            //cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                            fattestMatrix[i][j].m = largestMatrix[i][j].m;
                            fattestMatrix[i][j].w = largestMatrix[i][j].w;
                            matrix[i][j].m = largestMatrix[i][j].m;
                            matrix[i][j].w = largestMatrix[i][j].w;
                        }
                        //cout << '\n';
                    }
//                    if (largest == 16){
//                        have16 = true;
//                        break;
//                    }
                }
            }
            histogram[fattest] ++;
            mean += fattest;
            //avg += fattest;
            cout << "Fattest: " << fattest << '\n';
            cout << "Matrix:\n";
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j ++){
                    cout << fattestMatrix[i][j].m + 1 << ',' << fattestMatrix[i][j].w + 1 << "  ";
                }
                cout << '\n';
            }
//            if (have16){
//                break;
//            }
        }
        printHistogram();
//        cout << "Average: " << avg / i << '\n';
//        cout << "Ran " << i << " samples\n";
//        if (have16){
//            cout << "Found 16!\n";
//        }
    }
    
    if (notFromFile){
        largest = 0;
        
        numberOfStableMatchings();
        
        fattest = largest;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++){
                fattestMatrix[i][j].m = largestMatrix[i][j].m;
                fattestMatrix[i][j].w = largestMatrix[i][j].w;
            }
            //cout << '\n';
        }
        
        while (1) {
            largest = 0;
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n - 1; j ++){
                    for (int k = j + 1; k < n; k ++){
                        swapMen(i, j, k);
                        //                            cout << "Before:\n";
                        //                            printMatrix(matrix);
                        numberOfStableMatchings();
                        //readAndWriteFromFile();
                        
                        swapMen(i, j, k);
                        //                            cout << "After:\n";
                        //                            printMatrix(matrix);
                    }
                }
            }
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n - 1; j ++){
                    for (int k = j + 1; k < n; k ++){
                        swapWomen(i, j, k);
                        //                            cout << "Before:\n";
                        //                            printMatrix(matrix);
                        numberOfStableMatchings();
                        //readAndWriteFromFile();
                        swapWomen(i, j, k);
                        //                            cout << "After:\n";
                        //                            printMatrix(matrix);
                    }
                }
            }
            if (largest <= fattest){
                cout << 1 << '\n';
                break;
            }else{
                cout << "Largest: " << largest << '\n';
                fattest = largest;
                for (int i = 0; i < n; i ++){
                    for (int j = 0; j < n; j ++){
                        //cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                        fattestMatrix[i][j].m = largestMatrix[i][j].m;
                        fattestMatrix[i][j].w = largestMatrix[i][j].w;
                        matrix[i][j].m = largestMatrix[i][j].m;
                        matrix[i][j].w = largestMatrix[i][j].w;
                    }
                    //cout << '\n';
                }
                if (largest > 71){
                    ofstream outputFile;
                    outputFile.open("/Users/thecownextdoorr/Desktop/greaterThanSeventyOne.txt");
                    outputFile << "Number of Stable Marriages: " << largest << '\n';
                    for (int i = 0; i < n; i ++){
                        for (int j = 0; j < n; j ++){
                            outputFile << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                        }
                        outputFile << '\n';
                    }
                    outputFile.close();
                }
            }
        }
        cout << "Fattest: " << fattest << '\n';
        cout << "Matrix:\n";
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++){
                cout << fattestMatrix[i][j].m + 1 << ',' << fattestMatrix[i][j].w + 1 << "  ";
            }
            cout << '\n';
        }
    }else if (!notFromFile && (ch == 'D' || ch == 'd')){
        string randy;
        int counter = 0;
        int randyInt;
        int seedSM;
        int removedRow = 1;
        int removedCol = 1;
        ofstream outputFile;
        outputFile.open("/Users/ryan/Desktop/6CrossTo7AllMatricesAfterHC.txt", ios::app);
        string fileName;
        cout << "Enter file name: ";
        cin >> fileName;
        ifstream inputFile("/Users/ryan/Desktop/" + fileName);
        while(inputFile >> randy){
            int m, w;
            //inputFile >> counter;
            for (int i = 0; i < 3; i ++){
                inputFile >> randy;
            }
            inputFile >> randyInt;
            for (int i = 0; i < n; i ++){
                //cout << "Enter Row " << i + 1 << ": ";
                for (int j = 0; j < n; j ++){
                    inputFile >> m >> w;
                    matrix[i][j].m = m - 1;
                    matrix[i][j].w = w - 1;
                }
            }
            cout << "This is the given matrix:\n";
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j ++){
                    cout << matrix[i][j].m + 1 << ',' << matrix[i][j].w + 1 << "  ";
                }
                cout << '\n';
            }
            
            
            largest = 0;
            
            numberOfStableMatchings();
            seedSM = largest;
            fattest = largest;
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j ++){
                    fattestMatrix[i][j].m = largestMatrix[i][j].m;
                    fattestMatrix[i][j].w = largestMatrix[i][j].w;
                }
                //cout << '\n';
            }
            
            while (1) {
                largest = 0;
                for (int i = 0; i < n; i ++){
                    for (int j = 0; j < n - 1; j ++){
                        for (int k = j + 1; k < n; k ++){
                            swapMen(i, j, k);
                            //                            cout << "Before:\n";
                            //                            printMatrix(matrix);
                            numberOfStableMatchings();
                            //readAndWriteFromFile();
                            
                            swapMen(i, j, k);
                            //                            cout << "After:\n";
                            //                            printMatrix(matrix);
                        }
                    }
                }
                for (int i = 0; i < n; i ++){
                    for (int j = 0; j < n - 1; j ++){
                        for (int k = j + 1; k < n; k ++){
                            swapWomen(i, j, k);
                            //                            cout << "Before:\n";
                            //                            printMatrix(matrix);
                            numberOfStableMatchings();
                            //readAndWriteFromFile();
                            swapWomen(i, j, k);
                            //                            cout << "After:\n";
                            //                            printMatrix(matrix);
                        }
                    }
                }
                if (largest <= fattest){
                    cout << 1 << '\n';
                    break;
                }else{
                    cout << "Largest: " << largest << '\n';
                    fattest = largest;
                    for (int i = 0; i < n; i ++){
                        for (int j = 0; j < n; j ++){
                            //cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                            fattestMatrix[i][j].m = largestMatrix[i][j].m;
                            fattestMatrix[i][j].w = largestMatrix[i][j].w;
                            matrix[i][j].m = largestMatrix[i][j].m;
                            matrix[i][j].w = largestMatrix[i][j].w;
                        }
                        //cout << '\n';
                    }
                }
            }
            cout << "Seed: " << seedSM << '\n';
            cout << "Fattest: " << fattest << '\n';
            //if (fattest >= MAX_SM){
//                cout << "Removed row " << removedRow << '\n';
//                cout << "Removed col " << removedCol << '\n';
//                outputFile << "Removed row " << removedRow << '\n';
//                outputFile << "Removed col " << removedCol << '\n';
                outputFile << "Seed: " << seedSM << '\n';
                outputFile << "Number of Stable Marriages: " << fattest << '\n';
                for (int i = 0; i < n; i ++){
                    for (int j = 0; j < n; j ++){
                        //cout << fattestMatrix[i][j].m + 1 << ',' << fattestMatrix[i][j].w + 1 << "  ";
                        outputFile << fattestMatrix[i][j].m + 1 << ' ' << fattestMatrix[i][j].w + 1 << "  ";
                    }
                    //cout << '\n';
                    outputFile << '\n';
                }
            //}
            histogram[fattest]++;
            mean += fattest;
            cout << "Matrix:\n";
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j ++){
                    cout << fattestMatrix[i][j].m + 1 << ',' << fattestMatrix[i][j].w + 1 << "  ";
                }
                cout << '\n';
            }
            removedRow = removedRow == n + 1 ? 1 : removedRow + 1;
            removedCol = removedRow == 1 ? removedCol + 1 : removedCol;
            
            counter ++;
            cout << "Counter: " << counter << '\n';
        }
        printHistogram();
        inputFile.close();
        outputFile.close();
    }
}


#endif /* OptionH_h */
