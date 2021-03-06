#pragma once

#include <Object.hpp>
#include <string>
#include <SDL2/SDL.h>
#include <Vector.hpp>

namespace Tvdr{
	class GameObject : public Object{
		friend class Object;
	private:
		SDL_Surface* _surface;
		SDL_Texture* _texture;
		Vector _textureSize;

		virtual void Render();
	public:
		Vector const &GetPosition() {return _position;}
		void SetPosition(float x, float y) {_position.x = x; _position.y = y;}
		void SetPosition(Vector vec) {_position = vec;}
		float GetX() {return _position.x;}
		float GetY() {return _position.y;}
		Vector const &getTextureSize() {return _textureSize;}
		void SetScale(float x, float y) { _scale.x = x;_scale.y = y;}
		void SetScale(Vector vec){_scale = vec;}
		Vector const &GetScale() {return _scale;}
		Vector GetPrintSize() {return _textureSize * _scale;}

		GameObject(std::string imagePath);
		virtual ~GameObject();
	};
}