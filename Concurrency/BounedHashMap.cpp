/* Bounded Hash Map using semaphore.

   We leverage an existing hashmap implementation and
   use semaphore to count.  Note we can also use
   Condition Variables.
*/

class BoundedHashMap<Key, Val> {
   
   HashMap<Key, Val> map;
   Semaphore sem;  // used to block new elements if the max is reached
   Mutex lock; // lock to protect the map

   BoundedHashMap(int size) : sem(size) {
   }

   Val get(Key k) {
      Val v = null;
      lock.wait();

      Hashmap::iterator it = map.find(k);
      if (it != map.end()) {
         v = *it;
      }
      lock.signal();
      return v;
   }

   void set(Key k, Val v) {
      sem.wait(); // count down since we are adding
      lock.wait();

      Hashmap::iterator it = map.find(k);
      if (it == map.end()) {
         map.;
      } else {
         // we did not add the item to the map since
         // it already existed.  Count back up.
         sem.signal(); 
      }
      
      lock.signal();
   }

   void erase(Key k) {
      lock.wait();

      Hashmap::iterator it = map.find(k);
      if (it != map.end()) {
         map.earse(it);
         // we earsed an element so count up
         sem.signal(); 
      }

      lock.signal();
   }
}