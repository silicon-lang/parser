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
#include "silicon/parser/AST/Prototype.h"
#include "macros.h"


using namespace std;
using namespace silicon::parser::AST;


Prototype::Prototype(const string &location, string name, string return_type, vector<pair<string, string>> arguments)
        : Node{location}, name(MOVE(name)), return_type(MOVE(return_type)), arguments(MOVE(arguments)) {}

node_t Prototype::node_type() {
    return node_t::PROTOTYPE;
}

void Prototype::make_exported(bool should_export) {
    is_exported = should_export;
}

void Prototype::make_extern(bool should_be_extern) {
    is_extern = should_be_extern;
}

void Prototype::make_variadic(bool should_be_variadic) {
    is_variadic = should_be_variadic;
}
