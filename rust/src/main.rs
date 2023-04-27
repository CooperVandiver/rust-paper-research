#![allow(dead_code, unused_imports)]

use rand::Rng;
use std::time::{SystemTime};

const MAX_THREAD: i32 = 8;
const M: i32 = 1000; 
const N: i32 = 1000;
const P: i32 = 1000;

mod matrix_multiplication;
mod determinant;

use matrix_multiplication::{ mat_mul, mat_mul_thread };
use determinant::find_det;

#[allow(unused_variables)]
fn main() {
    let mut rng = rand::thread_rng();

    let x: Vec<Vec<i32>> = (0..M).map(|_| (0..N).map(|_| rng.gen_range(1..=2)).collect()).collect();
    let y: Vec<Vec<i32>> = (0..N).map(|_| (0..P).map(|_| rng.gen_range(1..=2)).collect()).collect();
    //let z = mat_mul_thread(Arc::new(x), Arc::new(y));
	//let start = SystemTime::now();
	//println!("{}x{} * {}x{}: {} ms", M, N, N, P, start.elapsed().unwrap().as_millis());*/


    let mut x: Vec<Vec<f64>> = (0..M).map(|_| (0..N).map(|_| rng.gen_range(1..=2) as f64).collect()).collect();
    match find_det(&mut x) {
        Some(result) => println!("Determinant: {}", result),
        None => println!("Matrix is not square."),
    }
}
