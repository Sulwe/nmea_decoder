#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <iterator>
#include "parseSentence.h"

using namespace std;

int main() {
    string split = convertDegrees("23456.786");
    cout << split << endl;
    assert("234°56.786'" == split);

    string dconv = convertDate("011224");
    cout << dconv << endl;
    assert(dconv == "01/12/24");

    string tconv = convertTime("123000");
    cout << tconv << endl;
    assert(tconv == "12:30:00");


}