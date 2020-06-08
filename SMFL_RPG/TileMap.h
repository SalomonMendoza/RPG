#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"

class TileMap
{

private:
	float gridSizeF;
	unsigned gridSizeU;
	unsigned layers;
	sf::Vector2u maxSize;
	std::vector< std::vector< std::vector< Tile* > > > map;
	sf::Texture tileTextureSheet;

public:

	TileMap(float gridSize, unsigned width, unsigned height);
	virtual ~TileMap();

	//Functions
	void update();
	void render(sf::RenderTarget& target );

	void addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& texture_rect);
	void removeTile(const unsigned x, const unsigned y, const unsigned z);
};

#endif
