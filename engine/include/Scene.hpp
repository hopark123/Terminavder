#pragma once

#include <Object.hpp>

namespace Tvdr{
	class Scene : public Object{
	private:
		void StartAll();
		void UpdateAll();
	public:
		static Scene* CreateScene();	
	};
}