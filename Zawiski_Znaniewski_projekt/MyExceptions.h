#ifndef MY_EXCEPT_H
#define MY_EXCEPT_H

#include <exception>
#include <string>
#include <iostream>

namespace MyRuntimeExceptions {
	class MyRuntimeError : public std::runtime_error
	{
	public:
		MyRuntimeError();
		MyRuntimeError(std::string msg);
	};
}

#endif