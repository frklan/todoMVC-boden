/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#pragma once

#include "TodoListDataSource.h"
#include "TodoStore.h"

#include <bdn/ui/Window.h>

namespace y44::todomvc {
  class MainViewController {
    public:
      MainViewController();
      virtual ~MainViewController() = default;

    private:
      std::shared_ptr<bdn::ui::Window> _window;
      std::shared_ptr<bdn::ui::TextField> _newEntryField;
      std::shared_ptr<bdn::ui::ListView> _listView;
      std::shared_ptr<bdn::ui::ContainerView> _mainContainer;

      std::shared_ptr<TodoListDataSource> _todoDataSource;
      std::shared_ptr<TodoStore> _todoStore;
  };
}

