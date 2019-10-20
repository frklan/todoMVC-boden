/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#include "TodoListDataSource.h"
#include "TodoItemView.h"

#include <bdn/ui.h>

namespace y44::todomvc {
  TodoListDataSource::TodoListDataSource(std::shared_ptr<TodoStore> store) {
    _store = store;
  }

  size_t TodoListDataSource::numberOfRows(const std::shared_ptr<bdn::ui::ListView>& listView) {
    return _store->todos.size();
  }

  std::shared_ptr<bdn::ui::View> TodoListDataSource::viewForRowIndex(const std::shared_ptr<bdn::ui::ListView>& listview,
    size_t rowIndex,
    std::shared_ptr<bdn::ui::View> reuseableView) {
      if(!reuseableView) {
        reuseableView = std::make_shared<TodoItemView>();
      }
      auto item = std::dynamic_pointer_cast<TodoItemView>(reuseableView);
      item->todoText = _store->todos.at(rowIndex).at("todoText");
      item->isCompleted = _store->todos.at(rowIndex).at("isCompleted");

      std::weak_ptr<bdn::ui::View> weakItem(item);

      item->isCompleted.onChange().unsubscribeAll();
      item->isCompleted.onChange() += [list = listview.get(), weakItem, this] (const auto& property) {
        if(auto rowIndex = list->rowIndexForView(weakItem.lock())) {
          _store->todos.at(*rowIndex).at("isCompleted") = property.get();
          _store->save();
        }
      };

      return reuseableView;
    }

  float TodoListDataSource::heightForRowIndex(const std::shared_ptr<bdn::ui::ListView>& listview, size_t rowIndex) {
    constexpr float height = 50;
    return height;
  }


}
