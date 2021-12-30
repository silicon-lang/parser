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


#ifndef SILICONPARSER_BINARYOPERATION_H
#define SILICONPARSER_BINARYOPERATION_H


#include <memory>
#include "Node.h"


namespace silicon::parser::AST {

    enum class binary_operation_t {
        ASSIGN,
        STAR,
        SLASH,
        PERCENT,
        PLUS,
        MINUS,
        CARET,
        AND,
        OR,
        DOUBLE_LESSER,
        DOUBLE_BIGGER,
        TRIPLE_BIGGER,
        LESSER,
        LESSER_EQUAL,
        EQUAL,
        NOT_EQUAL,
        BIGGER_EQUAL,
        BIGGER,
        STAR_STAR,
        AND_AND,
        OR_OR,
        CAST,
    };

    class BinaryOperation : virtual public Node {
    public:
        binary_operation_t op;
        Node *left;
        Node *right;

        BinaryOperation(const std::string &location, binary_operation_t op, Node *left, Node *right);

        explicit BinaryOperation(BinaryOperation *node);

        node_t node_type() override;
    };

}


#endif //SILICONPARSER_BINARYOPERATION_H
