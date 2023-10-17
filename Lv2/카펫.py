def solution(brown, yellow):
    yellow_rows = 1
    yellow_cols = yellow / yellow_rows
    while yellow_cols >= yellow_rows:
        rows = yellow_rows+2
        cols = yellow_cols+2
        if brown == (rows + cols) * 2 - 4:
            return [cols, rows]
        yellow_rows += 1
        yellow_cols = yellow / yellow_rows