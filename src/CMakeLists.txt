add_executable(
	${PROJECT_NAME}
	main.cpp
	Parsers/JSONParser.hpp Parsers/JSONParser.cpp
	Parsers/JSONParserNlohmann.hpp Parsers/JSONParserNlohmann.cpp
	Parsers/JSONParserSimd.hpp Parsers/JSONParserSimd.cpp
	Documents/JSONDocument.hpp
	Documents/JSONDocumentNlohmann.hpp Documents/JSONDocumentNlohmann.cpp
	Documents/JSONDocumentSimd.hpp Documents/JSONDocumentSimd.cpp
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/content $<TARGET_FILE:${PROJECT_NAME}>/../content
)