
#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include "class.hpp"  
#include <QTimer>
#include <array>

class RenderArea : public QWidget {
    Q_OBJECT

public:
    explicit RenderArea(QWidget *parent = nullptr);
    //void mousePressEvent(QMouseEvent *event);
    void updateGrid();
    // void mousePressEvent(QMouseEvent *event);
    // void trouverChemin(int startX, int startY);
    // void construireChemin(const std::array<int, 2>& destination, const std::map<std::array<int, 2>, std::array<int, 2>>& predecessors);



protected:
    void paintEvent(QPaintEvent *event) override;



private:
    ForestGrid grid;
    QTimer updateTimer;
    //std::vector<std::array<int, 2>> chemin;
};

#endif // RENDERAREA_H
