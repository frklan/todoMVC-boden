/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#pragma once

#include "TodoStore.h"

#include <bdn/ui.h>

namespace y44::todomvc {
  class TodoListDataSource : public bdn::ui::ListViewDataSource {
    public:
      TodoListDataSource(std::shared_ptr<TodoStore> store);
      virtual ~TodoListDataSource() = default;

      virtual size_t numberOfRows(const std::shared_ptr<bdn::ui::ListView>& listView) override;
      virtual std::shared_ptr<bdn::ui::View> viewForRowIndex(const std::shared_ptr<bdn::ui::ListView>& listview,
        size_t rowIndex,
        std::shared_ptr<bdn::ui::View> reuseableView) override;

      virtual float heightForRowIndex(const std::shared_ptr<bdn::ui::ListView>& listview, size_t rowIndex) override;
    
    private:
      std::shared_ptr<TodoStore> _store;
  };

}
