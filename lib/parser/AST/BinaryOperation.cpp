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


#include "silicon/parser/AST/BinaryOperation.h"
#include "macros.h"


using namespace std;
using namespace silicon::parser::AST;


BinaryOperation::BinaryOperation(const string &location, binary_operation_t op, Node *left, Node *right) : Node{
        location}, op(op), left(MOVE(left)), right(MOVE(right)) {}

BinaryOperation::BinaryOperation(BinaryOperation *node) : BinaryOperation{node->location, node->op, node->left,
                                                                          node->right} {}

node_t BinaryOperation::node_type() {
    return node_t::BINARY_OP;
}
