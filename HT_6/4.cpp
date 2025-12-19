int pascal(int row, int col) {
    if (col == 0 || row == col) return 1;
    return pascal(row-1, col-1) + pascal(row-1, col);
}
