#pragma once

#include <list>
#include <vector>
#include <string>

namespace Tvdr{

	class Object{
		friend class Scene;
	private:
		std::list<Object*> _children;
		Object* _parent;
	protected:
		bool AddChild(Object* obj);
		
		virtual void Update();
		virtual void Render();
	public:
		static Object* CreateObject(Object* parent = nullptr);
		void SetParent(Object* parent);
		Object const *GetParent();

		Object();
		virtual ~Object();
	};
}