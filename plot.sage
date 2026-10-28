import os

def readFile(filename):
    v = []
    path = "data/" + filename
    with open(path) as f:
        for line in f:
            v.append([float(x) for x in line.split()])
    return v

def create_graph(data, couleur, legende, style):
    return line(data, rgbcolor=couleur, legend_label=legende, linestyle=style)

Gnlogn = Graphics()
algos_fast = [("stdsort", "green"), ("stablesort", "red"), ("quicksort", "blue"), ("modifquicksort", "black")]
variantes = [("1", "solid", " (all random)"), ("2", "dashed", " (half sorted)"), ("3", "dotted", " (half reversed)")]

for alg in algos_fast:
    for var in variantes:
        data = readFile(alg[0] + var[0] + ".data")
        Gnlogn += create_graph(data, alg[1], alg[0] + var[2], var[1])

Gnlogn.axes_labels(['n', 'Temps (us)'])
Gnlogn.save('O(nlogn).png', title="Graphique des algorithmes de tri en O(nlogn)")

Gn2 = Graphics()
algos_slow = [("insertion", "red"), ("selection", "blue")]

for alg in algos_slow:
    for var in variantes:
        data = readFile(alg[0] + var[0] + ".data")
        Gn2 += create_graph(data, alg[1], alg[0] + var[2], var[1])

Gn2.axes_labels(['n', 'Temps (us)'])
Gn2.save('O(n2).png', title="Graphique des algorithmes de tri en O(n2)")