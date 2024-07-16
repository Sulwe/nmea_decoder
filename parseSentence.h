#ifndef PARSESENTENCE_H
#define PARSESENTENCE_H
#include <iostream>
#include <sstream>
#include <string>

    using namespace std;

    //function to split sentence into tokens using comma as delimiter
    void splitString(string input, char delimiter, string arr[], int index)

    {
        //create input string stream from input string
        istringstream stream(input);

        //temporary string to store token
        string token;

        //read tokens from string separated by delimiter
        while (getline(stream, token, delimiter)) {
            //add token to array
            arr[index++] = token;
        }        
    }

        //////////////function to convert direction
        string convertDegrees(string input) 
        { 


            // Delimiter 
            char delimiter = '.'; 

            // Array to store the substrings 
            string arrayOfDegrees[100]; 

            // Index to keep track of the number of substrings 
            int index = 0; 

            // Calling the function to split the input string into 
            // an array of substrings 
            splitString(input, delimiter, arrayOfDegrees, index); 


            string s = arrayOfDegrees[0];
            string t = arrayOfDegrees[1];
            string p;

            if (s.length() == 4){
                p = s.insert(2, "°");
            }
            else if (s.length() == 5){
                p = s.insert(3, "°");
            }

            return p +"."+ t + "'";
        }

        /////////////////////////////////////////////////////////

    //function to parse sentences and extract useful information
    int parser(string input)
    {
        //select comma as delimiter
        char delimiter = ',';

        //create array to store substrings
        string arrayOfSubStrings[100];

        //initialize index to keep track of number of substrings
        int index = 0;

        //call function
        splitString(input, delimiter, arrayOfSubStrings, index);

        //create an object to hold the information
        class MyData {
            public:
                string addressField;
                string time;
                string lattitude;
                string longitude;
                string latdir;
                string londir;
                string speed;
                string course;
                string date;
        };

            MyData nmeaData;

            nmeaData.addressField = arrayOfSubStrings[0];
            //map the addressfields into integers to be used in switch statement
            int caseMap;

            if (nmeaData.addressField == "$GPGGA") {
                caseMap = 1;
            }
            else if (nmeaData.addressField == "$GPGLL") {
                caseMap = 2;
            }
            else if (nmeaData.addressField == "$GPRMC") {
                caseMap = 3;
            }

            switch (caseMap) {
                case 1:
                    nmeaData.time = arrayOfSubStrings[1];
                    nmeaData.lattitude = convertDegrees(arrayOfSubStrings[2]);
                    nmeaData.latdir = arrayOfSubStrings[3];
                    nmeaData.longitude = convertDegrees(arrayOfSubStrings[4]);
                    nmeaData.londir = arrayOfSubStrings[5];

                    cout << "Time: " << nmeaData.time << ", Lattitude: " <<nmeaData.lattitude <<nmeaData.latdir << ", Longitude: "<<nmeaData.longitude <<nmeaData.londir<< endl;
                    break;

                case 2:
                    nmeaData.time = arrayOfSubStrings[5];
                    nmeaData.lattitude = convertDegrees(arrayOfSubStrings[1]);
                    nmeaData.latdir = arrayOfSubStrings[2];
                    nmeaData.longitude = convertDegrees(arrayOfSubStrings[3]);
                    nmeaData.londir = arrayOfSubStrings[4];

                    cout << "Time: " << nmeaData.time << ", Lattitude: " <<nmeaData.lattitude <<nmeaData.latdir << ", Longitude: "<<nmeaData.longitude <<nmeaData.londir<< endl;
                    break;

                case 3:
                    nmeaData.time = arrayOfSubStrings[1];
                    nmeaData.lattitude = convertDegrees(arrayOfSubStrings[3]);
                    nmeaData.latdir = arrayOfSubStrings[4];
                    nmeaData.longitude = convertDegrees(arrayOfSubStrings[5]);
                    nmeaData.londir = arrayOfSubStrings[6];
                    nmeaData.speed = arrayOfSubStrings[7];
                    nmeaData.course = arrayOfSubStrings[8];
                    nmeaData.date = arrayOfSubStrings[9];

                    cout << "Date: "<<nmeaData.date<< ", Time: " << nmeaData.time << ", Lattitude: " <<nmeaData.lattitude <<nmeaData.latdir << " Longitude: "<<nmeaData.longitude <<nmeaData.londir<< ", Speed: "<<nmeaData.speed<<" knots, Course: "<<nmeaData.course<<" degrees."<<endl;
                    break;

                default:
                cout << "Addressfield not found" <<endl;

                for (int i = 0; i < index; i++) {
                    cout << arrayOfSubStrings[i] << endl;
                }
                return 0;
            }

    }

#endif