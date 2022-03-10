#include "Object.hpp"
#include <algorithm>

using namespace std;

namespace Tvdr{

	Object::Object() : _parent(nullptr){}
	Object::~Object(){

	}

	bool Object::AddChild(Object *obj){
		if (find(_children.begin(), _children.end(), obj) == _children.end()){
			_children.push_back(obj);
			obj->SetParent(this);
			return true;
		}
		return false;
	}

	bool Object::Destroy(){
		for (auto child : _children)
			child->Destroy();
		if (_parent)
			_parent->_children.remove(this);
		delete this;
	}

	void Object::Start(){}
	void Object::Update(){}
	void Object::Render(vector<string> &screen, int width, int height){}

	Object* Object::CreateObject(Object* parent){
		auto obj = new Object;
		obj->_parent = parent;
		parent->AddChild(obj);
		return obj;
	}

	void Object::SetParent(Object* parent){
		if (_parent)
			_parent->_children.remove(this);
		_parent = parent;
		parent->AddChild(this);
	}

	Object const *Object::GetParent(){
		return _parent;
	}
}