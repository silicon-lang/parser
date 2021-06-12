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
#include "silicon/parser/Context.h"
#include "macros.h"


using namespace std;
using namespace silicon::parser;
using namespace silicon::parser::AST;


Context::Context(string &filename) : filename(filename) {
    location.begin.filename = &filename;
    location.end.filename = &filename;
}

string Context::parse_location() const {
    string l = (location.begin.filename ? location.begin.filename->c_str() : "(undefined)");

    l += ":" + to_string(location.begin.line);

    l += ":" + to_string(location.begin.column) + "-" + to_string(location.end.column);

    return l;
}

void Context::optimize(bool optimize) {
    should_optimize = optimize;
}

/* ------------------------- AST ------------------------- */

void Context::def_library(vector<Node *> statements) {
    library = def_code_block(MOVE(statements));
}

Node *Context::def_code_block(vector<Node *> statements) {
    CREATE_NODE(CodeBlock, MOVE(statements))
}

/* ------------------------- AST -> Literals ------------------------- */

Node *Context::def_bool(bool value) {
    CREATE_NODE(BooleanLiteral, value)
}

Node *Context::def_num(string value) {
    CREATE_NODE(NumberLiteral, MOVE(value))
}

/* ------------------------- AST -> Object & Interface ------------------------- */

Node *Context::def_plain_object(map<string, Node *> properties) {
    CREATE_NODE(PlainObject, MOVE(properties))
}

Node *Context::def_interface(string name, vector<pair<string, string>> properties, vector<string> bases) {
    CREATE_NODE(Interface, MOVE(name), MOVE(bases), MOVE(properties))
}

/* ------------------------- AST -> Variable & Constant ------------------------- */

Node *Context::def_variable(string name, Node *context) {
    CREATE_NODE(Variable, MOVE(name), MOVE(context))
}

Node *Context::def_variable_definition(string name, string type) {
    CREATE_NODE(VariableDefinition, MOVE(name), MOVE(type))
}

/* ------------------------- AST -> Operations ------------------------- */

Node *Context::def_op(binary_operation_t op, Node *left, Node *right) {
    CREATE_NODE(BinaryOperation, op, MOVE(left), MOVE(right))
}

Node *Context::def_op(unary_operation_t op, Node *node, bool suffix) {
    CREATE_NODE(UnaryOperation, op, MOVE(node), suffix)
}

/* ------------------------- AST -> If ------------------------- */

Node *Context::def_if(Node *condition, Node *then_statements, Node *else_statements) {
    CREATE_NODE(If, MOVE(condition), MOVE(then_statements), MOVE(else_statements))
}

/* ------------------------- AST -> Loops ------------------------- */

Node *Context::def_break() {
    CREATE_NODE(Break)
}

Node *Context::def_continue() {
    CREATE_NODE(Continue)
}

Node *Context::def_loop(Node *body) {
    CREATE_NODE(Loop, MOVE(body))
}

Node *Context::def_while(Node *condition, Node *body) {
    CREATE_NODE(While, MOVE(condition), MOVE(body))
}

Node *Context::def_for(Node *definition, Node *condition, Node *stepper,
                                  Node *body) {
    CREATE_NODE(For, MOVE(definition), MOVE(condition), MOVE(stepper), MOVE(body))
}

/* ------------------------- AST -> Function ------------------------- */

pair<string, string> Context::def_arg(string name, string type) {
    return make_pair(MOVE(name), MOVE(type));
}

Node *Context::def_prototype(string name, vector<pair<string, string>> arguments, string return_type) {
    CREATE_NODE(Prototype, MOVE(name), MOVE(return_type), MOVE(arguments))
}

Node *Context::def_return(Node *value) {
    CREATE_NODE(Return, MOVE(value))
}

Node *Context::def_fn(Node *prototype, Node *body) {
    CREATE_NODE(Function, MOVE(prototype), MOVE(body))
}

Node *Context::def_fn_call(string callee, vector<Node *> args) {
    CREATE_NODE(FunctionCall, MOVE(callee), MOVE(args))
}
