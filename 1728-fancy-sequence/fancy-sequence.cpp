class Fancy {
public:
    vector<long long> res;
    long long addInc = 0, multInc = 1;
    long long mod = 1000000007;

    Fancy() {}

    void append(int val) {
        val = (val - addInc + mod) % mod;
        val = (val * modInverse(multInc, mod)) % mod;
        res.push_back(val);
    }

    void addAll(int inc) {
        addInc = (addInc + inc) % mod;
    }

    void multAll(int m) {
        multInc = (multInc * m) % mod;
        addInc = (addInc * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= res.size())
            return -1;

        long long val = res[idx];
        val = (val * multInc) % mod;
        val = (val + addInc) % mod;

        return static_cast<int>(val);
    }

private:
    long long modInverse(long long a, long long m) {
        // Function to calculate the modular inverse
        // Assumes that m is a prime number
        long long m0 = m, t, q;
        long long x0 = 0, x1 = 1;

        while (a > 1) {
            q = a / m;
            t = m;
            m = a % m, a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }

        if (x1 < 0) x1 += m0;

        return x1;
    }
};
/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */