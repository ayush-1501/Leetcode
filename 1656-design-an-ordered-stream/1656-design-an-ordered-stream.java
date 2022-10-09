class OrderedStream {
     String[] v;
     int ptr;

    public OrderedStream(int n) {
        v = new String[n];
        ptr = 0;
    }
    
    public List<String> insert(int id, String value) {
        v[id - 1] = value;

        List<String> result = new ArrayList();
        while (ptr < v.length && v[ptr] != null) {
            result.add(v[ptr++]);
        }

        return result;
    }

}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */