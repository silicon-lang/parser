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


#include <iostream>
#include "silicon/parser/AST/Node.h"


using namespace std;
using namespace silicon::parser::AST;


Node::Node(const string &location) : location(location) {
}

Node::Node(Node *node) : location(node->location) {
}

void Node::optimize() {
}

bool Node::is_node(node_t t) {
    return t == node_type();
}

void Node::fail(const string &error) noexcept {
    cerr << location << ": " << error << endl;

    exit(1);
}
