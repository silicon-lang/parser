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


#ifndef SILICONPARSER_PARSER_H
#define SILICONPARSER_PARSER_H


#include <memory>
#include <string>
#include "silicon/parser/Context.h"
#include "silicon/parser/AST/Node.h"


namespace silicon::parser {

    class Parser {
    private:
        Context *ctx;

    public:
        explicit Parser(std::string &input);

        void cursor(const char *cursor);

        void optimize(bool should_optimize = true);

        AST::Node *parse(AST::Node *(*walker)(AST::Node *) = nullptr);
    };

}


#endif //SILICONPARSER_PARSER_H
