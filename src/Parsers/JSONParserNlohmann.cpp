#include "JSONParserNlohmann.hpp"

#ifdef parser_nlohmann

#include <iostream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

JSONParserNlohmann::JSONParserNlohmann()
	: JSONParser()
{
	std::cout << "Created Nlohmann parser\n";
}

#endif
