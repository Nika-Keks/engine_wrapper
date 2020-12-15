#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <functional>

#include "Unpacking.h"



class Wrapper
{
private:
	std::function<int()> f;
	std::vector<std::pair<std::string, int>> args;

	template<typename SubjectT, typename ...ArgsT, size_t ... Indices>
	Wrapper(SubjectT*, int(SubjectT::* methPtr)(ArgsT...), const std::vector<std::pair<std::string, int>>&, PackIndices<Indices...>);

	void setNewArgs(std::map<std::string, int> newArgs);
public:
	template<typename SubjectT, typename ...ArgsT>
	Wrapper(SubjectT*, int(SubjectT::* methPtr)(ArgsT...), const std::vector<std::pair<std::string, int>>&);

	int exetute(const std::map<std::string, int>& newArgs);

};

template<typename SubjectT, typename ...ArgsT>
Wrapper::Wrapper(SubjectT* subjPtr, int(SubjectT::* methPtr)(ArgsT...), const std::vector<std::pair<std::string, int>>&  args)
	:Wrapper(subjPtr, methPtr, args, CreatePackIndices<sizeof...(ArgsT)>::type())
{
}

template<typename SubjectT, typename ...ArgsT, size_t ... Indices>
Wrapper::Wrapper(SubjectT* subjPtr, int(SubjectT::* methPtr)(ArgsT...), const std::vector<std::pair<std::string, int>>& args, PackIndices<Indices...>)
{
	this->args = args;
	f = std::bind(methPtr, subjPtr, std::ref(this->args[Indices].second)...);	
}

