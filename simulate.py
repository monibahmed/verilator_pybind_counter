#!python 

import sys

sys.path.append('../build')
print(sys.path)

import Vcounter
c = Vcounter.Vcounter()
c.reset(True)
c.eval()
c.reset(False)

for _ in range(15):
    c.eval()