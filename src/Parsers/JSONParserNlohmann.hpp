#ifndef JSONPARSERNLOHMANN_H
#define JSONPARSERNLOHMANN_H

#ifdef parser_nlohmann

#include "JSONParser.hpp"

class JSONParserNlohmann : public JSONParser
{
public:
	JSONParserNlohmann();

	std::unique_ptr<JSONDocument> Parse(const std::string& jsonString);
};

#endif
#endif
