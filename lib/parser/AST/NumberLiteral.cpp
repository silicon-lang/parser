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


#include "silicon/parser/AST/NumberLiteral.h"
#include "macros.h"


using namespace std;
using namespace silicon::parser::AST;


NumberLiteral::NumberLiteral(const string &location, string value) : Node{location} {
    REPLACE_ALL(value, "_", "")

    this->value = value;
}

NumberLiteral::NumberLiteral(NumberLiteral *node) : NumberLiteral{node->location, node->value} {
}

node_t NumberLiteral::node_type() {
    return node_t::NUMBER_LIT;
}
