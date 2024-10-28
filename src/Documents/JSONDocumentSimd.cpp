#include "JSONDocumentSimd.hpp"

#ifdef parser_simdjson

JSONDocumentSimd::JSONDocumentSimd(simdjson::dom::element json)
{
	m_Document = json;
}

std::unique_ptr<JSONDocument> JSONDocumentSimd::At(const std::string& index)
{
	return std::make_unique<JSONDocumentSimd>(m_Document[index]);
}

std::unique_ptr<JSONDocument> JSONDocumentSimd::At(size_t index)
{
	return std::make_unique<JSONDocumentSimd>(m_Document.at(index));
}

std::string JSONDocumentSimd::GetAsString() const
{
	return std::string{ m_Document.get_c_str() };
}

int64_t JSONDocumentSimd::GetAsInteger() const
{
	return m_Document.get_int64();
}

std::vector<std::unique_ptr<JSONDocument>> JSONDocumentSimd::GetAsVector() const
{
	std::vector<std::unique_ptr<JSONDocument>> result{};

	for (auto el : m_Document.get_array())
	{
		result.push_back(std::make_unique<JSONDocumentSimd>(el));
	}

	return result;
}

std::string JSONDocumentSimd::Dump()
{
	throw FunctionNotImplementedException{};
}

#endif
