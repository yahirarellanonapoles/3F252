#pragma once
#include "Dibujo.hpp"

class Superficie {
private:
    static std::vector<std::u32string> GenerarFiguraSuelo(int ancho) {
        std::vector<std::u32string> figura;
        std::u32string top = std::u32string(ancho, U'═');
        figura.push_back(top);
        return figura;
    }

public:
    Dibujo dibujo_superficie;

    Superficie(int x, int y, int ancho, ftxui::Color color = ftxui::Color::YellowLight)
        : dibujo_superficie(x, y, GenerarFiguraSuelo(ancho), color)
    {
    }

    void Dibujar(ftxui::Screen& screen) const {
        dibujo_superficie.Dibujar(screen);
    }
};