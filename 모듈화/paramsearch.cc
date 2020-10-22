    int lo = 0, hi = 5001; int mid = 0;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (f(mid))hi = mid;
        else lo = mid + 1;
    }
    else cout << lo;