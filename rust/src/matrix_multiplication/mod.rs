use std::thread::{ self, JoinHandle };
use std::sync::{ Arc, atomic::{ AtomicI32, Ordering }, };
use std::time::SystemTime;
use crate::{ MAX_THREAD };

pub fn mat_mul(x: &Vec<Vec<i32>>, y: &Vec<Vec<i32>>) -> Option<Vec<Vec<i32>>> {
	match x[0].len() == y.len() {
		true => Some((0 .. x.len())
			.map(|i| {
				(0 .. y[0].len())
					.map(|j| {
						(0 .. y.len()).fold(0, |acc, k| {
							acc + x[i][k] * y[k][j]
						})
					})
					.collect::<Vec<i32>>()
			})
			.collect::<Vec<Vec<i32>>>()),
		false => None,
	}
}

pub fn mat_mul_thread(x: Arc<Vec<Vec<i32>>>, y: Arc<Vec<Vec<i32>>>) -> Option<Vec<Vec<i32>>> {
    if x[0].len() != y.len() {
        println!("Matrices are not conformable.");
        return None;
    }

    let mut handles: Vec<JoinHandle<Vec<i32>>> = Vec::with_capacity(x.len());
    let mut res: Vec<Vec<i32>> = Vec::with_capacity(x.len());
    let thread_count: Arc<AtomicI32> = Arc::new(AtomicI32::new(0));
    for i in 0..x.len() {
        while thread_count.load(Ordering::Relaxed) >= MAX_THREAD {}
        thread_count.fetch_add(1, Ordering::Relaxed);
		let x = Arc::clone(&x);
		let y = Arc::clone(&y);
        let thread_count = Arc::clone(&thread_count);
        handles.push(thread::spawn(move || {
            let start = SystemTime::now();
            let res = (0..y[0].len()).map(|j| {
                (0..y.len()).fold(0, |acc, k | {
                    acc + x[i][k] * y[k][j]
                })
            }).collect::<Vec<i32>>();
            println!("Thread {}: {} ns", i, start.elapsed().unwrap().as_micros());
            thread_count.fetch_sub(1, Ordering::Relaxed);
            res
        }));
    }
    for i in handles.into_iter() {
        res.push(i.join().unwrap());
    }
    Some(res)
}