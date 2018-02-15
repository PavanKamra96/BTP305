/** 
	Name: Pavan Kumar Kamra
	Course: BTP305
**/

#include <iostream> 
#include <string>

template < typename K, typename V, int n >
  class KVList {
    private:
      K a[n];
    V b[n];
    size_t count;

    public:
      KVList(): count(0) {};

    size_t size() const {
      return count;
    }

    const K & key(int i) const {
      return a[i];
    }

    const V & value(int i) const {
      return b[i];
    }

    KVList & add(const K & key,
      const V & value) {
      if (n > count) {
        a[count] = key;
        b[count] = value;
        count++;
      }
      return *this;
    }

    int find(const K & k) const {
      if (count > 0) {
        for (int i = 0; i < count; i++) {
          if (a[i] == k) {
            return i;
          }
        }
      }
      return 0;
    }

    KVList & replace(int i,
      const K & k,
        const V & v) {
      if (count >= i) {
        a[i] = k;
        b[i] = v;
      }
      return *this;
    }
  };
		
