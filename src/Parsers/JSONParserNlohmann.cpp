#include "JSONParserNlohmann.hpp"

#ifdef parser_nlohmann

#include "../Documents/JSONDocument.hpp"
#include "../Documents/JSONDocumentNlohmann.hpp"

#include <iostream>
#include "nlohmann/json.hpp"

JSONParserNlohmann::JSONParserNlohmann()
{
	std::cout << "== Initialized Nlohmann parser ==\n";
}

std::unique_ptr<JSONDocument> JSONParserNlohmann::Parse(const std::string& jsonString)
{
	return std::make_unique<JSONDocumentNlohmann>(nlohmann::json::parse(jsonString));
}

#endif
