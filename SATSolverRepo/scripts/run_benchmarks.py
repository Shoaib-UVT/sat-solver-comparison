#!/usr/bin/env python3
import os, subprocess, time, csv
methods=['dpll','dp','resolution']
runs=3
bench='benchmarks'; build='build'
files=sorted(f for f in os.listdir(bench) if f.endswith('.cnf'))
with open('benchmark_results.csv','w',newline='') as csvfile:
    w=csv.writer(csvfile); w.writerow(['Instance','Method','Run','Result','Time_s'])
    for inst in files:
        for m in methods:
            exe=os.path.join(build,'satsolver')
            for r in range(1,runs+1):
                t1=time.time()
                p=subprocess.run([exe,m,os.path.join(bench,inst)],capture_output=True,text=True)
                dt=time.time()-t1
                res=p.stdout.splitlines()[0] if p.stdout else 'ERR'
                w.writerow([inst,m,r,res,f"{dt:.6f}"])
print('Done')
