#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
    string fileName = "stats.txt";
    ifstream file(fileName);

    if(!file.is_open()) return 1;

    while(file)
    {
        string line;

        getline(file, line, ':');

        int value;
        file >> value;

        file >> ws;

        if (!file) break;

        std::cout << "'" << line << "'" << " -- '" << value  << "'" << std::endl;
    }

    file.close();

    return 0;
}
