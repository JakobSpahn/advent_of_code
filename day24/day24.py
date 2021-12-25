import z3

def add_constraints(s, inp):
    for digit in inp:
        s.add(digit>0)
        s.add(digit<10)

    uVar5 =(inp[0] != 0xb) * (inp[0] + 8)
    uVar2 = uVar5 % 0x1a + 0xe != inp[1]
    uVar2 = uVar2 * (inp[1] + 0xd) + uVar5 * (uVar2 * 0x19 + 1)
    uVar5 = uVar2 % 0x1a + 10 !=inp[2]
    uVar2 = uVar5 * (inp[2] + 2) + uVar2 * (uVar5 * 0x19 + 1)
    uVar5 = uVar2 % 0x1a != inp[3]
    uVar2 = uVar5 * (inp[3] + 7) + (uVar2 / 0x1a) * (uVar5 * 0x19 + 1);
    uVar5 = uVar2 % 0x1a + 0xc != inp[4]
    uVar2 = uVar5 * (inp[4] + 0xb) + uVar2 * (uVar5 * 0x19 + 1)
    uVar5 = uVar2 % 0x1a + 0xc !=inp[5]
    lVar1 = uVar5 * (inp[5] + 4) + uVar2 * (uVar5 * 0x19 + 1)
    uVar2 = lVar1 % 0x1a + 0xc != inp[6]
    lVar1 = uVar2 * (inp[6] + 0xd) + (uVar2 * 0x19 + 1) * lVar1
    uVar2 = lVar1 % 0x1a - 8 !=inp[7]
    lVar1 = uVar2 * (inp[7] + 0xd) + (uVar2 * 0x19 + 1) * (lVar1 / 0x1a)
    uVar2 = lVar1 % 0x1a - 9 != inp[8]
    lVar1 = uVar2 * (inp[8] + 10) + (lVar1 / 0x1a) * (uVar2 * 0x19 + 1)
    uVar2 = lVar1 % 0x1a + 0xb != inp[9]
    lVar1 = uVar2 * (inp[9] + 1) + lVar1 * (uVar2 * 0x19 + 1)
    uVar2 = lVar1 % 0x1a != inp[10]
    lVar1 = uVar2 * (inp[10] + 2) + (lVar1 / 0x1a) * (uVar2 * 0x19 + 1)
    uVar2 = lVar1 % 0x1a - 5 != inp[11]
    lVar1 = uVar2 * (inp[11] + 0xe) + (uVar2 * 0x19 + 1) * (lVar1 / 0x1a)
    uVar2 = lVar1 % 0x1a - 6 != inp[12]
    lVar1 = uVar2 * (inp[12] + 6) + (uVar2 * 0x19 + 1) * (lVar1 / 0x1a)
    uVar2 = lVar1 % 0x1a - 0xc != inp[13]

    res = uVar2 * (inp[13] + 0xe) + (lVar1 / 0x1a) * (uVar2 * 0x19 + 1)

    tot = 0
    for digit in inp:
        tot = tot * 10 + digit

    s.add(res==0)
    return tot

def solve(inp, maximize=True):
    s = z3.Optimize()
    value = add_constraints(s, inp)

    if maximize:
        s.maximize(value)
    else:
        s.minimize(value)

    assert s.check() == z3.sat

    m = s.model()
    return m.eval(value)

inp = [z3.Int('x{}'.format(i)) for i in range(14)]

print('Part 1:', solve(inp,maximize=True))
print('Part 2:', solve(inp,maximize=False))
