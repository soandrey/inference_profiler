set(INFERENCE_SRC torch_inferencer.cpp)

add_library(inference ${INFERENCE_SRC})

target_include_directories(inference INTERFACE ${CMAKE_CURRENT_LIST_DIR})