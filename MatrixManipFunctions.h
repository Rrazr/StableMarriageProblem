//
//  MatrixManipFunctions.h
//  StableMarriageProblem
//
//  Created by Ryan Ong on 6/4/24.
//

#ifndef MatrixManipFunctions_h
#define MatrixManipFunctions_h

char ch;

void printHistogram(){
    for (int i = 0; i < histogramSize; i ++){
        if (histogram[i] != 0){
            cout << i << ": " << histogram[i] << '\n';
        }
    }
    cout << "Mean: " << mean / 1000.0 << '\n';
//    cout << "Maximum: " << largest << "\n\n";
}

void printMatrix(){
    cout << "\nMatrix:\n";
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cout << matrix[i][j].m + 1 << ',' << matrix[i][j].w + 1 << "  ";
        }
        cout << '\n';
    }
    cout << '\n';
}

bool Pseudo = false;

int findIndex(int temp[], int size, int num){
    for (int i = 0; i < n + 1; i++){
        if (temp[i] == num){
            return i;
        }
    }
    return 0;
}

void convertToGeneral(){
    int arr[n];
    int temp[n];
    //fixing the rows
    //cout << "conver to general" << endl;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            arr[j] = matrix[i][j].m;
            temp[j] = matrix[i][j].m;

        }
        sort(temp, temp + n);
        for(int i = 0; i < n; i++){
            //cout << "arr[i] is "<< arr[i] << endl;
        }

        for(int k = 0; k < n; k++){
            arr[k] = findIndex(temp, n, arr[k]);
            matrix[i][k].m = arr[k];
            //cout << "arr[i] is "<< arr[i] << endl;
        }
    }

    //fixing columns
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            arr[j] = matrix[j][i].w;
            temp[j] = matrix[j][i].w;
            
        }
        
        sort(temp, temp + n);
        
        for(int k = 0; k < n; k++){
            arr[k] = findIndex(temp, n, arr[k]);
            matrix[k][i].w = arr[k];
        }
        
    }
}

// Clears matrix[][]
void clearMatrix(){
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            matrix[i][j].m = -1;
            matrix[i][j].w = -1;
        }
    }
}

// Clear men and women ranking vectors
void clearRankings(){
    mRank.clear();
    wRank.clear();
}

// Reset histogram and mean
void clearHistogram(){
    for (int i = 0; i < histogramSize; i ++){
        histogram[i] = 0;
    }
    mean = 0;
    largest = 0;
}

// Checks for multiple appearances of 1 in a single man's profile
bool repeatedOnes(int j){
    for (int i = 0; i < n - 1; i ++){
        if (matrix[i][j].m != 0){
            return false;
        }
    }
    return true;
}

// Randomizes matrix[][] in a way that no soulmates exist
void noSoulmatesRandomizer(){
    clearRankings();
    int ind = 0;
    //ind = rand() % mRank.size();
    //cout << ind << '\n';
    for (int i = 0; i < n; i ++){
        //cout << "i: " << i << '\n';
        ind = rand() % n;
        //cout << "ind: " << ind << '\n';
        if (i == n - 1){
            while (repeatedOnes(ind)){
                ind = rand() % n;
            }
        }
        matrix[i][ind].m = 0;
    }
    for (int i = 0; i < n; i ++){
        for (int k = 0; k < n; k ++){
            mRank.push_back(k + 1);
        }
        mRank.erase(mRank.begin() + (n - 1));
        for (int j = 0; j < n; j ++){
            if (matrix[i][j].m == -1){
                ind = rand() % mRank.size();
                matrix[i][j].m = mRank[ind];
                mRank.erase(mRank.begin() + ind);
            }
        }
    }
    //cout << "1: " << matrix[2][0].m << '\n';
    for (int i = 0; i < n; i ++){
        //cout << "i: " << i << '\n';
        do{
            ind = rand() % n;
            //cout << "ind: " << ind << '\n';
        }while(matrix[ind][i].m == 0);
        matrix[ind][i].w = 0;
    }
    for (int i = 0; i < n; i ++){
        for (int k = 0; k < n; k ++){
            wRank.push_back(k + 1);
        }
        wRank.erase(wRank.begin() + (n - 1));
        for (int j = 0; j < n; j ++){
            if (matrix[j][i].w == -1){
                ind = rand() % wRank.size();
                matrix[j][i].w = wRank[ind];
                wRank.erase(wRank.begin() + ind);
            }
        }
    }
}

