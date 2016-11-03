/* Thread Local Storage class.  We want an interface to get a memory block
   on a per-thread basis.
   Note: the per-thread map is a pointer, not aggregated so we only need to
   		 to hold the lock when accessing the outer map.  We know by design
   		 that only one thread can access the inner map at a time.
   */

class ThreadLocalStorage {
	
	Map<int, Map<int, void*>* > map;
	Mutex lock;

	void* get(int id, int sizeBytes) {
		int threadId = getThreadId();
		Map<int, void*>* localMap = null;
		void* pMem = null;
			
		lock.wait();

		Map<int, Map<int, void*>* >::iterator it = map.find(threadId);
		if (it != map.end()) {
			localMap = *it;
		} else {
			// first time we were called on this thread.  Create map for 
			// the thread.
			localMap = new Map<int, void*>*();
			map[threadId] = localMap;
		}
		
		lock.signal();

		Map<int, void*>*::iterator it = localMap.find(id);
		if (it == localMap.end()) {
			pMem = malloc(sizeBytes);
			localMap[id] = pMem;
		} else {
			pMem = *it;
		}

		return pMem;
	}

	void erase(int id) {
		int threadId = getThreadId();
		Map<int, void*>* localMap = null;
			
		lock.wait();

		Map<int, Map<int, void*>* >::iterator it = map.find(threadId);
		if (it != map.end()) {
			localMap = *it;
		}

		lock.signal();

		if (localMap) {
			localMap.erase(id);
		}
	}

	void removeThread() {
		int threadId = getThreadId();
		Map<int, void*>* localMap = null;
			
		lock.wait();

		Map<int, Map<int, void*>* >::iterator it = map.find(threadId);
		if (it != map.end()) {
			map.erase(it);
		}

		lock.signal();

		delete localMap;
	}
}