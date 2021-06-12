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


#include "silicon/parser/Parser.h"
#include "silicon/parser/BisonParser.h"


using namespace std;
using namespace silicon::parser;
using namespace silicon::parser::AST;


Parser::Parser(string &input) {
    ctx = new Context(input);
}

void Parser::cursor(const char *cursor) {
    ctx->cursor = cursor;
}

void Parser::optimize(bool should_optimize) {
    ctx->optimize(should_optimize);
}

Node *Parser::parse() {
    yy::Parser parser(*ctx);

    parser.parse();

    return ctx->library;
}
