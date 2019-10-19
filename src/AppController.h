/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#pragma once

#include <bdn/ui/UIApplicationController.h>

#include "MainViewController.h"

namespace y44::todomvc {
  class AppController : public bdn::ui::UIApplicationController {
    public:
     void beginLaunch() override;

    protected:
     std::shared_ptr<MainViewController> _mainViewController;
  };
}
