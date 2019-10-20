/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#include "TodoItemView.h"

#include <bdn/ui/yoga.h>

namespace y44::todomvc {
  using namespace bdn::ui;

  void TodoItemView::init() {
    this->stylesheet = FlexJsonStringify({
      "direction": "Row",
      "alignItems": "Center",
      "padding": 10
    });

    auto checkbox = std::make_shared<Checkbox>();
    checkbox->checked.bind(isCompleted);
    addChildView(checkbox);

    auto label = std::make_shared<Label>();
    label->text.bind(todoText);
    addChildView(label);
  }
}
