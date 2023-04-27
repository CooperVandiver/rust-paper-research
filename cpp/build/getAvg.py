import sys
import subprocess

avgs = []
for i in range(50):
	result = subprocess.run(["./target"], stdout = subprocess.PIPE, check = True, text = True)
	x = [i.rstrip() for i in result.stdout.split('\n') if len(i.split()) > 2]
	nums = [int(i.split()[2]) for i in x]
	avgs.append(sum(nums)/len(nums))
avg = sum(avgs)/len(avgs)
print(f"C++ Matrix Multiplication Avg: {avg/1000} ms")
