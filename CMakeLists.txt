cmake_minimum_required(VERSION 3.28)
project(SDLPaint)
file(COPY Fonts/font.ttf
        DESTINATION ./)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDLPaint main.cpp MainWindow.h
        MainWindow.cpp
        GraphBoxControl.cpp
        GraphBoxControl.h
        CirclePoint.cpp
        CirclePoint.h
        BasicFunctions.h
)

if (WIN32)
    set(SDL2_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2-2.30.3/include")
    set(SDL2_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2-2.30.3/lib/x64")
    set(SDL2_IMAGE_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2_image-2.8.2/include")
    set(SDL2_IMAGE_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2_image-2.8.2/lib/x64")
    set(SDL2_TTF_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2_ttf-2.22.0/include")
    set(SDL2_TTF_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2_ttf-2.22.0/lib/x64")

    target_link_libraries(
            SDLPaint
            ${SDL2_LIBRARY_DIR}/SDL2main.lib
            ${SDL2_LIBRARY_DIR}/SDL2.lib
            ${SDL2_IMAGE_LIBRARY_DIR}/SDL2_image.lib
            ${SDL2_TTF_LIBRARY_DIR}/SDL2_ttf.lib
    )

    target_include_directories(
            SDLPaint PRIVATE
            ${SDL2_INCLUDE_DIR}
            ${SDL2_IMAGE_INCLUDE_DIR}
            ${SDL2_TTF_INCLUDE_DIR}
    )
endif (WIN32)

target_include_directories(SDLPaint PUBLIC vendor/SDLForms_v_1_0_0/include)

find_library(SDL_Forms_Lib SDLForms vendor/SDLForms_v_1_0_0/bin)
target_link_libraries(SDLPaint ${SDL_Forms_Lib})

