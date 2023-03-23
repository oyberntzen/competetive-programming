length = 100000
length_per_reindeer = 1000
shifts = length//length_per_reindeer

weight = 900+100
reindeers = 0
for i in range(shifts):
    weight += length_per_reindeer
    new_reindeers = (weight+199)//200 + (reindeers+1)//2
    reindeers += new_reindeers
    print(reindeers)