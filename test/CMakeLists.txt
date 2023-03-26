add_subdirectory(./lib/googletest-main)
set(gtest_SOURCE_DIR, ./lib/googletest-main/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp)
add_executable(runLabProgrammazioneTests ${TEST_SOURCE_FILES})
target_link_libraries(runLabProgrammazioneTests gtest gtest_main core)