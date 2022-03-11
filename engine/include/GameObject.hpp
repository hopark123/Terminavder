#pragma once

#include <Object.hpp>
#include <string>
#include <SDL2/SDL.h>
#include <Vector.hpp>

namespace Tvdr{
	class GameObject : public Object{
	private:
		SDL_Surface* _model;
		Vector _position;

		virtual void Render();
	public:
		Vector const &GetPosition() {return _position;}
		void SetPosition(int x, int y) {_position.x = x; _position.y = y;}
		int const GetX() {return _position.x;}
		int const GetY() {return _position.y;}

		GameObject(std::string imagePath);
		virtual ~GameObject();
	};
}