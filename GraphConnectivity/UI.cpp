#include "UI.h"

UI_Panel::UI_Panel() {
	font.loadFromFile("../Font/font.otf");
	RebuildIm.create(240, 50, sf::Color::Blue);
	RebuildTex.loadFromImage(RebuildIm);
	RebuildSp.setTexture(RebuildTex);
	RebuildSp.setPosition(sf::Vector2f(1060, 50));
	Rebuildtex.setString("Rebuild connections");
	Rebuildtex.setPosition(sf::Vector2f(RebuildSp.getPosition().x + 10, RebuildSp.getPosition().y + 10));
	Rebuildtex.setFillColor(sf::Color::White);
	Rebuildtex.setFont(font);
	Rebuildtex.setCharacterSize(20);

	ElapsedTimeIm.create(250, 50, sf::Color::Blue);
	ElapsedTimeTex.loadFromImage(ElapsedTimeIm);
	ElapsedTimeSp.setTexture(ElapsedTimeTex);
	ElapsedTimeSp.setPosition(sf::Vector2f(1055, 700));
	ElapsedTimeText.setString("Execution time: 0ms");
	ElapsedTimeText.setPosition(sf::Vector2f(ElapsedTimeSp.getPosition().x + 10, ElapsedTimeSp.getPosition().y + 15));
	ElapsedTimeText.setFillColor(sf::Color::White);
	ElapsedTimeText.setFont(font);
	ElapsedTimeText.setCharacterSize(15);


	findIm.create(250, 50, sf::Color::Blue);
	findTex.loadFromImage(findIm);
	findSp.setTexture(findTex);
	findSp.setPosition(sf::Vector2f(1050, 255));
	findText.setPosition(sf::Vector2f(findSp.getPosition().x + 65, findSp.getPosition().y + 12));
	findText.setFillColor(sf::Color::White);
	findText.setFont(font);
	findText.setCharacterSize(20);
};
void  UI_Panel::DrawPanel(sf::RenderWindow& win, double exTime) {
	win.draw(RebuildSp);
	win.draw(Rebuildtex);
	ElapsedTimeText.setString("Execution time: " + std::to_string(exTime) + "ms");
	win.draw(ElapsedTimeSp);
	win.draw(ElapsedTimeText);

	findText.setString("Find comp!");
	win.draw(findSp);
	win.draw(findText);
}
sf::Sprite& UI_Panel::GetRebuildSp() {
	return RebuildSp;

}
sf::Sprite& UI_Panel::GetChangeMethodSp() {
	return  findSp;

}
bool UI_Panel::isRebuildPressed(sf::Vector2i &mouse) {
	return RebuildSp.getGlobalBounds().contains(mouse.x,mouse.y);
}
bool UI_Panel::isFindPressed(sf::Vector2i& mouse) {
	return findSp.getGlobalBounds().contains(mouse.x, mouse.y);
}