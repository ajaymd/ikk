/* Create object cache, such as a database connection pool */
class ConnectionPool<T> {
	int maxObjects;
	int allocObjects;
	List<T> freeObjects;
	Mutex lock;
	ConditionVariable cvNoObjects(&lock);

	ConnectionPool(int max)
		: maxObjects(max)
		, allocObjects(0) {}

	T* get() {
		T* val = null;

		lock.wait();

		// wait until there is an object available if we are maxed out.
		while (allocObjects == maxObjects) {
			cvNoObjects.wait();
		}

		// get the first free object from the list
		if (freeObjects.size()) {
			val = freeObjects.popFront();
		}

		lock.signal();

		// if we do not have an object at this point it means that we 
		// should allocate an object and return it.
		// NOTE: we allocate outside the lock since there is no reason
		// to hold it during allocation.
		if (val == null) {
			val = new T();
		}
		
		return val;
	}

	void free(T* val) {
		lock.wait();

		freeObjects.add(val);
		cvNoObjects.signal();

		lock.signal();
	}
}