#include "Scene.hpp"

namespace Tvdr{

	Scene::Scene(){

	}

	Scene::~Scene(){
		
	}

	void Scene::UpdateAll(Object* obj){
		if (obj == nullptr)
			obj = this;
		for (auto child : obj->_children){
			UpdateAll(child);
		}
		obj->Update();
		obj->Render();
	}
}