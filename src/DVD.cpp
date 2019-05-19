#include "stdinc.hpp"
#include "DVD.hpp"

DVD::DVD(const int screen_width, const int screen_height) : screen_width_(screen_width), screen_height_(screen_height)
{
	color_ = new_color();

	position_.x = static_cast<float>(random_num(0, screen_width - texture_.width));
	position_.y = static_cast<float>(random_num(0, screen_height - texture_.height));

	xspeed_ = 3.5f;
	yspeed_ = 3.5f;
}

DVD::~DVD()
{
	UnloadTexture(texture_);
}

void DVD::load()
{
	texture_ = LoadTexture("dvd.png");
}

void DVD::update()
{
	position_.x += xspeed_;
	position_.y += yspeed_;

	if (position_.x < 0 || position_.x + texture_.width > screen_width_)
	{
		xspeed_ *= -1;
		color_ = new_color();
	}

	if (position_.y < 0 || position_.y + texture_.height > screen_height_)
	{
		yspeed_ *= -1;
		color_ = new_color();
	}
}

void DVD::draw()
{
	DrawTextureV(texture_, position_, color_);
}

const int DVD::random_num(const int min, const int max)
{
	auto static rng = std::mt19937(std::random_device{}());
	auto static dist = std::uniform_int_distribution<std::mt19937::result_type>(min, max);

	return dist(rng);
}

Color DVD::new_color()
{
	return Color{
		static_cast<unsigned char>(random_num(0, 255)),
		static_cast<unsigned char>(random_num(0, 255)),
		static_cast<unsigned char>(random_num(0, 255)),
		255
	};
}
