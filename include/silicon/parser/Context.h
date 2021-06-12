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


#ifndef SILICONPARSER_CONTEXT_H
#define SILICONPARSER_CONTEXT_H


#include <memory>
#include <map>
#include <string>
#include <vector>
#include "silicon/parser/AST/Node.h"
#include "silicon/parser/AST/CodeBlock.h"
#include "silicon/parser/AST/BooleanLiteral.h"
#include "silicon/parser/AST/NumberLiteral.h"
#include "silicon/parser/AST/PlainObject.h"
#include "silicon/parser/AST/Interface.h"
#include "silicon/parser/AST/Variable.h"
#include "silicon/parser/AST/VariableDefinition.h"
#include "silicon/parser/AST/BinaryOperation.h"
#include "silicon/parser/AST/UnaryOperation.h"
#include "silicon/parser/AST/If.h"
#include "silicon/parser/AST/Break.h"
#include "silicon/parser/AST/Continue.h"
#include "silicon/parser/AST/Loop.h"
#include "silicon/parser/AST/While.h"
#include "silicon/parser/AST/For.h"
#include "silicon/parser/AST/Prototype.h"
#include "silicon/parser/AST/Return.h"
#include "silicon/parser/AST/Function.h"
#include "silicon/parser/AST/FunctionCall.h"
#include "silicon/parser/location.hh"


namespace silicon::parser {

    class Context {
    protected:
        [[nodiscard]] std::string parse_location() const;

    public:
        const char *cursor{};
        yy::location location;

        const std::string &filename;

        bool should_optimize = false;

        AST::Node *library = nullptr;

        explicit Context(std::string &filename);

        void optimize(bool should_optimize = true);

        /* ------------------------- AST ------------------------- */

        void def_library(std::vector<AST::Node *> statements = {});

        AST::Node *def_code_block(std::vector<AST::Node *> statements = {});

        /* ------------------------- AST -> Literals ------------------------- */

        AST::Node *def_bool(bool value);

        AST::Node *def_num(std::string value);

        /* ------------------------- AST -> Object & Interface ------------------------- */

        AST::Node *def_plain_object(std::map<std::string, AST::Node *> properties);

        AST::Node *
        def_interface(std::string name, std::vector<std::pair<std::string, std::string>> properties,
                      std::vector<std::string> bases = {});

        /* ------------------------- AST -> Variable & Constant ------------------------- */

        AST::Node *def_variable(std::string name, AST::Node *context = nullptr);

        AST::Node *def_variable_definition(std::string name, std::string type);

        /* ------------------------- AST -> Operations ------------------------- */

        AST::Node *
        def_op(AST::binary_operation_t op, AST::Node *left, AST::Node *right);

        AST::Node *
        def_op(AST::unary_operation_t op, AST::Node *node, bool suffix = false);

        /* ------------------------- AST -> If ------------------------- */

        AST::Node *def_if(AST::Node *condition, AST::Node *then_statements, AST::Node *else_statements = {});

        /* ------------------------- AST -> Loops ------------------------- */

        AST::Node *def_break();

        AST::Node *def_continue();

        AST::Node *def_loop(AST::Node *body);

        AST::Node *def_while(AST::Node *condition, AST::Node *body);

        AST::Node *def_for(AST::Node *definition, AST::Node *condition,
                           AST::Node *stepper, AST::Node *body);

        /* ------------------------- AST -> Function ------------------------- */

        static std::pair<std::string, std::string> def_arg(std::string name, std::string type);

        AST::Node *def_prototype(std::string name, std::vector<std::pair<std::string, std::string>> arguments,
                                 std::string return_type);

        AST::Node *def_return(AST::Node * = nullptr);

        AST::Node *def_fn(AST::Node *prototype, AST::Node *body = nullptr);

        AST::Node *def_fn_call(std::string callee, std::vector<AST::Node *> args = {});
    };

}


#endif //SILICONPARSER_CONTEXT_H
