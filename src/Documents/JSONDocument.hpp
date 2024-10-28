#ifndef JSONDOCUMENT_H
#define JSONDOCUMENT_H

#include <memory>
#include <string>
#include <vector>

struct FunctionNotImplementedException {};
class JSONDocument
{
public:
	using Ptr = std::unique_ptr<JSONDocument>;

	JSONDocument() = default;
	virtual ~JSONDocument() = default;

	JSONDocument(const JSONDocument&) = delete;
	JSONDocument(JSONDocument&&) noexcept = delete;
	JSONDocument& operator=(const JSONDocument&) = delete;
	JSONDocument& operator=(JSONDocument&&) noexcept = delete;

	virtual std::unique_ptr<JSONDocument> At(const std::string& index) = 0;
	virtual std::unique_ptr<JSONDocument> At(size_t index) = 0;

	virtual std::string GetAsString() const = 0;
	virtual int64_t GetAsInteger() const = 0;
	virtual std::vector<std::unique_ptr<JSONDocument>> GetAsVector() const = 0;

	virtual std::string Dump() = 0;
};

#endif
