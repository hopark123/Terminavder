#include "Scene.hpp"

namespace Tvdr{

	Scene::Scene(){

	}

	Scene::~Scene(){
		
	}

	void Scene::UpdateAll(Object* obj){
		if (obj == nullptr)
			obj = this;
		for (auto child : _children){
			UpdateAll(child);
		}
		this->Update();
		this->Render();
	}
}