#ifndef JSONDOCUMENTNLOHMANN_H
#define JSONDOCUMENTNLOHMANN_H

#ifdef parser_nlohmann

#include "JSONDocument.hpp"
#include "nlohmann/json.hpp"

class JSONDocumentNlohmann final : public JSONDocument
{
public:
	JSONDocumentNlohmann() = default;
	explicit JSONDocumentNlohmann(nlohmann::basic_json<> json);

	~JSONDocumentNlohmann() override = default;

	std::unique_ptr<JSONDocument> At(const std::string& index) override;
	std::unique_ptr<JSONDocument> At(size_t index) override;

	std::string GetAsString() const override;
	int64_t GetAsInteger() const override;
	std::vector<std::unique_ptr<JSONDocument>> GetAsVector() const override;

	std::string Dump() override;

private:
	nlohmann::basic_json<> m_Document;
};

#endif
#endif