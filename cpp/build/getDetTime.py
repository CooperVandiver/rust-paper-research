import subprocess
import os

times = []
for i in range(100):
	result = subprocess.run(["./target"], stdout=subprocess.PIPE, check=True, text=True)
	times.append(int(result.stdout.split('\n')[0].split()[2]))
avg = sum(times)/len(times)
print(f"C++ Determinant Avg: {avg/1000} ms")
