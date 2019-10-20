/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#include <bdn/ui.h>
#include <bdn/ui/yoga.h>
#include <iostream>

#include "MainViewController.h"

namespace y44::todomvc {
  MainViewController::MainViewController() {
    _window = std::make_shared<bdn::ui::Window>();
    _window->title = "todomvc";
    _window->geometry = bdn::Rect{0, 0, 300, 500};
    _window->setLayout(std::make_shared<bdn::ui::yoga::Layout>());
    _window->visible = true;
    
    _mainContainer = std::make_shared<bdn::ui::ContainerView>();
    _mainContainer->stylesheet = FlexJsonStringify({
      "flexGrow": 1.0,
      "direction": "Column",
      "padding": 5,
      "justifyContent": "Center"
    });
    _window->contentView = _mainContainer;
    
    _newEntryField = std::make_shared<bdn::ui::TextField>();
    _newEntryField->placeholder = "What needs to be done?";
    _newEntryField->stylesheet = FlexJsonStringify({
      "alignSelf": "Center",
      "size": {"width": "95%", "height": 50}
    });
    _mainContainer->addChildView(_newEntryField);

    _listView = std::make_shared<bdn::ui::ListView>();
    _listView->enableSwipeToDelete = true;
    _listView->stylesheet = FlexJsonStringify({
      "flexGrow": 1.0,
      "size": {"width": "95%", "height": "95%"}
    });
    _listView->enableRefresh = true;
    _listView->onRefresh() += [this]() {
      _todoStore->load();
      _listView->reloadData();
      _listView->refreshDone();
    };
    _mainContainer->addChildView(_listView);

    _todoStore = std::make_shared<TodoStore>();
    _todoStore->load();

    _todoDataSource = std::make_shared<TodoListDataSource>(_todoStore);
    _listView->dataSource = _todoDataSource;
    
    _listView->onDelete() += [this](int index) {
        _todoStore->remove(index);
    };

    _newEntryField->onSubmit() += [=](auto ev) {
      if(!_newEntryField->text->empty()) {
       _todoStore->add(_newEntryField->text);
       _listView->reloadData();
       _newEntryField->text = std::string();
      }
    };
  }
}

