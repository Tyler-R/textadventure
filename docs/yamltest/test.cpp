//Test run with g++ -Wall -I. -g test.cpp -lyaml-cpp -L. -o monsterstest

#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	YAML::Node monster = YAML::LoadFile("monster.yaml");
	std::cout << "Hello";
	return 0;
}
