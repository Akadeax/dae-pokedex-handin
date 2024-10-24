#include "JSONParserSimd.hpp"

#ifdef parser_simdjson

#include <iostream>
#include "simdjson.h"
using namespace simdjson;

JSONParserSimd::JSONParserSimd()
	: JSONParser()
{
		std::cout << "Created Simd parser\n";

	// ondemand::parser parser;
	// std::string json{ "{ \"test\": 123 }" };
	// ondemand::document decoded = parser.iterate(json);
	// std::cout << decoded["test"] << std::endl;
}

#endif
