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
#include "silicon/parser/AST/FunctionCall.h"
#include "macros.h"


using namespace std;
using namespace silicon::parser::AST;


FunctionCall::FunctionCall(const string &location, string callee, vector<Node *> args) : Node{location},
                                                                                         callee(MOVE(callee)),
                                                                                         args(MOVE(args)) {}

FunctionCall::FunctionCall(FunctionCall *node) : FunctionCall{node->location, node->callee, node->args} {}

node_t FunctionCall::node_type() {
    return node_t::FUNCTION_CALL;
}
