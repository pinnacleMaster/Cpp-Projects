#ifndef EXCEPTIONS_HPP
#define	EXCEPTIONS_HPP
#include <string>
using std::string;

class Exception{
public:
	Exception(const string& s) : data(s) {}
	const string& getException() {return data;}
private:
	string data;
};

class StackEmpty: public Exception{
public:
	StackEmpty(const string& s): Exception(s) {}
};

#endif /* EXCEPTIONS_HPP */