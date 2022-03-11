#include "GameObject.hpp"

namespace Tvdr{
	using namespace std;

	GameObject::GameObject(string imagePath): _position(0,0){
		_model = SDL_LoadBMP(imagePath.c_str());
	}
	
	GameObject::~GameObject(){
		if (_model)
			SDL_FreeSurface(_model);
	}

	void GameObject::Render(){
		
	}

}