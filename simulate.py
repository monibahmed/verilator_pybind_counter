## import sys
## 
## sys.path.append('/Users/monibahmed/Projects/counter/build')
## import counter


import counter

c = counter.Vcounter()
c.reset(True)
c.tick()
c.reset(False)

for _ in range(16):
    print(c.out())
    c.tick()