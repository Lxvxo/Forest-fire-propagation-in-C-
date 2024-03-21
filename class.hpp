#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include <random>
#include <Qpainter>
//DEFINITION DE CELLULE
enum class CellState {
    Arbre,
    Feu,
    Cendre,
    Roche,
    Lac,
};

class Config {
    public : 
    int height = 15;
    int width = 15;
    std::vector <CellState> vecState =  {CellState::Arbre, CellState::Cendre, CellState::Feu , CellState::Lac, CellState::Roche};
     float proba(CellState s) {
          switch (s)
        {
         case CellState::Arbre:
            return 0.65;
            break;
         case CellState::Feu:
            return 0.05;
            break;
         case CellState::Cendre:
            return 0;
            break;
         case CellState::Lac:
            return 0.1;
            break;
         case CellState::Roche:
            return 0.2;
            break;
        default:
            break;
        }
    }
    
    QColor ColorState(CellState s) {
        switch (s)
        {
        case CellState::Arbre:
            return Qt::green;
            break;
        case CellState::Feu:
            return Qt::red;
            break;
        case CellState::Cendre:
            return Qt::black;
            break;
        case CellState::Lac:
            return Qt::blue;
            break;
        case CellState::Roche:
            return Qt::gray;
            break;
        default:
            break;
        }
    }
};

class Cell {
    public : 
    CellState state = CellState::Arbre; 
    QColor color;
    int degats = 0;
    
   
};

class ForestGrid {
public:
    Config c;
    ForestGrid(int w, int h) : width(w), height(h), grid(w * h) {
    // Initialisation de la grille avec des éléments aléatoires
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(0, 1);

    for (auto& cell : grid) {
        double randNum = distrib(gen);
        float p = 0;
        for( auto state : c.vecState ){
            if ((randNum < (c.proba(state) + p) ) && (c.proba(state) != 0)) {
                cell.state = state;
                cell.color = c.ColorState(state);
                break;
                }
                    p += c.proba(state);
                }

}}
    ForestGrid clone() const {
        return ForestGrid(*this);
    }
    Cell getCell(int x, int y) const {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            return grid[x + y * width];
        } else {
            return Cell{}; // Retourne une cellule par défaut si les coordonnées sont hors limites
        }
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }
    void setCell(int x, int y, CellState newState) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[x + y * width].state = newState;
            grid[x + y * width].color = c.ColorState(newState);
        }}

    std::vector<Cell> Voisins(int x, int y) {
        std::vector<Cell> VectVoisins ;
        std::vector<int> Xvoisins = {x, x , x-1, x+1 };
        std::vector<int> Yvoisins = {y-1, y + 1 , y, y};

        int N = 4; // nombre de voisins
        for (int k = 0 ; k<4;  ++k) {
            if (Xvoisins[k] > getWidth() || Xvoisins[k] < 0 || Yvoisins[k] > getHeight() || Yvoisins[k] < 0){
                Xvoisins.erase(Xvoisins.begin() + k);
                Yvoisins.erase(Yvoisins.begin() + k);
                N -= 1;
            }
        }
        for (int k = 0 ; k < N ; k++)
            {
            VectVoisins.push_back(getCell(Xvoisins[k],Yvoisins[k]));
            };
        return VectVoisins;
    }
    void update() {
        ForestGrid cloneForest = clone();
        for (int y = 0; y < getHeight(); ++y) {
            for (int x = 0; x < getWidth(); ++x) {
                std::vector<Cell> VectVoisins = cloneForest.Voisins(x,y);
                Cell ce = getCell(x,y);
                for (Cell v :  VectVoisins) {
                    switch (ce.state)
                    {
                    case CellState::Arbre:
                        if (v.state == CellState::Feu) {
                            setCell(x,y,CellState::Feu);
                            
                        }
                        break;
                    case CellState::Feu:
                        setCell(x,y,CellState::Cendre);

                        break;
                    
                    default:
                        break;
                    }
                }

        }}}



private:
    int width, height;
    std::vector<Cell> grid;

    
};

#endif