// Randomizes matrix[][]
void randomizer(){
    clearRankings();
    int ind;
    for (int i = 0; i < n; i ++){
        for (int k = 0; k < n; k ++){
            mRank.push_back(k);
            wRank.push_back(k);
        }
        for (int j = 0; j < n; j ++){
            ind = rand() % mRank.size();
            matrix[i][j].m = mRank[ind];
            //mp[i][j] = mRank[ind];
            mRank.erase(mRank.begin() + ind);
            ind = rand() % wRank.size();
            matrix[j][i].w = wRank[ind];
            //wp[i][j] = wRank[ind];
            wRank.erase(wRank.begin() + ind);
        }
    }
}

// Swaps men preferences at i,j and i,k
void swapMen(int i, int j, int k){
    int temp = matrix[i][j].m;
    matrix[i][j].m = matrix[i][k].m;
    matrix[i][k].m = temp;
}

// Swaps women preferences at i,j and i,k
void swapWomen(int i, int j, int k){
    int temp = matrix[j][i].w;
    matrix[j][i].w = matrix[k][i].w;
    matrix[k][i].w = temp;
}

void displayDifferentNumbers(){ //displays a heat map of what rows and cols have been removed, use updateDisplayArray First
    for(int i = 0; i < n + 1; i++){
            
        for(int j = 0; j < n + 1; j++){
            
            cout << displayArr[i][j] << "   ";
        }

        cout << endl;
        
    }

}
void updateDisplayArray(int r, int c){ // updates the array heat map, takes in the row and col that have been removed
    displayArr[r][c] = cnt;
}


