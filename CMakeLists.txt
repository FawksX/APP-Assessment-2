cmake_minimum_required(VERSION 3.26)
project(APP_Assessment_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(APP_Assessment_2 Takeaway.cpp
        Item.h
        Item.cpp
        Appetiser.cpp
        Appetiser.h
        Beverage.cpp
        Beverage.h
        MainCourse.cpp
        MainCourse.h
        ItemList.cpp
        ItemList.h
        Menu.cpp
        Menu.h
        Order.cpp
        Order.h
        Util.cpp
        Util.h
        ItemType.h)
