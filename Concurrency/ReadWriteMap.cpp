/*  Create a map with a read/write lock.  Push the lock into the data structure.
	Lets assume we have a reader writer lock.
 */
class ReaderWriterMap<Key, Val> {
	Vector< pair<ReaderWriterLock, Map<Key,Val> > > buckets;
	ReaderWriterLock bucketsLock;
	int size;

	ReaderWriterMap() {
		buckets = new Vector< pair<ReaderWriterLock, Map<Key,Val> > >();
		buckets.resize(DEFAULT_SIZE);
		size = 0;
	}

	~ReaderWriterMap() {
		delete buckets;
	}

	Val get(Key k) {
		Val val = null;
		int hash = Hash(k);
		bucketsLock.readLock();

		auto bucket = buckets[hash % buckets.size()];

		bucket.lock.readLock()
		// Note there is a second hash of k here.  Using map as collision data
		// structure for convenience.
		Map<k, v>::iterator it = bucket.map.find(k);
		if (it != bucket.map.end()) {
			val = *it;
		}
		bucket.lock.readUnlock();
		
		bucketsLock.readUnlock();
		return val;
	}

	void set(Key k, Val v) {
		Val val = null;
		int hash = Hash(k);
		bool bResizeBuckets = false;

		bucketsLock.readLock();

		auto bucket = buckets[hash % buckets.size()];

		bucket.lock.writeLock()
		// Note there is a second hash of k here.  Using map as collision data
		// structure for convenience.
		bucket.map[k] = v;
		++size;

		// resize the data structure if we get too many collisions.
		bResizeBuckets = size >= buckets.size();

		bucket.lock.writeUnlock();
		
		bucketsLock.readUnlock();
		
		if (bResizeBuckets) {
			bucketsLock.writeLock();
			resize();
			bucketsLock.writeUnlock();
		}
	}

	void resize() {
		// loop over exisiting buckets and re-insert into larger
		// number of buckets.
	}
}

