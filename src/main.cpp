#include <iostream>
#include <string>
#include "Parsers/JSONParser.hpp"

int main()
{
	std::unique_ptr<JSONParser> parser{ CreateParser() };
}
