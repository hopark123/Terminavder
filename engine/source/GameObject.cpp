#include "GameObject.hpp"

namespace Tvdr{
	using namespace std;

	GameObject::GameObject() : _position(0, 0) {}
	GameObject::~GameObject(){}

	void GameObject::Render(vector<string> &screen){
		int width = screen[0].size();
		int height = screen.size();
		for (int i = 0;i < _model.size();++i){
			for (int j = 0;j < _model[i].size();++j){
				int tx = _position.x + j;
				int ty = _position.y + i;
				if ((tx < 0 || width <= tx) && (ty < 0 || height <= ty))
					continue;
				if (_model[i][j] != ' ')
					screen[ty][tx] = _model[i][j];
			}
		}
	}

	GameObject* GameObject::CreateGameObject(std::vector<std::string> const &model, Object* parent){
		GameObject* obj = new GameObject;
		obj->SetParent(parent);
		obj->_model = model;
		return obj;
	}
}