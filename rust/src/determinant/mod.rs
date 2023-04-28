#[allow(unused_variables)]

pub fn find_det(a: &mut Vec<Vec<f64>>) -> Option<f64> {
    // matrix not square, determinant is invalid
    if a.len() != a[0].len() {
        return None;
    }

    let tol = 1e-9;
    let n = a.len();

    // permutation vector
    let mut p: Vec<f64> = (0..=n).map(|i| {
        i as f64
    }).collect();

    for i in 0..n {
        let mut max_a: f64 = 0.0;
        let mut max_row: usize = i;

        // max element in current column
        for k in i..n {
            if a[k][i].abs() > max_a {
                max_a = a[k][i].abs();
                max_row = k;
            }
        }

        // checking for singularity
        if max_a < tol {
            return Some(0.0); // matrix is singular, determinant is 0
        }

        // swapping rows
        if max_row != i {
            p.swap(i, max_row);
            for k in 0..n {
                let temp = a[i][k];
                a[i][k] = a[max_row][k];
                a[max_row][k] = temp;
            }
        }

        // Gaussian elimination
        for k in (i+1)..n {
            a[k][i] /= a[i][i];
            for j in (i+1)..n {
                a[k][j] -= a[k][i] * a[i][j];
            }
        }
    }    

    // calculating and returning determinant
    Some((0..n).fold(1.0, |acc, i| {
        acc * a[i][i]
    }))

}