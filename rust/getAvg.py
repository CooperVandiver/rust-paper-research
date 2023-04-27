import subprocess
import os

os.system('cargo build --release')
avgs = []
for i in range(50):
	result = subprocess.run(["./target/release/rust"], stdout=subprocess.PIPE, check=True, text=True)
	x = [i.rstrip() for i in result.stdout.split('\n') if len(i.split()) == 4]
	nums = [int(i.split()[2]) for i in x]
	avgs.append(sum(nums)/len(nums))
avg = sum(avgs)/len(avgs)
print(f"Rust Matrix Multiplication Avg: {avg/1000} ms")
