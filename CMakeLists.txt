project(isg-ng)
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(CMAKE_AUTOMOC_RELAXED_MODE TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic-errors -Wall -Wextra")

set(QT_USE_IMPORTED_TARGETS TRUE)

find_package(Qt4 REQUIRED QtCore QtGui)

include(${QT_USE_FILE})

set(isg-ng_SRCS
    main.cpp
    InstructionEdit.cxx
    InstructionPart.cxx
    TextPart.cxx
    TagPart.cxx
    Instruction.cxx
    BitsTagPart.cxx
    ArgumentTagPart.cxx
)

add_executable(isg-ng ${isg-ng_SRCS})
set_target_properties(isg-ng PROPERTIES AUTOMOC TRUE)

target_link_libraries(isg-ng ${QT_LIBRARIES})

install(TARGETS isg-ng RUNTIME DESTINATION bin)
