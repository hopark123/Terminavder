#pragma once

#include <list>
#include <vector>
#include <string>

namespace Tvdr{
	class Object{
	private:
		std::list<Object*> _children;
		Object* _parent;
	protected:
		Object();
		bool AddChild(Object* obj);
		virtual bool Destroy();

		virtual void Start();
		virtual void Update();
		virtual void Render(std::vector<std::string> &screen);
	public:
		static Object* CreateObject(Object* parent = nullptr);
		void SetParent(Object* parent);
		Object const *GetParent();


		virtual ~Object();
	};
}