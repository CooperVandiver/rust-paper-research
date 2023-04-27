import subprocess
import os

os.system('cargo build --release')
times = []
for i in range(100):
	result = subprocess.run(["./target/release/rust"], stdout=subprocess.PIPE, check=True, text=True)
	times.append(int(result.stdout.split('\n')[0].split()[2]))
avg = sum(times)/len(times)
print(f"Rust Determinant Avg: {avg/1000} ms")
