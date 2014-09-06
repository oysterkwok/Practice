#include <iostream>

using namespace std;

public class segment_tree {
  class STnode {
    public int aa, la, ar, lr;
    public int left, right, middle;
    public int li, ri, mi;
    public STnode(int pos, int val) {
      this.left = pos;
      this.right = pos;
      this.middle = pos;
      this.aa = (val > 0)?val:0;
      this.la = node.aa;
      this.ar = node.aa;
      this.lr = val;
      this.li = -1;
      this.ri = -1;
      this.mi = pos;
    }
    public STnode(STnode leftChild, STnode rightChild, int index) {
      this.left = leftChild.left;
      this.middle = leftChild.right;
      this.right = rightChild.right;
      this.aa = Math.max(leftChild.aa, rightChild.aa, leftChild.ar+rightChild.la);
      this.la = Math.max(leftChild.la, leftChild.lr+rightChild.la);
      this.ar = Math.max(leftChild.ar+rightChild.lr, rightChild.ar);
      this.lr = leftChild.lr+rightChild.lr;
      this.li = leftChild.mi;
      this.ri = rightChild.mi;
      this.mi = index;
    }
  }

  public ArrayList<STnode> tree = new ArrayList<STnode>();

  public int query_max_lr(int start, int end, STnode node) {
    if (start > end) return 0;
    if (start == node.left && end == node.right) {
      return node.lr;
    }
    if (start > node.middle) {
      return query_max_lr(start, end, tree.get(node.ri));
    }
    if (start <= node.middle && node.middle < end) {
      int lm = query_max_lr(start, node.middle, tree.get(node.li));
      int mr = query_max_lr(node.middle+1, end, tree.get(node.ri));
      return lm+mr;
    }
    if (node.middle >= end) {
      return query_max_lr(start, end, tree.get(node.li));
    }
  }

  public int query_max_aa(int start, int end, STnode node) {
    if (start > end) return 0;
    if (start == node.left && end == node.right) {
      return node.aa;
    }
    if (start > node.middle) {
      return query_max_aa(start, end, tree.get(node.ri));
    }
    if (start <= node.middle && node.middle < end) {
      int am = query_max_ar(start, node.middle, tree.get(node.li));
      int ma = query_max_la(node.middle+1, end, tree.get(node.ri));
      return Math.max(am+ma, query_max_aa(start, node.middle, tree.get(node.li)), query_max_aa(node.middle, end, tree.get(node.ri)));
    }
    if (node.middle >= end) {
      return query_max_aa(start, end, tree.get(node.li));
    }
  }

  public int query_max_la(int start, int end, STnode node) {
    if (start > end) return 0;
    if (start == node.left && end == node.right) {
      return node.la;
    }
    if (start > node.middle) {
      return query_max_la(start, end, tree.get(node.ri));
    }
    if (start <= node.middle && node.middle < end) {
      int lm = query_max_lr(start, node.middle, tree.get(node.li));
      int ma = query_max_la(node.middle+1, end, tree.get(node.ri));
      return Math.max(lm+ma, query_max_la(start, node.middle, tree.get(node.li)));
    }
    if (node.middle >= end) {
      return query_max_la(start, end, tree.get(node.li));
    }
  }

  public int query_max_ar(int start, int end, STnode node) {
    if (start > end) return 0;
    if (start == node.left && end == node.right) {
      return node.ar;
    }
    if (start > node.middle) {
      return query_max_ar(start, end, tree.get(node.ri));
    }
    if (start <= node.middle && node.middle < end) {
      int am = query_max_ar(start, node.middle, tree.get(node.li));
      int mr = query_max_lr(node.middle+1, end, tree.get(node.ri));      
      return Math.max(am+mr, query_max_ar(node.middle+1, end, tree.get(node.ri)));
    }
    if (node.middle >= end) {
      return query_max_ar(start, end, tree.get(node.li));
    }
  }

  public void buildTree(ArrayList<Integer> data) {
    // build tree
    int baseSize = 1;
    while (baseSize < data.length) baseSize <<= 1;
    for (int i = 0; i < data.length; i ++) {
      STnode node = new STnode(i, data.get(i));
      tree.add(node);
    }
    for (int i = data.length(); i < baseSize; i ++) {
      STnode node = new STnode(i, 0);
      tree.add(node);
    }
    while (baseSize > 0) {
      for (int i = 0; i < baseSize/2; i ++) {
        int lc = tree.size()-baseSize+i;
        int rc = lc+1;
        STnode node = new STnode(tree.get(lc), tree.get(rc), tree.size());
        tree.add(node);
      }
      baseSize /= 2;
    }
  }

  public static void Main(String[] args) {
    ArrayList<Integer> data = new ArrayList<Integer>(20, 4, 20, 1, 4);
    
    segmentTree ST = new segmentTree();
    ST.buildTree(data);

    // query
    int result = ST.query_max_aa(1, 4, ST.tree.get(tree.size()-1));
  }
}

