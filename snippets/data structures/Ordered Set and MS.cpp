#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define pbds_set(T)                                                            \
  tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag,               \
       tree_order_statistics_node_update>

//find_by_order returns iterator to that position 0-based index
// order_of_key returns number of elements strictly less than val
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> struct OrderedMultiset {
  pbds_set(T) st;
  int counter = 0;
  void insert(T val) { st.insert({val, counter++}); }

  void erase(T val) {
    auto it = st.lower_bound({val, 0});
    if (it != st.end() && it->first == val) {
      st.erase(it);
    }
  }
  T find_by_order(int k) { return st.find_by_order(k)->first; }
  int order_of_key(T val) { return st.order_of_key({val, 0}); }
  int size() { return st.size(); }
};
