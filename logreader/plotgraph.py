import numpy as np
import matplotlib.pyplot as plt
import matplotlib
matplotlib.use('GTK3Agg')

methods = open("graph.txt", "r").readlines()
N = len(methods[0].split()) - 1
ind = np.arange(N)
bot = (0,)*N
for i in methods:
  line = [int(j) for j in i.split()]
  y=tuple(line[1:])
  plt.bar(ind, y, bottom=bot)
  bot = tuple(map(sum, zip(y, bot)))
plt.show()
