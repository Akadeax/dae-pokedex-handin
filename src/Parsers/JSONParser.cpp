#include "JSONParser.hpp"

#ifdef parser_nlohmann
#include "JSONParserNlohmann.hpp"
#elif parser_simdjson
#include "JSONParserSimd.hpp"
#endif


std::unique_ptr<JSONParser> CreateParser()
{
#ifdef parser_nlohmann
	return std::make_unique<JSONParserNlohmann>();
#elif parser_simdjson
	return std::make_unique<JSONParserSimd>();
#endif
}
