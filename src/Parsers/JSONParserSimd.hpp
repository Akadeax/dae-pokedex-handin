#ifndef JSONPARSERSIMD_H
#define JSONPARSERSIMD_H

#ifdef parser_simdjson

#include "JSONParser.hpp"

class JSONParserSimd : public JSONParser
{
public:
	JSONParserSimd();
};

#endif
#endif
