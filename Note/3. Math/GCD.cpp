int GCD(int a, int b) {
    if (a < b) swap(a, b);
    int tmp;
    while (b)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}