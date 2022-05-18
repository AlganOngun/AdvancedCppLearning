#include <iostream>
#include <exception>

void canThrowExceptions()
{
	bool error1 = true;
	bool error2 = false;

	if(error1) throw std::bad_alloc();
	if(error2) throw std::exception();
}

int main()
{
	try
	{
		canThrowExceptions();
	}
	catch(std::bad_alloc& e)
	{
		std::cout << "Caught Child: " << e.what() << "\n";
	}
	catch(std::exception& e)
	{
		std::cout << "Caught Parent: " << e.what() << "\n";
	}
}
