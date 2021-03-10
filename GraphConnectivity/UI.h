#pragma once
#pragma once
#include "SFML/Graphics.hpp"

class UI_Panel {
public:
	UI_Panel();
	UI_Panel(const UI_Panel& copy) = delete;
	void DrawPanel(sf::RenderWindow& win, double exTime);
	bool isRebuildPressed(sf::Vector2i &mouse);
	bool isFindPressed(sf::Vector2i &mouse);
	sf::Sprite& GetRebuildSp();
	sf::Sprite& GetChangeMethodSp();
private:
	sf::Font font;
	sf::Image RebuildIm;
	sf::Texture RebuildTex;
	sf::Sprite RebuildSp;
	sf::Text Rebuildtex;

	sf::Image ElapsedTimeIm;
	sf::Texture ElapsedTimeTex;
	sf::Sprite ElapsedTimeSp;
	sf::Text ElapsedTimeText;

	sf::Image findIm;
	sf::Texture  findTex;
	sf::Sprite   findSp;
	sf::Text   findText;

};