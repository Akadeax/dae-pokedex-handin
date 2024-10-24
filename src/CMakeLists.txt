add_executable(
	${PROJECT_NAME}
	main.cpp
	Parsers/JSONParser.hpp Parsers/JSONParser.cpp
	Parsers/JSONParserNlohmann.hpp Parsers/JSONParserNlohmann.cpp
	Parsers/JSONParserSimd.hpp Parsers/JSONParserSimd.cpp
)
