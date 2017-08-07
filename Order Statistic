//(...) Inserir template normalmente

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
using namespace __gnu_pbds;
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;//n é multi
 
 
int main(){
  ordered_set os;
  
  os.insert(1);
  os.insert(10);
  os.insert(1);
  os.insert(15);
  
  cout << (os.find(10) == end(os)) << endl;//0 mesma coisa q !count
  cout << os.order_of_key(10) << endl;//1 qual o indice do valor 10, se n tem o indice, pega o proximo
  cout << os.order_of_key(2) << endl;//1
  cout << *os.upper_bound(2) << endl;//10 !!!Retorna iterador!!!
  cout << *os.find_by_order(0) << endl;//1 !!!Retorna iterador!!!
  cout << *os.find_by_order(2) << endl;//15 !!!Retorna iterador!!!
  return 0;
}
