include_directories(${CMAKE_SOURCE_DIR}/include/)

add_executable(eBay eBay.cpp)
add_test(eBay ./eBay)

add_executable(huawei1 huawei1.cpp)
add_executable(huawei2 huawei2.cpp)
add_executable(huawei3 huawei3.cpp)
add_executable(huawei4 huawei4.cpp)
add_executable(huawei5 huawei5.cpp)
add_executable(huawei6 huawei6.cpp)
add_executable(huawei7 huawei7.cpp)
add_executable(huawei8 huawei8.cpp)

add_executable(sensetime sensetime.cpp)
add_test(sensetime ./sensetime)
