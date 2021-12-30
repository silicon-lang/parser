//
//   Copyright 2021 Ardalan Amini
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//


#ifndef SILICONPARSER_NODE_H
#define SILICONPARSER_NODE_H


#include <string>


namespace silicon::parser {

    class Context;

}

namespace silicon::parser::AST {

    enum class node_t {
        NODE,

        TYPE,

        INTERFACE,

        CODE_BLOCK,

        BOOLEAN_LIT,
        NUMBER_LIT,
        CHAR_LIT,

        STRING,
        PLAIN_OBJECT,
        ARRAY,

        NULL_PTR,

        VARIABLE_DEFINITION,
        VARIABLE,

        BINARY_OP,
        UNARY_OP,

        LOOP,
        WHILE,
        FOR,
        BREAK,
        CONTINUE,

        IF,

        FUNCTION,
        PROTOTYPE,
        FUNCTION_CALL,
        RETURN,
    };

    class Node {
    protected:
        const std::string &location;

        explicit Node(const std::string &location);

        explicit Node(Node *node);

        void optimize();

    public:
        virtual ~Node() = default;

        virtual node_t node_type() = 0;

        bool is_node(node_t node_type);

        void fail(const std::string &error) noexcept __attribute__ ((__noreturn__));

        friend class silicon::parser::Context;
    };

}


#endif //SILICONPARSER_NODE_H
