cmake_minimum_required(VERSION 3.10)

# Установите название вашего проекта
project(Calculator)

# Установите стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Найдите пакеты Qt5, если вы используете Qt для UI
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
find_package(Qt5 COMPONENTS Widgets Core Gui PrintSupport REQUIRED)
set(CMAKE_AUTOUIC ON) # Включите обработку файлов .ui
set(CMAKE_AUTOMOC ON) # Включите обработку файлов moc
set(CMAKE_AUTORCC ON) # Включите обработку файлов ресурсов
option(BUILD_MY_EXECUTABLE "Build the my_executable target" OFF)
option(BUILD_MY_MAIN "Build the my_executable target" OFF)
# Добавьте все исходные файлы и заголовочные файлы
if(BUILD_MY_MAIN)
add_executable(${PROJECT_NAME}
    calc/main.cpp
    calc/controller.cpp
    calc/calculator.cpp
    calc/credits.cpp
    calc/deposit.cpp
    calc/model.cc
    calc/qcustomplot.cpp
    calc/view.cpp
)

# Укажите включаемые каталоги
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/calc)

# Свяжите ваше приложение с библиотеками Qt
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::PrintSupport)
endif()


if(BUILD_MY_EXECUTABLE)


add_executable(CalculatorTests
    calc/tests.cc /
    calc/model.cc
)
target_include_directories(CalculatorTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/calc)
target_link_libraries(CalculatorTests Qt5::Widgets Qt5::Core Qt5::Gui Qt5::PrintSupport)

target_link_libraries(CalculatorTests
    ${CMAKE_CURRENT_SOURCE_DIR}/calc
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/libgtest.a
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/libgtest_main.a
    pthread # Для Google Test требуется pthread
)
endif()

