#include "GameObject.hpp"
#include <Graphics.hpp>

namespace Tvdr{
	using namespace std;

	GameObject::GameObject(string imagePath): _position(0,0), _scale(1, 1), _rotate(0){
		_surface = SDL_LoadBMP(imagePath.c_str());
		_texture = Graphics::GetTextureFromSurface(_surface);
		int w, h;
		SDL_QueryTexture(_texture, nullptr, nullptr, &w, &h);
		_textureSize = Vector(w, h);
	}
	
	GameObject::~GameObject(){
		if (_texture)
			SDL_DestroyTexture(_texture);
		if (_surface)
			SDL_FreeSurface(_surface);
	}

	void GameObject::Render(){
		SDL_Rect rect;
		Graphics::RenderTexture(_texture);
	}

}