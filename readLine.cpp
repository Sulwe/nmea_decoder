#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    //get file path
    string filepath = "jogging_path.txt";

    //open file using ifstream
    ifstream file(filepath);

    //check if file didn't open successfully and inform user
    if (!file.is_open()) {
        cerr << "File failed to open" << filepath << endl;
        return 1;
    }

    //read file line by line
    string sentence;
    while (getline(file, sentence)){
        string input = sentence;
        //print "Empty line" for blank lines
        if (input == "") {
            cout << "Empty Line" << endl;
        }
        //print the sentense if available
        else {
            cout << input << endl;
            
        }
        
    }
    //close file
    file.close();
    return 0;
}