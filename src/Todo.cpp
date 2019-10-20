/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#include "Todo.h"

namespace y44::todomvc {
  void to_json(nlohmann::json& j, const Todo& todo) {
    j = nlohmann::json{{"todoText", todo.todoText},
      {"isCompleted", todo.isCompleted}};
  }

  void from_json(const nlohmann::json& j, Todo& todo) {
    j.at("todoText").get_to(todo.todoText);
    j.at("isCompleted").get_to(todo.isCompleted);
  }
}

