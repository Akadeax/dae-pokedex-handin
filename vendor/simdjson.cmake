function(fetch_and_link target)
	message(STATUS "== LINKING SIMDJSON ==")

	FetchContent_Declare(
		simd_json
		GIT_REPOSITORY https://github.com/simdjson/simdjson.git
		GIT_SHALLOW TRUE
		GIT_TAG tags/v3.10.1
	)
	FetchContent_MakeAvailable(simd_json)

	target_link_libraries(
		${target}
		PRIVATE simdjson
	)

	target_include_directories(
		${target}
		PRIVATE
		"${simd_json_SOURCE_DIR}/include"
	)

	target_compile_definitions(${target} PRIVATE parser_simdjson)
endfunction()
