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
#include "silicon/parser/AST/Variable.h"
#include "macros.h"


using namespace std;
using namespace silicon::parser::AST;


Variable::Variable(const string &location, string name, Node *context) : Node{location}, name(MOVE(name)),
                                                                         context(MOVE(context)) {}

Variable::Variable(Variable *node) : Variable{node->location, node->name, node->context} {}

node_t Variable::node_type() {
    return node_t::VARIABLE;
}
