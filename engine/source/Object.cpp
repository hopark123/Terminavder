#include "Object.hpp"
#include <algorithm>
#include <iostream>
#include "GameManager.hpp"

using namespace std;

namespace Tvdr{

	Object::Object() : _parent(nullptr){}
	Object::~Object(){
		if (_parent)
			_parent->_children.remove(this);
		while (!_children.empty())
			delete _children.front();
	}

	bool Object::AddChild(Object *obj){
		if (find(_children.begin(), _children.end(), obj) == _children.end()){
			_children.push_back(obj);
			obj->_parent = this;
			return true;
		}
		return false;
	}

	void Object::Update(){}
	void Object::Render(){}

	void Object::SetParent(Object* parent){
		if (_parent)
			_parent->_children.remove(this);
		_parent = parent;
		parent->AddChild(this);
	}

	Object const *Object::GetParent(){
		return _parent;
	}

	void Object::Release(){
		GameManager::Instance()->_releaseObject.push_back(this);
	}
}