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


#include <utility>
#include "silicon/parser/AST/If.h"
#include "macros.h"


using namespace std;
using namespace silicon::parser::AST;


If::If(const string &location, Node *condition, Node *then_statements, Node *else_statements) : Node{
        location}, condition(MOVE(condition)), then_statements(MOVE(then_statements)), else_statements(
        MOVE(else_statements)) {}

If::If(If *node) : If{node->location, node->condition, node->then_statements, node->else_statements} {}

node_t If::node_type() {
    return node_t::IF;
}

void If::set_else(Node *statements) {
    else_statements = MOVE(statements);
}

void If::make_inline(bool should_inline) {
    is_inline = should_inline;
}
