#pragma once

#include <Object.hpp>
#include <string>
#include <SDL2/SDL.h>
#include <Vector.hpp>

namespace Tvdr{
	class GameObject : public Object{
	private:
		SDL_Surface* _surface;
		SDL_Texture* _texture;
		Vector _position;
		Vector _textureSize;
		Vector _scale;
		float _rotate;

		virtual void Render();
	public:
		Vector const &GetPosition() {return _position;}
		void SetPosition(int x, int y) {_position.x = x; _position.y = y;}
		void SetPosition(Vector vec) {_position = vec;}
		int GetX() {return _position.x;}
		int GetY() {return _position.y;}
		Vector const &getTextureSize() {return _textureSize;}
		void SetScale(int x, int y) { _scale.x = x;_scale.y = y;}
		void SetScale(Vector vec){_scale = vec;}
		Vector const &GetScale() {return _scale;}

		GameObject(std::string imagePath);
		virtual ~GameObject();
	};
}