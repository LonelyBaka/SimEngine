file(GLOB hdrs "${CMAKE_SOURCE_DIR}/include/SmartHouseData/*.h*") #��������� � ���������� hdrs ��� ����� � ����������� .h
file(GLOB srcs "*.cpp")#��������� � ���������� srcs ��� ����� � ����������� .h

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

add_library(SmartHouseData STATIC ${srcs} ${hdrs}) 

