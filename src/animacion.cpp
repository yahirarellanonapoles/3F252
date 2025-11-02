#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "Dibujo.hpp" 
#include "GestorDibujos.hpp"
#include "Corral.hpp" 
#include <cmath>
using namespace ftxui;

#define PI 3.14159265358979323846 

const std::vector<std::u32string> nube_figura = {
    U"    _  _   ",
    U"  _( )_( )_",
    U" (_   _   _)",
    U"  (_(_|_)_)"
};

const std::vector<std::u32string> montaña_figura = {
    U"           /\\          ",
    U"  /\\      /  \\  /\\     ",
    U" /  \\ /\\ /    \\/  \\    ",
    U"/____\\/_/______\\/____\\ "
};

const std::vector<std::u32string> arbol_fondo_figura = {
    U"  /\\ ",
    U" /\\/\\",
    U"/_||_\\",
    U"  || "
};
// ------------------------------------

const std::vector<std::u32string> niño1_figura = {
    U"  _O_  ",
    U" / | \\ ",
    U"  / \\  ",
    U" /   \\ "
};

const std::vector<std::u32string> niño2_figura = {
    U"  .-.  ",
    U" ( O ) ",
    U" / | \\ ",
    U"  / \\  ",
    U" /   \\ "
};
// ------------------------------------

int main()
{
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24));

    Superficie suelo(0, 20, 80, ftxui::Color::YellowLight);

    GestorDibujos gestor;
    
    gestor.Agregar(Dibujo(5, 1, nube_figura, ftxui::Color::White));
    gestor.Agregar(Dibujo(40, 3, nube_figura, ftxui::Color::White));
    gestor.Agregar(Dibujo(65, 1, nube_figura, ftxui::Color::White));

    gestor.Agregar(Dibujo(5, 8, montaña_figura, ftxui::Color::GrayDark)); 
    
    gestor.Agregar(Dibujo(3, 16, arbol_fondo_figura, ftxui::Color::Green));
    gestor.Agregar(Dibujo(45, 15, arbol_fondo_figura, ftxui::Color::Green));
    gestor.Agregar(Dibujo(65, 17, arbol_fondo_figura, ftxui::Color::Green));
    
    int base_y_niño1 = 16; 
    int base_y_niño2 = 15;

    gestor.Agregar(Dibujo(20, base_y_niño1, niño1_figura, ftxui::Color::Red)); 
    
    gestor.Agregar(Dibujo(35, base_y_niño2, niño2_figura, ftxui::Color::Blue)); 

    int frames = 200; 

    int amplitud_salto = 3; 
    int velocidad = 8;     

    for (int frame = 0; frame < frames; ++frame)
    {
        screen.Clear();

        
        double offset1 = (double)frame / velocidad;
        int nuevo_y1 = base_y_niño1 - (int)(amplitud_salto * std::abs(std::sin(offset1 * PI)));
        gestor.dibujos[7].y = nuevo_y1; 
        
        double offset2 = (double)(frame + velocidad / 2) / velocidad; 
        int nuevo_y2 = base_y_niño2 - (int)(amplitud_salto * std::abs(std::sin(offset2 * PI)));
        gestor.dibujos[8].y = nuevo_y2; 

        suelo.Dibujar(screen);    
        gestor.DibujarTodos(screen); 

        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(80)); 
    }
    return 0;
}