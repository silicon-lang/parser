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


Node *default_walker(Node *node) {
    return node;
}

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

void Context::set_walker(AST::Node *(*w)(Node *)) {
    walker = w;
}

AST::Node *Context::walk(Node *node) {
    if (walker) return walker(node);

    return default_walker(node);
}

/* ------------------------- AST ------------------------- */

void Context::def_library(vector<AST::Node *> statements) {
    library = def_code_block(MOVE(statements));
}

AST::Node *Context::def_code_block(vector<AST::Node *> statements) {
    CREATE_NODE(CodeBlock, MOVE(statements))
}

/* ------------------------- AST -> Types ------------------------- */

AST::Node *Context::def_type(string name) {
    CREATE_NODE(Type, MOVE(name))
}

/* ------------------------- AST -> Literals ------------------------- */

AST::Node *Context::def_bool(bool value) {
    CREATE_NODE(BooleanLiteral, value)
}

AST::Node *Context::def_num(string value) {
    CREATE_NODE(NumberLiteral, MOVE(value))
}

/* ------------------------- AST -> String ------------------------- */

AST::Node *Context::def_string(string value) {
    CREATE_NODE(String, MOVE(value))
}

/* ------------------------- AST -> Object & Interface ------------------------- */

AST::Node *Context::def_plain_object(map<string, AST::Node *> properties) {
    CREATE_NODE(PlainObject, MOVE(properties))
}

AST::Node *Context::def_interface(string name, vector<pair<string, AST::Node *>> properties, vector<string> bases) {
    CREATE_NODE(Interface, MOVE(name), MOVE(bases), MOVE(properties))
}

/* ------------------------- AST -> Variable & Constant ------------------------- */

AST::Node *Context::def_variable(string name, AST::Node *context) {
    CREATE_NODE(Variable, MOVE(name), MOVE(context))
}

AST::Node *Context::def_variable_definition(string name, AST::Node *type) {
    CREATE_NODE(VariableDefinition, MOVE(name), MOVE(type))
}

/* ------------------------- AST -> Operations ------------------------- */

AST::Node *Context::def_op(binary_operation_t op, AST::Node *left, AST::Node *right) {
    CREATE_NODE(BinaryOperation, op, MOVE(left), MOVE(right))
}

AST::Node *Context::def_op(unary_operation_t op, AST::Node *node, bool suffix) {
    CREATE_NODE(UnaryOperation, op, MOVE(node), suffix)
}

/* ------------------------- AST -> If ------------------------- */

AST::Node *Context::def_if(AST::Node *condition, AST::Node *then_statements, AST::Node *else_statements) {
    CREATE_NODE(If, MOVE(condition), MOVE(then_statements), MOVE(else_statements))
}

/* ------------------------- AST -> Loops ------------------------- */

AST::Node *Context::def_break() {
    CREATE_NODE(Break)
}

AST::Node *Context::def_continue() {
    CREATE_NODE(Continue)
}

AST::Node *Context::def_loop(AST::Node *body) {
    CREATE_NODE(Loop, MOVE(body))
}

AST::Node *Context::def_while(AST::Node *condition, AST::Node *body) {
    CREATE_NODE(While, MOVE(condition), MOVE(body))
}

AST::Node *Context::def_for(AST::Node *definition, AST::Node *condition, AST::Node *stepper,
                       AST::Node *body) {
    CREATE_NODE(For, MOVE(definition), MOVE(condition), MOVE(stepper), MOVE(body))
}

/* ------------------------- AST -> Function ------------------------- */


pair<string, AST::Node *> Context::def_arg(string name, AST::Node *type) {
    return make_pair(MOVE(name), type);
}

AST::Node *Context::def_prototype(string name, vector<pair<string, AST::Node *>> arguments, AST::Node *return_type) {
    CREATE_NODE(Prototype, MOVE(name), return_type, MOVE(arguments))
}

AST::Node *Context::def_return(AST::Node *value) {
    CREATE_NODE(Return, MOVE(value))
}

AST::Node *Context::def_fn(AST::Node *prototype, AST::Node *body) {
    CREATE_NODE(Function, MOVE(prototype), MOVE(body))
}

AST::Node *Context::def_fn_call(string callee, vector<AST::Node *> args) {
    CREATE_NODE(FunctionCall, MOVE(callee), MOVE(args))
}
