add_executable(example)
target_sources(example
    PRIVATE
        main.cpp
        SampleGame.h
        SampleGame.cpp
)
target_link_libraries(example
    PRIVATE
        powderpuff
	${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
)
add_custom_command(TARGET example POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/face.png
        $<TARGET_FILE_DIR:example>
)
