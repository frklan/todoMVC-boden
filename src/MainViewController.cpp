/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#include <bdn/ui.h>
#include <bdn/ui/yoga.h>

#include "MainViewController.h"

namespace y44::todomvc {
  MainViewController::MainViewController()
  {
      _window = std::make_shared<bdn::ui::Window>();
      _window->title = "TodoMVC";
      _window->geometry = bdn::Rect{0, 0, 400, 300};
      _window->setLayout(std::make_shared<bdn::ui::yoga::Layout>());

      auto label = std::make_shared<bdn::ui::Label>();
      label->text = "Hello WORLD!";

      _window->contentView = label;
      _window->visible = true;
  }
}
