def solve_towers(n):
    source = [i for i in reversed(range(n))]
    dest = []
    temp = []
    _solve_towers(n, source, dest, temp)


def _solve_towers(n, source, dest, temp):
    if n == 1:
        # only one disk, so can move from source to dest directly
        print 'Moving disk: ', source[-1]
        print 'Before move: '
        print 'Source: ', source
        print 'Temp: ', temp
        print 'Dest: ', dest
        # do the move
        dest.append(source.pop())
        print 'After move: '
        print 'Source: ', source
        print 'Temp: ', temp
        print 'Dest: ', dest
        print '----------------\n'
        return

    _solve_towers(n-1, source, temp, dest)
    _solve_towers(1, source, dest, temp)
    _solve_towers(n-1, temp, dest, source)



solve_towers(5)