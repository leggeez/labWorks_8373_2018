#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

const int H = 18;
const int W = 118;

float Cam_x = 0;
float Cam_y = 0;

String TileMap[H] = {
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"B                                                                                                                   B",
	"B                                                                                                                   B",
	"B                                                                                                                   B",
	"B                                                                                                                   B",
	"B                                                                                                                   B",
	"B                                                                                                                   B",
	"B                                                                                                                   B",
	"B                                                                                                                   B",
	"B                                                                                                                   B",
	"B                                                                                                                   B",
	"B                                                                                                                   B",
	"B               0                                                                                                   B",
	"B              BBBB                                    BBBBBBBBBBB                                                  B",
	"B        B              B            0      0          B                   B             0       0                  B",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBFFFFSSFFFFSSFFFFBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBFFFFFSSFFFFFSSFFFFBBBBBBBBBBBBBBB",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBLLLLLLLLLLLLLLLLBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBLLLLLLLLLLLLLLLLLLBBBBBBBBBBBBBBB",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBKKKKKKKKKKKKKKKKBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBKKKKKKKKKKKKKKKKKKBBBBBBBBBBBBBBB",
};

int ground = 398;

class ENEMY {
public: float dx;
		float currentFrame;
		FloatRect rect;
		Sprite sprite;
		bool life;

		void SetEnemy(Texture &image, int e_x, int e_y)
		{
			sprite.setTexture(image);
			rect = FloatRect(e_x, e_y, 32, 32);
			dx = 0.35;
			life = true;
		}

		void Collision()
		{
			for (int i = rect.top / 32; i<(rect.top + rect.height) / 32; i++)
				for (int j = rect.left / 32; j<(rect.left + rect.width) / 32; j++)
					if (TileMap[i][j] == 'B')
					{
						if (dx>0) {
							rect.left = j * 32 - rect.width; dx *= -1;
						}
						else if (dx < 0) {
							rect.left = j * 32 + 32;  dx *= -1;
						}
					}
		}

		void update(float time)
		{
			rect.left += dx*time;
			Collision();

			sprite.setTextureRect(IntRect(0, 0, 32, 32));

			sprite.setPosition(rect.left - Cam_x, rect.top - Cam_y);
		}
};

class PLAYER {
public: float dx, dy;
		float currentFrame;
		int Coin;
		FloatRect rect;
		bool onGround, cursor;
		Sprite sprite;
		map < string, bool > key;
		enum { stay, walkR, walkL, jump } STATE;
		PLAYER(Texture &image)
		{
			sprite.setTexture(image);
			rect = FloatRect(33, 382, 82, 79);
			Coin = 0;
			dy = 0;
			dx = 0;
			STATE = stay;
			currentFrame = 0;
		}

		void KeyCheck()
		{
			if (key["Right"]) {
				dx = 0.5;
				if (STATE == stay) STATE = walkR;
			}
			if (key["Left"]) {
				dx = -0.5;
				if (STATE == stay) STATE = walkL;
			}
			if (key["Up"]) {
				if (onGround) {
					if (STATE == walkR || STATE == stay) cursor = 0;
					if (STATE == walkL) cursor = 1;
					if (STATE == stay || STATE == walkR || STATE == walkL) {
						dy = -0.8;
						STATE = jump;
						onGround = false;
					}
				}
			}
			if (!(key["Right"] || key["Left"])) {
				dx = 0;
				if (STATE == walkL) { cursor = 1; STATE = stay; }
				if (STATE == walkR) { cursor = 0; STATE = stay; }
			}
			if (!(key["Up"])) {
				dy = 0.5;
				if (STATE == jump) STATE = stay;
			}
		}

		void Collision(int dir)
		{
			for (int i = rect.top / 32; i <= (rect.top + rect.height) / 32; i++)
				for (int j = rect.left / 32; j <= (rect.left + rect.width) / 32; j++)
					{
						if ((TileMap[i][j] == 'B') || (TileMap[i][j] == 'S'))
						{
							if ((dx > 0) && (dir == 0)) {
								rect.left -= 4;
							}
							if ((dx < 0) && (dir == 0)) {
								rect.left += 4;
							}
							if ((dy > 0) && (dir == 1)) {
								rect.top -= 4;
								dy = 0;
								onGround = true;
							}
							if ((dy < 0) && (dir == 1)) {
								rect.top += 4;
								dy = 0;
							}
						}
						if ((TileMap[i][j] == 'F') || (TileMap[i][j] == 'L') || (TileMap[i][j] == 'K')) {
							ground += 32 * 3;
						}
						if (TileMap[i][j] == '0') {
							Coin++;
							TileMap[i][j] = ' ';
						}
					}
		}

