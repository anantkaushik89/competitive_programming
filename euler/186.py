#!/usr/bin/env python

values_c = []
values_cc = []
map_t = {}
par = []
rank = []
aux = []
maxn = 2000001
mod = 1000000

def init():
    par.append(0)
    rank.append(0)
    aux.append(0)
    for i in range(1, maxn):
        par.append(i)
        rank.append(1)

    for i in range(1, 2 * maxn):
        if i < 56:
            t = (100003 - 200003 * i + 300007 * i * i * i) % 1000000
        else:
            t = (aux[i - 24] + aux[i - 55]) % 1000000
        aux.append(t)

    values_c.append(0)
    values_cc.append(0)
    v = 0
    for i in range(1, maxn):
        values_c.append(aux[2 * i - 1])
        values_cc.append(aux[2 * i])
        if values_c[i] == values_cc[i]:
            v += 1
        print(values_c[i], values_cc[i])
    print(v)

init()
