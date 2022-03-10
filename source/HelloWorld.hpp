#pragma once

#include <TVDR.hpp>

class HelloWorld : public Tvdr::Scene {
protected:
	void Start();
	virtual void Update();
public:
	HelloWorld();
	virtual ~HelloWorld(){}
};