#include "Scene.hpp"

namespace Tvdr{

	Scene* Scene::CreateScene(){
		Scene* scene = new Scene;
		scene->SetParent(nullptr);
		return scene;
	}
}