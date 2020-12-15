#pragma once
#include "Wrapper.h"


class Engine
{
private:
	std::map<std::string, Wrapper*> commands;

public:
	void registerCommand(Wrapper* wrapper, const std::string& comName);
	int execute(const std::string&, const std::map<std::string, int>& newArgs);
};