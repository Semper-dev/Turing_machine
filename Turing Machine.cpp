#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>    
#include <string.h>    
#include <cstring>

using namespace std;

int main()
{
    int headposition = 0, max = 0, line = 0, counter = 0;
    string state = "0", temp_head_position;
    string tape, file_name;
    vector <string> vect;
    vector<vector<string>> second_vector;
    string* tapeArray = new string[100];
    vector<string> temp[100];
    
    cout << "Enter file name (e.g. - (code1,code2,code3,code4).txt):" << endl;
    cin >> file_name;

    ifstream myFile(file_name);
    

    if (myFile.is_open())
    {
        myFile >> headposition;
             while (getline(myFile, tape, '\n'))
             {
                 if (line == 1)
                 { break; }
                 line++;
             }
             max = tape.length() + 1;
             //string* tapeArray = new string[max];
             cout << headposition << endl;
             cout << '\n';
             for (int i = 0; i < max; i++) {
                 tapeArray[i] = tape[i];
                 cout << tapeArray[i];
             }
             cout << '\n' << '\n';

             
             for (int i = 0; i < 999; i++) {

                 if (counter % 5 == 0 && counter != 0) {
                    second_vector.push_back(vect);
                     for (int i = 0; i < 5; i++) {
                         vect.pop_back();
                     }
                 }
                 string l;
                 myFile >> l;
                 vect.push_back(l);
                 if (myFile.eof()) {
                     vect.pop_back();
                     break;
                 }
                 counter++;
             }

             for (int i = 0; i < counter / 5; i++) {
                 for (int k = 0; k < 5; k++) {
                     cout << second_vector[i][k];
                     if (k == 4) { cout << '\n'; }
                 }
             }
             
                     
             
             for (int i = 0; i < 99999; i++) {
                 //cout << "Head:" << temp_head_position << endl; //
                 for (int j = 0; j < counter / 5; j++) {
                     temp_head_position = tapeArray[headposition];
                     if (second_vector[j][0].compare(state) == 0) {
                         for (int k = 1; k < 2; k++) {
                             if (second_vector[j][k].compare(temp_head_position) == 0) {
                                 //cout << "Vector:" << second_vector[j][k] << endl; //
                                 k++;
                                 string temp = second_vector[j][k];
                                 char tempChar[1];
                                 tempChar[0] = temp[0];
                                 //cout << "Irasom:" << tempChar[0] << endl; //
                                 tapeArray[headposition] = tempChar[0];
                                 
                                 k++;
                                 if (second_vector[j][k] == "R") {
                                     headposition++;
                                 }
                                 else { headposition--; }
                                 
                                 k++;
                                 //cout << "Vector:" << second_vector[j][k] << endl;
                                 state = second_vector[j][k];
                                 //cout << "State:" << state << endl;
                                 //cout << "headposition:" << headposition << endl;
                                 for (int m = 0; m < max; m++) { cout << tapeArray[m]; }
                                 cout << "\n";
                             }
                         }
                     }
                     
                 }

             }

    }
    else { cout << "Unable to open file"; }   
    myFile.close();
}
