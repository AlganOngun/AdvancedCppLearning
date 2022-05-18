#include <iostream>

class canThrowExceptions
{
public:
    canThrowExceptions()
    {
        char* bytes = new char[99999999999999];
        delete [] bytes;
    }
};

int main()
{
    try
    {
        canThrowExceptions instance;
    }
    catch(std::bad_alloc& e)
    {
		std::cout << "Caught Exception: " << e.what() << "\n";
	}

	std::cout << "Still Running\n";
}
