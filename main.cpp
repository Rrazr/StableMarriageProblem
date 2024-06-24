/** StableMarriage -- Non Recursive Version
 *  StableMarriageRecursion.cpp
 *
 *  Fall, 2011
 *
 *  Problem: Stable Marriage Problem-- Matches Men & Women after listening to their preferences
 *
 *  For More Description & Example of Problem:
 *     Check File: 'stable marriage using backtrack assignment.pdf'
 *
 *  Input Format:
 *      You can't input straight away, however, you can edit 'mp' and 'wp' arrays to change the
 *      input in different way
 *
 *  OutPut Format:
 *      This program will output the best possible men and women matches
 *
 * This program matches 3 men with 3 women in a best way possible acc. to men and women preferences
 *
 * @param mp mp: stands for Men's Preferences, holds preferences of 3 mens's
 *               For eg. in 'int mp[3][3] = {{0,2,1},{0,2,1},{1,2,0}};'
 *               First men Preferences are: 0, 2, 1        (here each of 0, 2, 1 represents a women)
 *               Third men Preferences are: 1, 2, 0
 * @param wp wp stands for Women's Preferences
 * @Compiler version on which Program is Last Run before uploading to Github: Dev-C++ 5.4.1, Date: 1st July, 2013
 * @author Gurpreet Singh
 */

#include "OptionL.h"
#include "OptionH.h"
#include "OptionB.h"
#include "OptionE.h"
#include "OptionR.h"
#include "OptionS.h"
#include "OptionI.h"
#include "OptionP.h"
#include "OptionG.h"

// Start timer
clock_t tStart;

int main() {
    srand((unsigned int)time(NULL));
    
    while(1) {
        cout << "Choose an option below:\n";
        cout << "(R) Generate And Calculate Random Samples\n";
        cout << "(S) Verify Matching\n";
        cout << "(L) Test Latin Matrix\n";
        cout << "(H) Hill Climbing Search\n";
        cout << "(B) Best First Search\n";
        cout << "(I) Input Matrix\n";
        cout << "(P) Input Psuedo Latin Matrix\n";
        cout << "(E) Extract Top Seeds\n";
        cout << "(G) Generate a new matrix that is n + 1\n\n";
        cout << "Enter choice: ";
        cin >> ch;
        cout << '\n' << '\n';
        if (ch == 'R' || ch == 'r'){
            optionR();
        }else if (ch == 'S' || ch == 's'){
            optionS();
        }else if (ch == 'L' || ch == 'l'){
            optionL();
        }else if (ch == 'I' || ch == 'i'){
            optionI();
        }else if (ch == 'H' || ch == 'h'){
            optionH();
        }else if (ch == 'P' || ch == 'p'){
            optionP();
        }else if (ch == 'B' || ch == 'b'){
            optionB();
        }else if (ch == 'E' || ch == 'e'){
            optionE();
        }else if (ch == 'G' || ch == 'g'){
            optionG();
        }
    }
}//main method
             
