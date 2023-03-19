add_executable(GE_Game main.cpp)

include_directories(../Cloud/include)

target_link_libraries(GE_Game Cloud)