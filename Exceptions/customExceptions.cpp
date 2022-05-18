#include <iostream>
#include <exception>

class CustomException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Something Bad Happened";
	}
};

class Test
{
public:
	void canThrowException()
	{
		throw CustomException();
	}
};

int main()
{
	Test test;

	try
	{
		test.canThrowException();
	}
	catch(CustomException& e)
	{
		std::cout << e.what() << std::endl;
	}
}