		void update(float time)
		{
			KeyCheck();
			switch (STATE)
			{
			case stay:	if (cursor) {
						currentFrame += 0.008*time;
						if (currentFrame > 4)
						{
							currentFrame -= 4;
						}
						sprite.setTextureRect(IntRect(81 * int(currentFrame) + 81, 98, -81, 78));
						}
						else {
							currentFrame += 0.008*time;
							if (currentFrame > 4)
							{
								currentFrame -= 4;
							}
							sprite.setTextureRect(IntRect(81 * int(currentFrame), 98, 81, 78));
						}
						break;
			case walkL: currentFrame += 0.025*time;
						if (currentFrame > 8)
						{
							currentFrame -= 8;
						}
						sprite.setTextureRect(IntRect(82 * int(currentFrame) + 82, 245, -82, 79));
						break;
			case walkR: currentFrame += 0.025*time;
						if (currentFrame > 8)
						{
							currentFrame -= 8;
						}
						sprite.setTextureRect(IntRect(82 * int(currentFrame), 245, 82, 79));
						break;
			case jump:  if (cursor) {
						currentFrame += 0.01*time;
						if (currentFrame > 6)
						{
							currentFrame -= 6;
						}
						sprite.setTextureRect(IntRect(80 * int(currentFrame) + 80, 383, -80, 92));
						}
						else {
							currentFrame += 0.01*time;
							if (currentFrame > 6)
							{
								currentFrame -= 6;
							}
							sprite.setTextureRect(IntRect(80 * int(currentFrame), 383, 80, 92));
						}
						break;
			}

			rect.left += dx*time;
			Collision(0);

			if (!onGround) dy = dy + 0.005*time;
			rect.top += dy*time;
			onGround = false;
			Collision(1);

			if (rect.top > ground) {
				rect.top = ground;
				dy = 0;
				onGround = true;
			}

			sprite.setPosition(rect.left - Cam_x, rect.top - Cam_y);

			dx = 0;

			key["Right"] = key["Left"] = key["Up"] = false;
		}
};

int main()
{
	RenderWindow window(VideoMode(1000, 576), "The Game.");
	
	Texture tileSet;
	tileSet.loadFromFile("tileset.png");

	Sprite tile(tileSet);

	Texture t;
	t.loadFromFile("Sprite_cosmo.png");

	float currentFrame = 0;

	PLAYER p(t);
	ENEMY enemy1;
	ENEMY enemy2;
	enemy1.SetEnemy(tileSet, 11 * 32, 14 * 32);
	enemy2.SetEnemy(tileSet, 56 * 32 , 14 * 32);

	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1700;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color(255, 255, 255));

		if (Keyboard::isKeyPressed(Keyboard::Left)) p.key["Left"] = true;
		if (Keyboard::isKeyPressed(Keyboard::Right)) p.key["Right"] = true;
		if (Keyboard::isKeyPressed(Keyboard::Up)) p.key["Up"] = true;

		p.update(time);
		enemy1.update(time);
		enemy2.update(time);
		
		if (p.rect.intersects(enemy2.rect))
		{
			if (enemy2.life) {
				if (p.dy > 0) {
					enemy2.dx = 0;
					enemy2.life = false;
				}
				else p.sprite.setColor(Color::Red);
			}
		}
		
		if (p.rect.intersects(enemy1.rect))
		{
			if (enemy1.life) {
				if (p.dy > 0) {
					enemy1.dx = 0;
					enemy1.life = false;
				}
				else p.sprite.setColor(Color::Red);
			}
		}

		if (p.rect.left > 500) {
			Cam_x = p.rect.left - 500;
		}
		if (p.rect.top < 288) {
			Cam_y = p.rect.top - 288;
		}

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'B') tile.setTextureRect(IntRect(320, 288, 32, 32));
				if (TileMap[i][j] == 'F') tile.setTextureRect(IntRect(128, 128, 32, 32));
				if (TileMap[i][j] == 'L') tile.setTextureRect(IntRect(160, 128, 32, 32));
				if (TileMap[i][j] == 'K') tile.setTextureRect(IntRect(192, 128, 32, 32));
				if (TileMap[i][j] == '0') tile.setTextureRect(IntRect(704, 288, 32, 32));
				if (TileMap[i][j] == 'S') tile.setTextureRect(IntRect(288, 96, 32, 32));
				if (TileMap[i][j] == ' ') continue;
				tile.setPosition(j * 32 - Cam_x, i * 32 - Cam_y);

				window.draw(tile);
			}

		window.draw(enemy1.sprite);
		window.draw(enemy2.sprite);
		window.draw(p.sprite);
		window.display();
	}
	return 0;
}