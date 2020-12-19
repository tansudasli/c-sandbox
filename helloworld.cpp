#include <iostream>
#include <vector>
#include <string>

using namespace std;

// run with, g++ -o out/helloworld helloworld.cpp -std=c++17
int main()
{
    // cout << "Hello World" << endl;

    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}