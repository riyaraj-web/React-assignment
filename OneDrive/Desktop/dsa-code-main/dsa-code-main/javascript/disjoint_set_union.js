/*
Disjoint Set Union (Union-Find) implementation in JavaScript

Supports:
- find with path compression
- union by rank/size
- connected queries
- component size

Use-cases:
- Kruskal's MST
- Connected components
- Cycle detection in undirected graphs
- Dynamic connectivity
*/

class DisjointSetUnion {
  constructor(n) {
    if (typeof n !== 'number' || n <= 0 || !Number.isInteger(n)) {
      throw new Error('DisjointSetUnion requires a positive integer size');
    }
    this.parent = new Array(n);
    this.rank = new Array(n).fill(0);
    this.sizeArr = new Array(n).fill(1);
    for (let i = 0; i < n; i += 1) this.parent[i] = i;
    this.numComponents = n;
  }

  // Find representative with path compression
  find(x) {
    this.#validateIndex(x);
    if (this.parent[x] !== x) {
      this.parent[x] = this.find(this.parent[x]);
    }
    return this.parent[x];
  }

  // Union by rank; returns true if merged, false if already same set
  union(a, b) {
    this.#validateIndex(a);
    this.#validateIndex(b);
    let ra = this.find(a);
    let rb = this.find(b);
    if (ra === rb) return false;

    if (this.rank[ra] < this.rank[rb]) {
      [ra, rb] = [rb, ra];
    }
    this.parent[rb] = ra;
    this.sizeArr[ra] += this.sizeArr[rb];
    if (this.rank[ra] === this.rank[rb]) this.rank[ra] += 1;
    this.numComponents -= 1;
    return true;
  }

  // Are a and b in the same component?
  connected(a, b) {
    return this.find(a) === this.find(b);
  }

  // Size of the component containing x
  componentSize(x) {
    const r = this.find(x);
    return this.sizeArr[r];
  }

  // Total number of components
  components() {
    return this.numComponents;
  }

  #validateIndex(x) {
    if (!Number.isInteger(x) || x < 0 || x >= this.parent.length) {
      throw new Error(`index out of bounds: ${x}`);
    }
  }
}

// Demo
function demoDSU() {
  const dsu = new DisjointSetUnion(7);
  dsu.union(0, 1);
  dsu.union(1, 2);
  dsu.union(3, 4);
  dsu.union(5, 6);
  console.log('connected(0,2):', dsu.connected(0, 2)); // true
  console.log('connected(0,3):', dsu.connected(0, 3)); // false
  console.log('size(0):', dsu.componentSize(0)); // 3
  dsu.union(2, 3);
  console.log('components:', dsu.components()); // fewer components
}

if (require.main === module) {
  demoDSU();
}

module.exports = { DisjointSetUnion };


