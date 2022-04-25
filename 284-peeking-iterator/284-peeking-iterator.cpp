/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    private:
    int curr;
    bool has_next;
public:
   
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        has_next=Iterator::hasNext();
        if(has_next){
            curr=Iterator::next();
        }
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return curr;
        
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ans=curr;
        has_next=Iterator::hasNext();
        if(has_next){
            curr=Iterator::next();
        }
        return ans;
	    
	}
	
	bool hasNext() const {
        return has_next;
	    
	}
};