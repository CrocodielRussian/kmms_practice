target_sources(bubble_sort_split
	PRIVATE
		bubble_sort.cpp
		bubble_sort.hpp
)

target_include_directories(bubble_sort_split PRIVATE
	"${PROJECT_SOURCE_DIR}/sorting"
)
