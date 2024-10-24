function(fetch_and_link target)
	message(STATUS "== LINKING NLOHMANN ==")
	FetchContent_Declare(
		nlohmann_json
		URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
	)
	FetchContent_MakeAvailable(nlohmann_json)

	target_link_libraries(
		${target}
		PRIVATE nlohmann_json
	)

	target_compile_definitions(${target} PRIVATE parser_nlohmann)
endfunction()
