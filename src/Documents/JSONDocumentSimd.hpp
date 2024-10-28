#ifndef JSONDOCUMENTSIMD_H
#define JSONDOCUMENTSIMD_H

#ifdef parser_simdjson

#include "JSONDocument.hpp"
#include "simdjson.h"

class JSONDocumentSimd final : public JSONDocument
{
public:
	JSONDocumentSimd() = default;
	explicit JSONDocumentSimd(simdjson::dom::element json);

	~JSONDocumentSimd() override = default;

	std::unique_ptr<JSONDocument> At(const std::string& index) override;
	std::unique_ptr<JSONDocument> At(size_t index) override;

	std::string GetAsString() const override;
	int64_t GetAsInteger() const override;
	std::vector<std::unique_ptr<JSONDocument>> GetAsVector() const override;

	std::string Dump() override;

private:
	simdjson::dom::element m_Document;
};

#endif
#endif
