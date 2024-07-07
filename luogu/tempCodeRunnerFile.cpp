if(n >= 1e8) {
        int k = n / (int)1e8;
        p[k].first--;
        while(p[k].first--) it++;
        op = p[k].second;
        n %= (int)1e8;
    }