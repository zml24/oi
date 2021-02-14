for (int i = 0, j = 0; i < n; i++) {
    while (j < i && check(i, j)) j++;
    add(i);
    res = get(i, j);
    //do sth.
}
