/** Copyright (c) Fredrik Andersson
*
*   This file is licensed under a
*   Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
**/

#include "AppController.h"

namespace y44::todomvc {
  void AppController::beginLaunch() { 
    _mainViewController = std::make_shared<MainViewController>(); 
  }
}
