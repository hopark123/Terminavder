#pragma once

#include <Object.hpp>
#include <Vector.hpp>

namespace Tvdr{
	class GameObject : public Object{
	private:
		std::vector<std::string> _model;
		Vector _position;

		virtual void Render(std::vector<std::string> &screen);
	protected:	
		GameObject();
	public:
		static GameObject* CreateGameObject(std::vector<std::string> const &model, Object* parent);
		Vector const &GetPosition() {return _position;}
		void SetPosition(int x, int y) {_position.x = x; _position.y = y;}
		int const GetX() {return _position.x;}
		int const GetY() {return _position.y;}
		virtual ~GameObject();
	};
}