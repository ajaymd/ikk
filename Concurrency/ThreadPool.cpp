/* Thread pool using producer/consumer queue */
class ThreadPool() {
	
	ProducerConsumerQueue queue;
	
	ThreadPool(int size) {
		for (int i = 0; i < size; ++i) {

			CreateThread( () => {

				while (true) {

					Task& t = queue.pop();

					try {
						t.run();
					} catch(Exception e) {
						t.error(e);
					}
				}
			});
		}
	}

	void Execute(Task& t) {
		queue.push(t);
	}
}