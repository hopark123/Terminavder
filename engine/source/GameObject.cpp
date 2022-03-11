#include "GameObject.hpp"
#include <Graphics.hpp>

namespace Tvdr{
	using namespace std;

	GameObject::GameObject(string imagePath): _position(0,0){
		_surface = SDL_LoadBMP(imagePath.c_str());
		_texture = Graphics::GetTextureFromSurface(_surface);
	}
	
	GameObject::~GameObject(){
		if (_texture)
			SDL_DestroyTexture(_texture);
		if (_surface)
			SDL_FreeSurface(_surface);
	}

	void GameObject::Render(){
		Graphics::RenderTexture(_texture);
	}

}