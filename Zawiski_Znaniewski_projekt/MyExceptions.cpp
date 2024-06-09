#include "MyExceptions.h"

MyRuntimeExceptions::MyRuntimeError::MyRuntimeError() : runtime_error("Blad w funkcjonowaniu programu") {}

MyRuntimeExceptions::MyRuntimeError::MyRuntimeError(std::string msg) : runtime_error(msg.c_str()) {}