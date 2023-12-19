import sys

sys.path.append('./build')
print(sys.path)

import Vcounter
c = Vcounter.Vcounter()
c.reset(True)
c.tick()
c.reset(False)

for _ in range(16):
    print(c.out())
    c.tick()