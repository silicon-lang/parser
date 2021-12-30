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


#ifndef SILICONPARSER_BREAK_H
#define SILICONPARSER_BREAK_H


#include "Node.h"


namespace silicon::parser::AST {

    class Break : virtual public Node {
    public:
        explicit Break(const std::string &location);

        explicit Break(Break *node);

        node_t node_type() override;
    };

}


#endif //SILICONPARSER_BREAK_H
