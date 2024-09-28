use std::collections::VecDeque;

const MAX_CELLS: usize = 100;
const MAX_CHANGES: usize = 100;

#[derive(Clone, Copy)]
struct State {
    row: usize,
    col: usize,
    changes: usize,
}

fn within_bounds(row: usize, col: usize, num_rows: usize, num_cols: usize) -> bool {
    row < num_rows && col < num_cols
}

fn optimized_search(map: &Vec<Vec<char>>, num_rows: usize, num_cols: usize, max_changes: usize, center_row: usize, center_col: usize) -> bool {
    let row_moves: [isize; 4] = [-1, 0, 1, 0];
    let col_moves: [isize; 4] = [0, 1, 0, -1];
    let directions: [char; 4] = ['^', '>', 'v', '<'];

    let mut visited = vec![vec![vec![false; MAX_CHANGES + 1]; MAX_CELLS]; MAX_CELLS];
    let mut queue: VecDeque<State> = VecDeque::new();

    for i in 0..num_rows {
        for j in 0..num_cols {
            if i == 0 || i == num_rows - 1 || j == 0 || j == num_cols - 1 {
                queue.push_back(State { row: i, col: j, changes: 0 });
                visited[i][j][0] = true;
            }
        }
    }

    while let Some(current) = queue.pop_front() {
        let (row, col, changes) = (current.row, current.col, current.changes);

        if row == center_row && col == center_col {
            return true;
        }

        for i in 0..4 {
            if map[row][col] == directions[i] {
                let new_row = (row as isize + row_moves[i]) as usize;
                let new_col = (col as isize + col_moves[i]) as usize;

                if within_bounds(new_row, new_col, num_rows, num_cols) && !visited[new_row][new_col][changes] {
                    visited[new_row][new_col][changes] = true;
                    queue.push_back(State { row: new_row, col: new_col, changes });
                }
                break;
            }
        }

        if changes < max_changes {
            for i in 0..4 {
                if map[row][col] == directions[i] {
                    let opposite_dir = (i + 2) % 4;
                    let new_row = (row as isize + row_moves[opposite_dir]) as usize;
                    let new_col = (col as isize + col_moves[opposite_dir]) as usize;

                    if within_bounds(new_row, new_col, num_rows, num_cols) && !visited[new_row][new_col][changes + 1] {
                        visited[new_row][new_col][changes + 1] = true;
                        queue.push_back(State { row: new_row, col: new_col, changes: changes + 1 });
                    }
                    break;
                }
            }
        }
    }

    false
}

fn main() {
    let mut input = String::new();
    while std::io::stdin().read_line(&mut input).unwrap() > 0 {
        let mut values = input.split_whitespace().map(|s| s.parse::<usize>().unwrap());
        let num_rows = values.next().unwrap();
        let num_cols = values.next().unwrap();
        let max_changes = values.next().unwrap();

        if num_rows == 0 && num_cols == 0 && max_changes == 0 {
            break;
        }

        let mut map: Vec<Vec<char>> = Vec::new();
        for _ in 0..num_rows {
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            map.push(input.trim().chars().collect());
        }

        let center_row = num_rows / 2;
        let center_col = num_cols / 2;

        if optimized_search(&map, num_rows, num_cols, max_changes, center_row, center_col) {
            println!("Sim");
        } else {
            println!("Nao");
        }

        input.clear();
    }
}