/*takes in the orignal n for example if your going from 4 to 3, the og n would be 4
reads matrices from a file and systematically chops every row and col
writes to a new file how many SM's and the corresponding matrices
at the end it will write out the heat map in the file
*/
void dropToOneLessN(int orignalN){

    int badRow = 0;
    int badCol = 0;
    int row = 0;
    int col = 0;
    bool RowChanged = true;
    int count = 0;
    int max = 0;
    int lastIteraation = 0;

    for (int i = 0; i < orignalN; i++)
    {
        for (int j = 0; i < orignalN; i++)
        {
            displayArr[i][j] = 0;
        }
    }
    // for reading the file
    ifstream FileToRead;
    FileToRead.open("/Users/thecownextdoorr/Desktop/eightcross.txt");
    ofstream specialMatrixFile("/Users/thecownextdoorr/Desktop/eightToSevenForHeatMap.txt", ios::app);
    string str;

    while (FileToRead >> str)
    {
        badRow = 0;
        badCol = 0;
        row = 0;
        col = 0;
        RowChanged = true;

        max = 0;
        lastIteraation = 0;
        int m;
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                FileToRead >> m;
                startNArray[i][j] = m;
            }
        }

        do
        {
            row = 0;
            col = 0;

            for (int i = 0; i < orignalN; i++)
            {
                for (int j = 0; j < orignalN; j++)
                {
                    // if its a bad row Or if its a bad com we should skip

                    if ((i != badRow && j != badCol))
                    { // if its not a bad row or if its not a bad col we input

                        matrix[row][col].m = startNArray[i][j];
                        matrix[row][col].w = n - matrix[row][col].m;

                        if (col < orignalN - 2)
                        {
                            col++;
                        }
                        else if (col == orignalN - 2)
                        {
                            col = 0;
                            row++;
                        }
                    }
                }
            }

            convertToGeneral();

            numberOfStableMatchings();

            
            specialMatrixFile << "Number of SM is " << cnt << endl;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    specialMatrixFile << matrix[i][j].m + 1 << ' ' << matrix[i][j].w + 1 << "  ";
                }
                specialMatrixFile << '\n';
            }

            if (cnt > max)
            {
                max = cnt;
            }

            updateDisplayArray(badRow, badCol);

            if (badRow == orignalN - 1 && badCol == orignalN - 1)
            {

                lastIteraation++;
            }

            else if (badRow < orignalN - 1)
            {
                badRow++;
            }

            else if (badRow == orignalN - 1)
            {
                badCol++;
                badRow = 0;
            }

        } while ((badRow != orignalN || badCol != orignalN) && lastIteraation != 1);
        count++;
    
        bool sixteenIsPresent = false;
        for (int i = 0; i < n + 1; i++)
        {

            for (int j = 0; j < n + 1; j++)
            {
                if (displayArr[i][j] == 16 && sixteenIsPresent == false)
                {
                    sixteenIsPresent = true;
                }
            }
        }

        specialMatrixFile << "Count is " << count << endl;
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                specialMatrixFile << startNArray[i][j] + 1 << " ";
            }
            specialMatrixFile << endl;
        }

        // HEAT MAPS
        for (int i = 0; i < n + 1; i++)
        {

            for (int j = 0; j < n + 1; j++)
            {

                specialMatrixFile << displayArr[i][j] << "   ";
            }

            specialMatrixFile << endl;
        }
        //}//if statement for 16
        // displayDifferentNumbers();
        cout << "count is " << count << endl;
    }
    specialMatrixFile.close();
    FileToRead.close();
    cout << endl
    << "max is " << max << endl;
    cout << "count is " << count << endl;
}

/*
takes in the orignal n for example if your going from 4 to 2, the og n would be 4
reads matrices from a file and systematically chops every 2 cols and 2 rows everytime
writes to a new file how many SM's and the corresponding matrices
*/

void dropTo2LessN(int orignalN){
    int row = 0;
    int col = 0;
    int count = 0;
    int max  = 0;
    
    //for reading the file
    ifstream FileToRead;
    FileToRead.open("/Users/thecownextdoorr/Desktop/TenCross.txt");
    ofstream FileToWrite("/Users/thecownextdoorr/Desktop/TenToEight.txt", ios::app);
    string str;
    while(FileToRead >> str){
        //reading file into startNArray array
        int m;
        for (int i = 0; i < n+2; i ++){
            //cout << "Enter Row " << i + 1 << ": ";
            for (int j = 0; j < n+2; j ++){
                FileToRead >> m;
                startNArray[i][j] = m;
                cout << startNArray[i][j] << " ";
                }
                cout << endl;
            }
            //finished reading
        row = 0;
        col = 0;
        for(int badColOne = 0; badColOne < orignalN - 1; badColOne++){
            for(int badColTwo = badColOne + 1; badColTwo < orignalN; badColTwo++){
                for(int badRowOne = 0; badRowOne < orignalN - 1; badRowOne++){
                    for(int badRowTwo = badRowOne + 1; badRowTwo < orignalN; badRowTwo++){
                        
                        row = 0;
                        col = 0;
                        for(int i = 0; i < orignalN; i++){
                            for(int j = 0; j < orignalN; j ++){
                                if((i != badRowOne && i != badRowTwo && j != badColOne && j != badColTwo)){ // if its not a bad row or if its not a bad col we input && j != badColOne && j != badColTwo
                                    matrix[row][col].m = startNArray[i][j];
                                    matrix[row][col].w =  n - matrix[row][col].m;
                                    if(col < orignalN - 3){ // because you are going 8 to 6 and 5 is max rows
                                        col++;
                                    }
                                    else if (col == orignalN - 3){
                                        col = 0;
                                        row++;
                                    }
                                }//if statement
                            }//inner for loop
                        }//outer for loop
                        
                        convertToGeneral();
                        numberOfStableMatchings();
                        if(cnt > max){
                            max = cnt;
                        }
                        count++;
                        cout << "count is " << count<< endl;
                        //printing out the matrix
                        for (int i = 0; i < n; i ++){
                            for (int j = 0; j < n; j ++){
                                cout << matrix[i][j].m << ' ' << matrix[i][j].w << "  ";
                            }
                            cout << '\n';
                        }
                        cout << '\n';
                        //break;
                        
                        
                        //writing matrix out in a file
                        FileToWrite << "Number of SM " << cnt << endl;
                        for (int i = 0; i < n; i ++){
                            for (int j = 0; j < n; j ++){
                                FileToWrite << matrix[i][j].m + 1 << ' ' << matrix[i][j].w + 1 << "  ";
                            }
                            FileToWrite << '\n';
                        }
                        FileToWrite << '\n';
                        



                    }//bad row two
                   // break;
                }//bad row one
                //break;
            }//bad col two
            //break;
        }//bad col one
        //break;





    }//end of reading while loop
    cout << "count is " << count;
    cout << "max is " << max << endl;
    FileToRead.close();
    FileToWrite.close();

}
/*takes in the orignal n for example if your going from 10 to 7, the og n would be 10
reads matrices from a file and systematically chops 3 cols and 3 rows everytime
writes to a new file how many SM's and the corresponding matrices
*/

