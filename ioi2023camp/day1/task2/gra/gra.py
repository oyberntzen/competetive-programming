from gralib import dajN, dajK, dajM, nastepna, zwieksz, koniec

n = dajN()

for i in range(n):
    y = nastepna()

    if y % 2 == 0:
        zwieksz()

koniec()
