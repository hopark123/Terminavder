#include <MemoryPool.hpp>
#include <cstdlib>

using namespace std;

namespace Tvdr{

	MemoryPool MemoryPool::_instance;
	MemoryPool *MemoryPool::Instance() {
		return &_instance;
	}

	MemoryPool::MemoryPool(){

	}

	MemoryPool::~MemoryPool(){
		while (!_garbageCollector.empty()){
			free(_garbageCollector.top());
			_garbageCollector.pop();
		}
	}

	void* MemoryPool::Alloc(size_t size){
		void* mem = nullptr;
		auto st = &_instance._pool[size];
		if (st->empty()) {
			mem = malloc(size);
			_instance._garbageCollector.push(mem);
		}
		else{
			mem = st->top();
			st->pop();
		}
		return mem;
	}

	void MemoryPool::Dealloc(void* memory, size_t size){
		auto st = &_instance._pool[size];
		st->push(memory);
	}
}