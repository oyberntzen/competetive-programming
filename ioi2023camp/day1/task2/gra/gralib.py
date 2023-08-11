import sys
import random

_n = None
_k = None
_M = None
_x = 0
_calls = 0
_games_remaining = 100
_prev = 0
_initialized = False


def _read():
    global _n, _k, _M
    _n, _k, _M, seed = [int(x) for x in sys.stdin.readline().split()]
    random.seed(seed)

def _init():
    global _initialized
    if not _initialized:
        _read()
        _initialized = True


def dajN():
    _init()
    return _n


def dajK():
    _init()
    return _k

def dajM():
    _init()
    return _M

def nastepna():
    global _calls, _prev
    _init()

    _calls += 1

    if _calls > _M:
        print("Przekroczono limit zapytan.")
        sys.exit(0)

    _prev = random.randint(1, _k)
    return _prev


def zwieksz():
    global _x, _prev
    _init()

    if _prev == 0:
        print("Program wywoluje zwieksz() bez wczesniejszego wywolania nastepna().")
        sys.exit(0)
    if _x % _prev != 0:
        print("Proba zwiekszenia licznika o liczbe niebedaca jego dzielnikiem.")
        sys.exit(0)

    _x += _prev
    _prev = 0

    if _x > _n:
        print("Licznik przekroczyl n.")
        sys.exit(0)


def koniec():
    global _x, _games_remaining, _calls, _prev
    _init()

    if _x != _n:
        print("Zla odpowiedz: " + str(_x))
        sys.exit(0)

    if _games_remaining == 1:
        print("OK")
    elif _games_remaining <= 0:
        print("Program wywoluje koniec() zbyt wiele razy.")
        sys.exit(0)

    _games_remaining -= 1
    _x = 0
    _calls = 0
    _prev = 0