void dropToLessN(int orignalN){
    int row = 0;
    int col = 0;
    bool RowChanged = true;
    int count = 0;
    int max  = 0;
    bool flipROne = true;
    bool flipRTwo = true;
    bool flipRThree = true;
    bool flipCOne = true;
    bool flipCTwo = true;
    bool flipCThree = true;
    //do{
        
    for(int badColOne = 0; badColOne < orignalN - 2; badColOne++){
    for(int badColTwo = badColOne + 1; badColTwo < orignalN - 1; badColTwo++){
    for(int badColThree = badColTwo + 1; badColThree < orignalN; badColThree++){
    for(int badRowOne = 0; badRowOne < orignalN - 2; badRowOne++){
    for(int badRowTwo = badRowOne + 1; badRowTwo < orignalN - 1; badRowTwo++){
    for(int badRowThree = badRowTwo + 1; badRowThree < orignalN; badRowThree++){
    row = 0;
    col = 0;


    for(int i = 0; i < orignalN; i++){
        for(int j = 0; j < orignalN; j ++){
        
        //if its a bad row Or if its a bad com we should skip

            if((i != badRowOne && i != badRowTwo && i != badRowThree && j != badColOne && j != badColTwo && j != badColThree)){ // if its not a bad row or if its not a bad col we input

             
                matrix[row][col].m = startNArray[i][j];
                matrix[row][col].w =  n - matrix[row][col].m;
        

            if(col < orignalN - 4){ // because you are going from 10 to 7 and 6 is max rows
                col++;
            }
            else if (col == orignalN - 4){
                col = 0;
                row++;
            }
            
            } // end of if else statment
       }//end of inner for loop
    //cout << endl;
    }//end of outer for loop
    convertToGeneral();

    numberOfStableMatchings();
    if(cnt > max){
        max = cnt;
    }
    count++;
    cout << "count is " << count <<endl;
    ofstream myFile("/Users/thecownextdoorr/Desktop/18to15BeforeHillClimb", ios::app);
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j ++){
                    myFile << matrix[i][j].m + 1 << ' ' << matrix[i][j].w + 1 << "  ";
                }
                myFile << '\n';
            }
            myFile << '\n';
            myFile.close();
    
   

    }//for bad row three
    }// for bad row two
    }//for bad row one
    }//for bad col three
    }//for bad col two
    }//for row bad col one
   cout << "count is " << count;
   cout << "max is " << max << endl;

}

