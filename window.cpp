// window.cpp

#include "window.hpp"

Window::Window() {
    // Création et configuration de RenderArea
    renderArea = new RenderArea(this);

    
    setCentralWidget(renderArea);

   
}
