//
//  OptionB.h
//  StableMarriageProblem
//
//  Created by Ryan Ong on 6/5/24.
//

#ifndef OptionB_h
#define OptionB_h

#include "NumberOfSMFunctions.h"
#include "MatrixManipFunctions.h"

void optionB(){
    bool inputFromFile = true;
    
    // Choose Input Method
    cout << '\n';
    cout << "(A) Randomized matrix\n";
    cout << "(B) Input normal matrix\n";
    cout << "(C) Input Latin matrix\n";
    cout << "(D) Input file\n\n";
    cout << "Enter choice: ";
    cin >> ch;
    if (ch == 'A' || ch == 'a'){
        randomizer();
        inputFromFile = false;
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
        inputFromFile = false;
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
        inputFromFile = false;
    }
    
    // Choose Generation Mode
    cout << '\n';
    cout << "(A) Systematic Generation\n";
    cout << "(B) Random Generation\n\n";
    cout << "Enter choice: ";
    cin >> ch;
    
    if (!inputFromFile){
        largest = 0;
        numberOfStableMatchings();
        cout << "Starting number: " << largest << '\n';
        fattest = largest;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++){
                fattestMatrix[i][j].m = largestMatrix[i][j].m;
                fattestMatrix[i][j].w = largestMatrix[i][j].w;
            }
            //cout << '\n';
        }
        if (ch == 'A' || ch == 'a'){
            while (1) {
                largest = 0;
                bool endIteration = false;
                for (int i = 0; i < n; i ++){
                    for (int j = 0; j < n - 1; j ++){
                        for (int k = j + 1; k < n; k ++){
                            swapMen(i, j, k);
                            //                            cout << "Before:\n";
                            //                            printMatrix(matrix);
                            numberOfStableMatchings();
                            if (largest > fattest){
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
                                    outputFile.open("/Users/ryan/Desktop/greaterThanSeventyOne.txt");
                                    outputFile << "Number of Stable Marriages: " << largest << '\n';
                                    for (int i = 0; i < n; i ++){
                                        for (int j = 0; j < n; j ++){
                                            cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                        }
                                        cout << '\n';
                                    }
                                    outputFile.close();
                                }
                                endIteration = true;
                                break;
                            }
                            //readAndWriteFromFile();
                            
                            swapMen(i, j, k);
                            //                            cout << "After:\n";
                            //                            printMatrix(matrix);
                        }
                        if (endIteration){
                            break;
                        }
                    }
                    if (endIteration){
                        break;
                    }
                }
                if (!endIteration){
                    for (int i = 0; i < n; i ++){
                        for (int j = 0; j < n - 1; j ++){
                            for (int k = j + 1; k < n; k ++){
                                swapWomen(i, j, k);
                                //                            cout << "Before:\n";
                                //                            printMatrix(matrix);
                                numberOfStableMatchings();
                                if (largest > fattest){
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
                                        outputFile.open("/Users/ryan/Desktop/greaterThanSeventyOne.txt");
                                        outputFile << "Number of Stable Marriages: " << largest << '\n';
                                        for (int i = 0; i < n; i ++){
                                            for (int j = 0; j < n; j ++){
                                                cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                            }
                                            cout << '\n';
                                        }
                                        outputFile.close();
                                    }
                                    endIteration = true;
                                    break;
                                }
                                //readAndWriteFromFile();
                                swapWomen(i, j, k);
                                //                            cout << "After:\n";
                                //                            printMatrix(matrix);
                            }
                            if (endIteration){
                                break;
                            }
                        }
                        if (endIteration){
                            break;
                        }
                    }
                }
                if (!endIteration){
                    cout << 1 << '\n';
                    break;
                }
            }
        }else if (ch == 'B' || ch == 'b'){ // Work in progress (randomized BFS)
            int ind, ind2, ind3, temp = 0;
            PAIR Temp[n][n];
            while (1) {
                bool endIteration = true;
                for (int i = 0; i < 10; i ++){
                    cout << i << '\n';
                    ind = rand() % 2;
                    if (ind == 0){
                        ind = rand() % n;
                        ind2 = rand() % n;
                        do{
                            ind3 = rand() % n;
                        }while (ind3 == ind2);
                        swapMen(ind, ind2, ind3);
                        numberOfStableMatchings();
                        
                        if (largest > temp){
                            endIteration = false;
                            temp = largest;
                            for (int i = 0; i < n; i ++){
                                for (int j = 0; j < n; j ++){
                                    //cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                    Temp[i][j].m = largestMatrix[i][j].m;
                                    Temp[i][j].w = largestMatrix[i][j].w;
    //                                matrix[i][j].m = largestMatrix[i][j].m;
    //                                matrix[i][j].w = largestMatrix[i][j].w;
                                }
                                //cout << '\n';
                            }
                            if (largest > 71){
                                ofstream outputFile;
                                outputFile.open("/Users/ryan/Desktop/greaterThanSeventyOne.txt");
                                outputFile << "Number of Stable Marriages: " << largest << '\n';
                                for (int i = 0; i < n; i ++){
                                    for (int j = 0; j < n; j ++){
                                        cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                    }
                                    cout << '\n';
                                }
                                outputFile.close();
                            }
                        }
                        
                        swapMen(ind, ind2, ind3);
                    }else if (ind == 1){
                        ind = rand() % n;
                        ind2 = rand() % n;
                        do{
                            ind3 = rand() % n;
                        }while (ind3 == ind2);
                        swapWomen(ind, ind2, ind3);
                        numberOfStableMatchings();
                        
                        if (largest > temp){
                            endIteration = false;
                            temp = largest;
                            for (int i = 0; i < n; i ++){
                                for (int j = 0; j < n; j ++){
                                    //cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                    Temp[i][j].m = largestMatrix[i][j].m;
                                    Temp[i][j].w = largestMatrix[i][j].w;
    //                                matrix[i][j].m = largestMatrix[i][j].m;
    //                                matrix[i][j].w = largestMatrix[i][j].w;
                                }
                                //cout << '\n';
                            }
                            if (largest > 71){
                                ofstream outputFile;
                                outputFile.open("/Users/ryan/Desktop/greaterThanSeventyOne.txt");
                                outputFile << "Number of Stable Marriages: " << largest << '\n';
                                for (int i = 0; i < n; i ++){
                                    for (int j = 0; j < n; j ++){
                                        cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                    }
                                    cout << '\n';
                                }
                                outputFile.close();
                            }
                        }
                        
                        swapWomen(ind, ind2, ind3);
                    }
                }
                if (temp > fattest){
                    for (int i = 0; i < n; i ++){
                        for (int j = 0; j < n; j ++){
                            //cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                            fattestMatrix[i][j].m = Temp[i][j].m;
                            fattestMatrix[i][j].w = Temp[i][j].w;
                            matrix[i][j].m = Temp[i][j].m;
                            matrix[i][j].w = Temp[i][j].w;
                        }
                        //cout << '\n';
                    }
                }
                if (endIteration){
                    cout << 1 << '\n';
                    break;
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
    }else{
        string fileName;
        cout << "Enter file name: ";
        cin >> fileName;
        ifstream inputFile("/Users/ryan/Desktop/" + fileName);
        while(!inputFile.eof()){
            int m, w;
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
            cout << "Starting number: " << largest << '\n';
            fattest = largest;
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j ++){
                    fattestMatrix[i][j].m = largestMatrix[i][j].m;
                    fattestMatrix[i][j].w = largestMatrix[i][j].w;
                }
                //cout << '\n';
            }
            if (ch == 'A' || ch == 'a'){
                while (1) {
                    largest = 0;
                    bool endIteration = false;
                    for (int i = 0; i < n; i ++){
                        for (int j = 0; j < n - 1; j ++){
                            for (int k = j + 1; k < n; k ++){
                                swapMen(i, j, k);
                                //                            cout << "Before:\n";
                                //                            printMatrix(matrix);
                                numberOfStableMatchings();
                                if (largest > fattest){
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
                                        outputFile.open("/Users/ryan/Desktop/greaterThanSeventyOne.txt");
                                        outputFile << "Number of Stable Marriages: " << largest << '\n';
                                        for (int i = 0; i < n; i ++){
                                            for (int j = 0; j < n; j ++){
                                                cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                            }
                                            cout << '\n';
                                        }
                                        outputFile.close();
                                    }
                                    endIteration = true;
                                    break;
                                }
                                //readAndWriteFromFile();
                                
                                swapMen(i, j, k);
                                //                            cout << "After:\n";
                                //                            printMatrix(matrix);
                            }
                            if (endIteration){
                                break;
                            }
                        }
                        if (endIteration){
                            break;
                        }
                    }
                    if (!endIteration){
                        for (int i = 0; i < n; i ++){
                            for (int j = 0; j < n - 1; j ++){
                                for (int k = j + 1; k < n; k ++){
                                    swapWomen(i, j, k);
                                    //                            cout << "Before:\n";
                                    //                            printMatrix(matrix);
                                    numberOfStableMatchings();
                                    if (largest > fattest){
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
                                            outputFile.open("/Users/ryan/Desktop/greaterThanSeventyOne.txt");
                                            outputFile << "Number of Stable Marriages: " << largest << '\n';
                                            for (int i = 0; i < n; i ++){
                                                for (int j = 0; j < n; j ++){
                                                    cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                                }
                                                cout << '\n';
                                            }
                                            outputFile.close();
                                        }
                                        endIteration = true;
                                        break;
                                    }
                                    //readAndWriteFromFile();
                                    swapWomen(i, j, k);
                                    //                            cout << "After:\n";
                                    //                            printMatrix(matrix);
                                }
                                if (endIteration){
                                    break;
                                }
                            }
                            if (endIteration){
                                break;
                            }
                        }
                    }
                    if (!endIteration){
                        cout << 1 << '\n';
                        break;
                    }
                }
            }else if (ch == 'B' || ch == 'b'){ // Work in progress (randomized BFS)
                int ind, ind2, ind3, temp = 0;
                PAIR Temp[n][n];
                while (1) {
                    bool endIteration = true;
                    for (int i = 0; i < 10; i ++){
                        cout << i << '\n';
                        ind = rand() % 2;
                        if (ind == 0){
                            ind = rand() % n;
                            ind2 = rand() % n;
                            do{
                                ind3 = rand() % n;
                            }while (ind3 == ind2);
                            swapMen(ind, ind2, ind3);
                            numberOfStableMatchings();
                            
                            if (largest > temp){
                                endIteration = false;
                                temp = largest;
                                for (int i = 0; i < n; i ++){
                                    for (int j = 0; j < n; j ++){
                                        //cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                        Temp[i][j].m = largestMatrix[i][j].m;
                                        Temp[i][j].w = largestMatrix[i][j].w;
                                        //                                matrix[i][j].m = largestMatrix[i][j].m;
                                        //                                matrix[i][j].w = largestMatrix[i][j].w;
                                    }
                                    //cout << '\n';
                                }
                                if (largest > 71){
                                    ofstream outputFile;
                                    outputFile.open("/Users/ryan/Desktop/greaterThanSeventyOne.txt");
                                    outputFile << "Number of Stable Marriages: " << largest << '\n';
                                    for (int i = 0; i < n; i ++){
                                        for (int j = 0; j < n; j ++){
                                            cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                        }
                                        cout << '\n';
                                    }
                                    outputFile.close();
                                }
                            }
                            
                            swapMen(ind, ind2, ind3);
                        }else if (ind == 1){
                            ind = rand() % n;
                            ind2 = rand() % n;
                            do{
                                ind3 = rand() % n;
                            }while (ind3 == ind2);
                            swapWomen(ind, ind2, ind3);
                            numberOfStableMatchings();
                            
                            if (largest > temp){
                                endIteration = false;
                                temp = largest;
                                for (int i = 0; i < n; i ++){
                                    for (int j = 0; j < n; j ++){
                                        //cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                        Temp[i][j].m = largestMatrix[i][j].m;
                                        Temp[i][j].w = largestMatrix[i][j].w;
                                        //                                matrix[i][j].m = largestMatrix[i][j].m;
                                        //                                matrix[i][j].w = largestMatrix[i][j].w;
                                    }
                                    //cout << '\n';
                                }
                                if (largest > 71){
                                    ofstream outputFile;
                                    outputFile.open("/Users/ryan/Desktop/greaterThanSeventyOne.txt");
                                    outputFile << "Number of Stable Marriages: " << largest << '\n';
                                    for (int i = 0; i < n; i ++){
                                        for (int j = 0; j < n; j ++){
                                            cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                        }
                                        cout << '\n';
                                    }
                                    outputFile.close();
                                }
                            }
                            
                            swapWomen(ind, ind2, ind3);
                        }
                    }
                    if (temp > fattest){
                        for (int i = 0; i < n; i ++){
                            for (int j = 0; j < n; j ++){
                                //cout << largestMatrix[i][j].m + 1 << ',' << largestMatrix[i][j].w + 1 << "  ";
                                fattestMatrix[i][j].m = Temp[i][j].m;
                                fattestMatrix[i][j].w = Temp[i][j].w;
                                matrix[i][j].m = Temp[i][j].m;
                                matrix[i][j].w = Temp[i][j].w;
                            }
                            //cout << '\n';
                        }
                    }
                    if (endIteration){
                        cout << 1 << '\n';
                        break;
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
        }
    }
}


#endif /* OptionB_h */