/*takes in the orignal n for example if your going from 4 to 5, the og n would be 4
reads matrices from a file and adds a row and col
writes to a new file how many SM's and the corresponding matrices
*/

void increaseNByOne(int beginningN){
    
    ifstream FileToRead;
    int m;
    
    FileToRead.open("/Users/thecownextdoorr/Desktop/SixCross.txt");
    
    for (int i = 0; i < n - 1; i ++){
        //cout << "Enter Row " << i + 1 << ": ";
        for (int j = 0; j < n-1; j ++){
            FileToRead >> m;
            startNArray[i][j] = m;
            //cout << startNArray[i][j] << " ";
        }
        //cout << endl;
    }
    FileToRead.close();
    
    //n = 4
    
    int newRow[beginningN + 1];
    
    for(int i = 0; i < beginningN + 1; i++){
        newRow[i] = i;
    }
    
    int j = 0;
    //creating a new row basically takes 0123 and randomly permuates
    for(int i = beginningN - 1; i > 0; i--){
        j = rand() % (i + 1);
        swap(newRow[i], newRow[j]);
    }
    
    //adding the new row to the beginning and filling out the matrix and putting 0's in last col
    for(int i = 0; i < beginningN + 1; i++){
        for(int j = 0; j < beginningN + 1; j++){
            if(i == 0){
                matrix[i][j].m = newRow[j];
            }
            else if(j == beginningN){
                matrix[i][j].m = 0;
            }
            else{
                matrix[i][j].m = startNArray[i-1][j];
                matrix[i][j].w = (beginningN-1) - matrix[i][j].m;
            }
            
            
        }//end of inner for loop
    }//end of outer for loop
    
    
    int womenRow[beginningN];
    
    for(int i = 0; i < beginningN + 1; i++){
        womenRow[i] = i;
    }
    j = 0;
    //creating a new row
    for(int i = beginningN; i > 0; i--){
        j = rand() % (i + 1);
        swap(womenRow[i], womenRow[j]);
    }
    
    
    //adding the new row to the beginning and filling out the matrix and putting 0's in last col
    for(int i = 0; i < beginningN + 1; i++){
        for(int j = 0; j < beginningN + 1; j++){
            if(j == beginningN){
                matrix[i][j].w = womenRow[i];
            }
        }//end of inner for loop
    }//end of outer for loop
    
    
    
    
    
    int randomInt = 0;
    for(int i = 1; i < beginningN + 1; i++){
        randomInt = rand() % beginningN + 1;
        //cout << "rand is " << randomInt << endl;
        for(int j = beginningN; j >= 0; j--){
            if(randomInt != beginningN && randomInt != j && j > randomInt){
                
                matrix[i][j].m = matrix[i][j-1].m;
            }
            else if(randomInt == j){
                matrix[i][j].m = beginningN;
            }
            else if(randomInt == beginningN && j == beginningN){
                matrix[i][j].m = beginningN;
            }
            
        }
    }
    
    
    // WOMEN
    
    for(int i = 0; i < beginningN; i++){
        randomInt = rand() % beginningN+1;
        
        for(int j = 0; j < beginningN + 1; j++){
            if(randomInt != 0 && j < randomInt && randomInt != j){
                
                matrix[j][i].w = matrix[j+1][i].w;
            }
            else if(randomInt == j){
                matrix[j][i].w = beginningN;
            }
            
        }
    }
    
    
    numberOfStableMatchings();
    ofstream fileToWrite("/Users/thecownextdoorr/Desktop/sixToSeven.txt", ios::app);
    fileToWrite << "Number of Stable Marriages " << cnt << endl;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            fileToWrite << matrix[i][j].m + 1 << ' ' << matrix[i][j].w + 1 << "  ";
        }
        fileToWrite << '\n';
    }
    fileToWrite << '\n';
    fileToWrite.close();
}

#endif /* MatrixManipFunctions_h */
