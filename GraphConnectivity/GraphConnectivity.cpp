
#include "Graph.h"
#include "UI.h"
int main()
{
    sf::RenderWindow win(sf::VideoMode(1350,800),"Connectivity");
    Graph graph(400,400,win,sf::Color(50, 76, 129));
    UI_Panel ui;
    while (win.isOpen()) {
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) win.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mouse= sf::Mouse::getPosition(win);
                if (ui.isRebuildPressed(mouse)) graph.rebuildConnections();
                 if (ui.isFindPressed(mouse)) graph.deepSearch(win);
            }
        }
        win.clear();
        graph.Draw(win);
        ui.DrawPanel(win, graph.lastTime);
        win.display();
    }
}
