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


#ifndef SILICONPARSER_MACROS_H
#define SILICONPARSER_MACROS_H


#define MOVE(V) std::move(V)

#define CREATE_NODE(NODE, ...) auto *new_node = new NODE(parse_location(), ##__VA_ARGS__); \
                               if (should_optimize) new_node->optimize();                  \
                               return new_node;

#define REPLACE_ALL(STRING, FROM, TO) size_t replace_all_start_pos = 0;                                                                         \
                                      std::string replace_all_from = FROM;                                                                      \
                                      std::string replace_all_to = TO;                                                                          \
                                      while ((replace_all_start_pos = STRING.find(replace_all_from, replace_all_start_pos)) != string::npos) {  \
                                          STRING.replace(replace_all_start_pos, replace_all_from.length(), replace_all_to);                     \
                                          replace_all_start_pos += replace_all_to.length();                                                     \
                                      }

#endif //SILICONPARSER_MACROS_H
