#pragma once

#include <list>
#include <vector>
#include <string>
#include <Vector.hpp>

namespace Tvdr{

	class Object{
		friend class Scene;
	private:
		std::list<Object*> _children;
		Object* _parent;
	protected:
		Vector _position;
		Vector _scale;
		float _rotate;

		bool AddChild(Object* obj);
		
		virtual void Update();
		virtual void Render();
	public:
		void SetParent(Object* parent);
		Object const *GetParent();
		void Release();

		Object();
		virtual ~Object();
	};
}