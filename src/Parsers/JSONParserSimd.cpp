#include "JSONParserSimd.hpp"

#ifdef parser_simdjson

#include <iostream>
#include "simdjson.h"
using namespace simdjson;

#include "Documents/JSONDocumentSimd.hpp"

JSONParserSimd::JSONParserSimd()
{
	std::cout << "== Initialized Simdjson parser ==\n";
}

std::unique_ptr<JSONDocument> JSONParserSimd::Parse(const std::string& jsonString)
{
    return std::make_unique<JSONDocumentSimd>(m_Parser.parse(jsonString));
}

#endif
