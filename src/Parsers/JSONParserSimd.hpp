#ifndef JSONPARSERSIMD_H
#define JSONPARSERSIMD_H

#ifdef parser_simdjson

#include <simdjson/dom/parser.h>
#include "JSONParser.hpp"

class JSONParserSimd : public JSONParser
{
public:
	JSONParserSimd();

	std::unique_ptr<JSONDocument> Parse(const std::string& jsonString) override;

private:
	simdjson::dom::parser m_Parser{};
};

#endif
#endif
