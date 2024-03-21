
#include "render_area.hpp"
#include <QPainter>
#include "class.hpp"

static Config  c ;
#include <queue>
#include <limits>

RenderArea::RenderArea(QWidget *parent) 
    : QWidget(parent), grid(c.height, c.width) {
        connect(&updateTimer, &QTimer::timeout, this, &RenderArea::updateGrid);
        updateTimer.start(5000); // Démarrer le timer avec un intervalle de 5000 ms (5 secondes)
}
void RenderArea::updateGrid() {
    grid.update();  // Met à jour la grille
    update();       // Redessine la zone de rendu si nécessaire
}


void RenderArea::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    int cellWidth = width() / grid.getWidth();
    int cellHeight = height() / grid.getHeight();

    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            Cell cell = grid.getCell(x, y);
            painter.setBrush(cell.color);
            painter.drawRect(x * cellWidth, y * cellHeight, cellWidth, cellHeight);
        }
    }
    // QPen pen(Qt::yellow);
    // painter.setPen(pen);
    // for (size_t i = 0; i < chemin.size() - 1; i++) {
    //     painter.drawLine(chemin[i][0], chemin[i][1], chemin[i + 1][0], chemin[i + 1][1]);
    // }
}
// #include <QMouseEvent>
// void RenderArea::mousePressEvent(QMouseEvent *event) {
//     int cellWidth = width() / grid.getWidth();
//     int cellHeight = height() / grid.getHeight();
//     int x = event->pos().x() / cellWidth;
//     int y = event->pos().y() / cellHeight;

//     Cell cell = grid.getCell(x, y);

//     if (event->button() == Qt::RightButton && cell.state == CellState::Arbre) {
//         // Clic droit sur un arbre : allumer le feu
//         grid.setCell(x, y, CellState::Feu);
//     } else if (event->button() == Qt::LeftButton && cell.state == CellState::Arbre) {
//         // Clic gauche sur un arbre : trouver le chemin vers le feu le plus proche
//         trouverChemin(x, y);
//     }

//     update(); // Met à jour le widget pour redessiner la grille
// }


// void RenderArea::trouverChemin(int startX, int startY) {
//     // Initialisation de BFS
//     std::queue<std::array<int, 2>> queue;
//     std::map<std::array<int, 2>, std::array<int, 2>> predecessors;
//     std::vector<std::vector<bool>> visited(grid.getHeight(), std::vector<bool>(grid.getWidth(), false));

//     queue.push({startX, startY});
//     visited[startY][startX] = true;
//     bool found = false;

//     while (!queue.empty() && !found) {
//         std::array<int, 2> current = queue.front();
//         queue.pop();

//         // Vérifier les voisins...
//         for (int dx = -1; dx <= 1; ++dx) {
//             for (int dy = -1; dy <= 1; ++dy) {
//                 if (dx != 0 && dy != 0) continue;
//                 int nx = current[0] + dx;
//                 int ny = current[1] + dy;

//                 if (nx >= 0 && nx < grid.getWidth() && ny >= 0 && ny < grid.getHeight() && !visited[ny][nx]) {
//                     visited[ny][nx] = true;
//                     predecessors[{nx, ny}] = current;
//                     if (grid.getCell(nx, ny).state == CellState::Feu) {
//                         construireChemin({nx, ny}, predecessors);
//                         found = true;
//                         break;
//                     }
//                     queue.push({nx, ny});
//                 }
//             }
//         }
//     }
// }

// void RenderArea::construireChemin(const std::array<int, 2>& destination, const std::map<std::array<int, 2>, std::array<int, 2>>& predecessors) {
//     chemin.clear();
//     for (auto at = destination; at != predecessors.end()->first; at = predecessors.at(at)) {
//         chemin.push_back(at);
//     }
//     std::reverse(chemin.begin(), chemin.end());
// }
