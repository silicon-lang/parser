cmake_minimum_required(VERSION 3.19)

project(SiliconParser VERSION 0.2.0 DESCRIPTION "Silicon Programming Language Parser")

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(SILICON_PARSER_INPUT_DIRECTORY ${PROJECT_BINARY_DIR}/include/silicon/parser)
file(MAKE_DIRECTORY ${SILICON_PARSER_INPUT_DIRECTORY})

# ------------------------- BISON ----------------------------------

set(SILICON_PARSER_BISON_INPUT ${PROJECT_SOURCE_DIR}/lib/parser.y)
set(SILICON_PARSER_BISON_OUTPUT ${SILICON_PARSER_INPUT_DIRECTORY}/BisonParser.re)
set(SILICON_PARSER_BISON_HEADER ${SILICON_PARSER_INPUT_DIRECTORY}/BisonParser.h)

FIND_PACKAGE(BISON 3.8 REQUIRED)

message(STATUS "Using Bison ${BISON_VERSION}")

BISON_TARGET(SILICON_PARSER ${SILICON_PARSER_BISON_INPUT} ${SILICON_PARSER_BISON_OUTPUT}
        DEFINES_FILE ${SILICON_PARSER_BISON_HEADER}
        VERBOSE
        )

# ------------------------- RE2C -----------------------------------

set(SILICON_PARSER_RE2C_OUTPUT ${SILICON_PARSER_INPUT_DIRECTORY}/BisonParser.cpp)

FIND_PACKAGE(RE2C 2.2 REQUIRED)

message(STATUS "Using RE2C ${RE2C_VERSION}")

RE2C_TARGET(
        NAME SILICON_PARSER
        INPUT ${BISON_SILICON_PARSER_OUTPUT_SOURCE}
        OUTPUT ${SILICON_PARSER_RE2C_OUTPUT}
)

# ------------------------- SILICON PARSER -------------------------

include_directories(BEFORE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/lib
        ${PROJECT_BINARY_DIR}/include
        )

add_library(SiliconParser
        STATIC
        ${SILICON_PARSER_RE2C_OUTPUT}
        lib/parser/Parser.cpp
        lib/parser/Context.cpp
        lib/parser/AST/Node.cpp
        lib/parser/AST/CodeBlock.cpp
        lib/parser/AST/BooleanLiteral.cpp
        lib/parser/AST/NumberLiteral.cpp
        lib/parser/AST/PlainObject.cpp
        lib/parser/AST/Interface.cpp
        lib/parser/AST/Variable.cpp
        lib/parser/AST/VariableDefinition.cpp
        lib/parser/AST/BinaryOperation.cpp
        lib/parser/AST/UnaryOperation.cpp
        lib/parser/AST/If.cpp
        lib/parser/AST/Break.cpp
        lib/parser/AST/Continue.cpp
        lib/parser/AST/Loop.cpp
        lib/parser/AST/While.cpp
        lib/parser/AST/For.cpp
        lib/parser/AST/Prototype.cpp
        lib/parser/AST/Return.cpp
        lib/parser/AST/Function.cpp
        lib/parser/AST/FunctionCall.cpp
        )
