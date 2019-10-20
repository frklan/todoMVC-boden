
/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#pragma once

#include <nlohmann/json.hpp>
#include <string>

namespace y44::todomvc {
  struct Todo {
    std::string todoText;
    bool isCompleted;
  };

  void to_json(nlohmann::json& j, const Todo& todo);
  void from_json(const nlohmann::json& j, Todo& todo);
}
