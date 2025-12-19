int maxMinMultiplication(int* data, int size) {
    if (size < 3) return -1;

    int min_idx = 1;
    int i = 0;

    while (1) {
        int tmp = 2 * i + 1;
        if (tmp < size) {
            min_idx = tmp;
            i = tmp;
            continue;
        }
        break;
    }

    int max_idx = 2;
    i = 0;

    while (1) {
        int tmp = 2 * i + 2;
        if (tmp < size) {
            max_idx = tmp;
            i = tmp;
            continue;
        }
        break;
    }

    return data[min_idx] * data[max_idx];
}
