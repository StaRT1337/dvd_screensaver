#pragma once

class DVD
{
private:
	Texture2D texture_;
	Color color_;
	Vector2 position_;
	
	float xspeed_;
	float yspeed_;

	int screen_width_;
	int screen_height_;
public:
	DVD(const int screen_width, const int screen_height);
	~DVD();

	void load();
	void update();
	void draw();

	static const int random_num(const int min, const int max);
	static Color new_color();
};
