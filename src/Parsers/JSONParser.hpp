#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>
#include <memory>

class JSONParser
{
public:
	JSONParser() {}

	JSONParser(const JSONParser&) = delete;
	JSONParser(JSONParser&&) noexcept = delete;
	JSONParser operator=(const JSONParser&) = delete;
	JSONParser operator=(JSONParser&&) noexcept = delete;
};

std::unique_ptr<JSONParser> CreateParser();

#endif
