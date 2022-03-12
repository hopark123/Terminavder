#pragma once
#include <map>
#include <stack>

namespace Tvdr{
	class MemoryPool{
	private:
		static MemoryPool _instance;

		std::map<size_t, std::stack<void*> > _pool;
		std::stack<void*> _garbageCollector;
	public:
		static MemoryPool *Instance();

		static void* Alloc(size_t size);
		static void Dealloc(void* memory, size_t size);
	private:
		MemoryPool();
		~MemoryPool();
	};
}