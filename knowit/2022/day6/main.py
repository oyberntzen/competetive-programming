with open("slemmehandlinger.txt", "r") as f:
    slemmeHandlinger = f.readlines()

values = {}
for handling in slemmeHandlinger:
    a = handling.replace("\n", "").split(":")
    values[a[0]] = float(a[1])

with open("stemmer.txt", "r") as f:
    stemmer = f.readlines()

kandidater = {}
for stemme in stemmer:
    a = stemme.replace("\n", "").split(":")
    if kandidater.get(a[1]) == None:
        kandidater[a[1]] = 0
    kandidater[a[1]] += min([1 if values.get(b) == None else values.get(b) for b in a[0].split(",")])

resultat = list(kandidater.values())
resultat.sort()

print(round(resultat[len(resultat)-1] - resultat[len(resultat)-2]))