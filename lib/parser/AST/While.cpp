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
#include "silicon/parser/AST/While.h"
#include "macros.h"


using namespace std;
using namespace silicon::parser::AST;


While::While(const string &location, Node *condition, Node *body) : Node{location}, condition(MOVE(condition)),
                                                                    body(MOVE(body)) {}

node_t While::node_type() {
    return node_t::WHILE;
}

void While::make_do_while(bool should_do_while) {
    is_do_while = should_do_while;
}
