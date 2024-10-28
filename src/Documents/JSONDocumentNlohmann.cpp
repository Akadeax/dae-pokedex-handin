#include "JSONDocumentNlohmann.hpp"

#ifdef parser_nlohmann

JSONDocumentNlohmann::JSONDocumentNlohmann(nlohmann::basic_json<> json)
{
	m_Document = std::move(json);
}

std::unique_ptr<JSONDocument> JSONDocumentNlohmann::At(const std::string& index)
{
	return std::make_unique<JSONDocumentNlohmann>(m_Document.at(index));
}

std::unique_ptr<JSONDocument> JSONDocumentNlohmann::At(size_t index)
{
	return std::make_unique<JSONDocumentNlohmann>(m_Document.at(index));
}

std::string JSONDocumentNlohmann::GetAsString() const
{
    return m_Document.get<std::string>();
}

int64_t JSONDocumentNlohmann::GetAsInteger() const
{
    return m_Document.get<int64_t>();
}

std::vector<std::unique_ptr<JSONDocument>> JSONDocumentNlohmann::GetAsVector() const
{
    std::vector<std::unique_ptr<JSONDocument>> result{};

	for (auto el : m_Document)
	{
		result.push_back(std::make_unique<JSONDocumentNlohmann>(el));
	}

	return result;
}

std::string JSONDocumentNlohmann::Dump()
{
	return m_Document.dump();
}

#endif
