/* Rate limiter.  Limit calls to doWork to n per interval.  Call doDrop if the 
	limit has been reached for the interval.
	Assume doWork and doDrop are asynchronous functions.
*/

Queue<int> queue;
int intervalMS = 2000; // two seconds (as an example)
int n = 10; // 10 requests per 2 seconds (as an example)

void OnRequestRecieve(Req& r) {
	int time = timeGetTime(); // set time since boot in milliseconds.

	if (queue.size() < n) {
		// trivial case.  we are not at the limit.
		queue.push(time);
		doWork(r);
	} else {
		if ((time - queue.peek()) > intervalMS) {
			// the oldest request interval has expired.  Lets doWork().
			queue.pop();
			queue.push(time);
			doWork(r);
		} else {
			// no space in queue which means all requests in the queue 
			// are still valid.
			doDrop(r);
		}
	}
}