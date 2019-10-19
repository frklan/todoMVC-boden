/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#pragma once

#include <bdn/ui/Window.h>

namespace y44::todomvc {
  class MainViewController {
    public:
     MainViewController();
     virtual ~MainViewController() = default;

    private:
     std::shared_ptr<bdn::ui::Window> _window;
  };
}
