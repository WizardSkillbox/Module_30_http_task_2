#include <iostream>
#include <string>

#include <cpr/cpr.h>

using namespace std;

int main() {
    const string h1StartStr("<h1>");
    const string h1EndStr("</h1>");

    string response = (cpr::Get(cpr::Url("http://httpbin.org/html"),
                                cpr::Header({{"Accept", "text/html"}}))).text;

    size_t h1Start = response.find(h1StartStr);
    if (h1Start != string::npos) {
        h1Start += h1StartStr.length();
        size_t h1End = response.find(h1EndStr, h1Start);
        if (h1End != string::npos) {
            cout << response.substr(h1Start, h1End - h1Start) << endl;
        }
    }

    return 0;
}
