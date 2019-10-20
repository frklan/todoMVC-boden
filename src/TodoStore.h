/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "Todo.h"

namespace y44::todomvc {
  class TodoStore {
    public:
      TodoStore() { std::cout << "TodoStore()\n";}
      void add(const std::string &todoText);
      void remove(size_t index);

      void load();
      void save();

      nlohmann::json todos = std::vector<Todo>();
    
    private:
      std::string todoFilePath();
  };
}

