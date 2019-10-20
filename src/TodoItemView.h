/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#pragma once

#include <bdn/ui.h>

namespace y44::todomvc {
  class TodoItemView : public bdn::ui::CoreLess<bdn::ui::ContainerView> {
    public:
    bdn::Property<std::string> todoText;
    bdn::Property<bool> isCompleted;

    using bdn::ui::CoreLess<bdn::ui::ContainerView>::CoreLess;

    void init() override;
  };
}

