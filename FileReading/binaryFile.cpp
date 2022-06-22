#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#pragma pack(push, 1)

struct Person
{
    char name[50];
    int age;
    double height;
};

#pragma pack(pop)

int main (int argc, char *argv[])
{
    Person testPerson {"Frudo", 50, 1.7};

    string fileName {"test.bin"};
    ofstream outputFile {fileName, ios::binary};

    if(outputFile.is_open())
    {
        outputFile.write(
                reinterpret_cast<char *>(&testPerson),
                sizeof(Person)
                );

        outputFile.close();
    }
    else cout << "Could not create file" << fileName << endl;


    Person loadedPerson {};

    ifstream inputFile {fileName, ios::binary};

    if(inputFile.is_open())
    {
        inputFile.read(
                reinterpret_cast<char *>(&loadedPerson),
                sizeof(Person)
                );

        inputFile.close();
    }
    else cout << "Could not read file" << fileName << endl;

    cout << loadedPerson.name << ", " << loadedPerson.age << ", "
         << loadedPerson.height << endl;
}
