cmake_minimum_required(VERSION 3.15.0)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

set(BDN_BUILD_TESTS OFF CACHE BOOL "Don't include boden tests")
set(BDN_BUILD_EXAMPLES OFF CACHE BOOL "Don't include boden examples")
set(BDN_WARNINGS_AS_ERRORS OFF CACHE BOOL "Don't treat warnings as errors")

project(TodoMVC)

set(CMAKE_CXX_CLANG_TIDY 
  clang-tidy;
  -header-filter="*.h";
  -checks=*,-fuchsia-default-arguments;
)

add_compile_options(
  -g
  -Weverything 
  -Wno-c++98-compat 
  -Wno-c++98-compat-pedantic
  -Wno-padded
)

add_subdirectory(boden boden)

file(GLOB_RECURSE _sources src/*.cpp src/*.h)

ios_configure_asset(_assets ./ios-assets/Base.lproj/LaunchScreen.storyboard)
ios_configure_asset(_assets AppIcons/black.png)

roger_add(
    TodoMVC
    _assets
    ${CMAKE_CURRENT_LIST_DIR}/AppIcons/app_icons.json)

set(ANDROID_ICON "android:icon=\"@mipmap/ic_launcher_png\"")

add_universal_executable(TodoMVC SOURCES ${_sources} ${_assets})

ios_configure_app_info(TARGET TodoMVC
    LAUNCHSCREEN "LaunchScreen"
    TARGETED_DEVICES IPHONE IPAD
    IPHONE_ORIENTATIONS ALL
    IPAD_ORIENTATIONS ALL)

use_boden_template_info_plist(
    TARGET TodoMVC
    BUNDLE_NAME "TodoMVC"
    BUNDLE_ID "com.yallowfortyfour.TodoMVC"
    )
set(ANDROID_APP_ID "com.yellowfortyfour.TodoMVC")

set_xcode_appicon_asset(TodoMVC "ApplicationIcon")
use_boden_template_info_plist(TARGET TodoMVC
                              BUNDLE_NAME "TodoMVC"
                              BUNDLE_ID "com.yellowfortyfour.TodoMVC")

set_target_version(TARGET TodoMVC VERSION "0.0.1" SHORTVERSION "0.0" LONGVERSION "0.0.1.0" ANDROID_VERSION_ID 1)

target_link_libraries(TodoMVC Boden::All)
