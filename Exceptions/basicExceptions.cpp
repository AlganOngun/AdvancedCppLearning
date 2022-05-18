#include <iostream>
#include <string>

void canThrowExceptions()
{
	throw std::string("testMessage");
}

void usesCanThrowExceptions()
{
	canThrowExceptions();
}

int main()
{
	try
	{
		usesCanThrowExceptions();
	}
	catch(std::string e)
	{
		std::cout << "Exception Caught: " << e << "\n";
	}

    std::cout << "Continued To Run\n";
}
