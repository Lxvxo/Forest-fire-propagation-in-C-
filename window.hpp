
 // window.hpp

#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "render_area.hpp"

class Window : public QMainWindow {
    Q_OBJECT

public:
    Window();

private:
    RenderArea *renderArea;
    
};

#endif 