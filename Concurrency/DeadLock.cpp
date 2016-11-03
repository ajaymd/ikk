/* Show a deadlock */

Mutex a;
Mutex b;

Thread0Callback() {
	a.wait();
	b.wait();

	// do work that requires locks

	b.signal();
	a.signal();
}

Thread1Callback() {
	b.wait();
	a.wait();

	// do work that requires locks

	a.signal();
	b.signal();
}