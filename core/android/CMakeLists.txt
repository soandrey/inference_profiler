add_library(native-inference SHARED jni_wrapper.cpp)

find_library(log-lib log)

target_link_libraries(native-inference PUBLIC ${log-lib} inference)
