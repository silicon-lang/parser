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


#ifndef SILICONPARSER_PROTOTYPE_H
#define SILICONPARSER_PROTOTYPE_H


#include <memory>
#include <string>
#include <vector>
#include "Node.h"


namespace silicon::parser::AST {

    class Prototype : public Node {
    public:
        std::string name;
        std::string return_type;
        std::vector<std::pair<std::string, std::string>> arguments;

        bool is_exported = false;
        bool is_extern = false;
        bool is_variadic = false;

        Prototype(const std::string &location, std::string name, std::string return_type,
                  std::vector<std::pair<std::string, std::string>> arguments);

        node_t node_type() override;

        void make_exported(bool should_export = true);

        void make_extern(bool should_be_extern = true);

        void make_variadic(bool should_be_variadic = true);
    };

}


#endif //SILICONPARSER_PROTOTYPE_H
