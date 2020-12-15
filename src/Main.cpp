#include<iostream>
#include <vector>
#include <sstream>

#include "Subject.h"
#include "Wrapper.h"
#include "Engine.h"


int main()
{
	Subject* subj = new Subject();

	Wrapper wrapper(subj, &Subject::f3, { { "arg1", 0 }, { "arg2", 0 } });
	
	Engine engine;

	engine.registerCommand(&wrapper, "command1");

	std::cout << engine.execute("command1", { {"arg1", 1}, {"arg2", 2} }) << std::endl;
	
	delete subj;

	return 0;
} 

