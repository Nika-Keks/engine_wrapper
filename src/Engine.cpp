#include "Engine.h"

void Engine::registerCommand(Wrapper* wrapper, const std::string& comName)
{
	if (wrapper != nullptr)
		commands.insert(std::pair<std::string, Wrapper*>(comName, wrapper));
}

int Engine::execute(const std::string& comName, const std::map<std::string, int>& newArgs)
{
	if (commands.find(comName) != commands.end())
		return commands[comName]->exetute(newArgs);
	return 0;
}
