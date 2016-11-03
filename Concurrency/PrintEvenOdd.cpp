/* print odd and even numbers using two threads. 
   NOTE: we need to force specific execution order since locks are unfair.
*/

void PrintOddEven(int max, bool bEven, Semaphore& me, Semaphore& other)
{
	int n = (bEven)? 0 : 1;

	while(n < max) {
		me.wait();

		print("%d:%d\n", getThreadId(), n);
		n += 2;
		other.signal();
	}
}

Semaphore semOdd(0);
Semaphore semEven(1);
const int COUNT = 1000;

void main() {

	CreateThread( () => {
		PrintOddEven(COUNT, true, semEven, semOdd);
	});

	PrintOddEven(COUNT, false, semOdd, semEven);
}