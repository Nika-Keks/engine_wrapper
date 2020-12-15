#include "Wrapper.h"

void Wrapper::setNewArgs(std::map<std::string, int> newArgs)
{
	for (auto& pair : args)
		pair.second = newArgs[pair.first];
}

int Wrapper::exetute(const std::map<std::string, int>& newArgs)
{
	if (args.size() == newArgs.size())
	{
		for (const auto& pair : args)
			if (newArgs.find(pair.first) == newArgs.end())
				return f();
		setNewArgs(newArgs);
	}
	return f();
}
