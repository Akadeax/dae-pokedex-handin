#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <memory>
#include <string>

#include "Documents/JSONDocument.hpp"

class JSONParser
{
public:
	JSONParser() = default;
	virtual ~JSONParser() = default;

	JSONParser(const JSONParser&) = delete;
	JSONParser(JSONParser&&) noexcept = delete;
	JSONParser& operator=(const JSONParser&) = delete;
	JSONParser& operator=(JSONParser&&) noexcept = delete;

	virtual std::unique_ptr<JSONDocument> Parse(const std::string& jsonString) = 0;
};

std::unique_ptr<JSONParser> CreateParser();

#endif
